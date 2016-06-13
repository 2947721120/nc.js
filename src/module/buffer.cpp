
/***************************************************************
 * Name:      buffer.cpp
 * Purpose:   Code for Node-CEF Buffer Module
 * Author:    Joshua GPBeta (studiocghibli@gmail.com)
 * Created:   2016-05-27
 * Copyright: Studio GPBeta (www.gpbeta.com)
 * License:
 **************************************************************/

/// ============================================================================
/// declarations
/// ============================================================================

#define BUFFER_ERROR Environment::ErrorException(NCJS_TEXT("Argument should be a Buffer"), except)
#define  INDEX_ERROR Environment::RangeException(NCJS_TEXT("Out of range index"), except)

/// ----------------------------------------------------------------------------
/// headers
/// ----------------------------------------------------------------------------

#include "ncjs/module/buffer.h"

#include "ncjs/module.h"
#include "ncjs/constants.h"

#include <include/cef_parser.h>

#include <signal.h>

namespace ncjs {

enum Encoding { ASCII, UTF8, BASE64, UCS2, BINARY, HEX, BUFFER };

/// ----------------------------------------------------------------------------
/// variables
/// ----------------------------------------------------------------------------

static const unsigned int MAX_LENGTH =
    sizeof(int32_t) == sizeof(intptr_t) ? 0x3fffffff : 0x7fffffff;

static const int STRING_MAX_LENGTH = (1 << 28) - 16;

/// ============================================================================
/// implementation
/// ============================================================================

Buffer* Buffer::SubBuffer(size_t offset, size_t size) const
{
    NCJS_ASSERT(offset + size < m_size);

    return new Buffer(m_buffer + offset, size, this);
}

inline Buffer* Buffer::Create(CefRefPtr<Environment> env, size_t size)
{
    Environment::BufferObjectInfo& info = env->GetBufferObjectInfo();

    void* buffer = info.NoZeroFill() ? malloc(size) : calloc(size, 1);
    info.ResetFillFlag();

    return new Buffer(static_cast<char*>(buffer), size);
}

inline Buffer* Buffer::Create(size_t size)
{
    return new Buffer(static_cast<char*>(malloc(size)), size);
}

class FormatSliceParam {
public:

    FormatSliceParam(const CefRefPtr<CefV8Value>& object,
                     const CefV8ValueList& args, CefString& except) :
        buf(NULL), pos(0), len(0)
    {
        if (!(buf = Buffer::Get(object))) {
            BUFFER_ERROR;
            return;
        }

        len = buf->Size();

        if (len == 0)
            return;

        int end = int(len);
        if (NCJS_ARG_IS(Int, args, 0)) { 
            pos = args[0]->GetIntValue();
            if (pos < 0) {
                pos += int(len);
                if (pos < 0)
                    pos = 0;
            } else if (size_t(pos) > len) {
                pos = int(len);
            }
        }
        if (NCJS_ARG_IS(Int, args, 1)) {
            end = args[1]->GetIntValue();
            if (end < 0)
                end = -end;
            if (size_t(end) > len)
                end = int(len);
        }

        len = end > pos ? end - pos : 0;
    }

    Buffer* buf;
    int     pos;
    size_t  len;
};

template <class T>
static void force_ascii_slow(const char* src, size_t len, T* dst) {
    for (size_t i = 0; i < len; ++i)
        dst[i] = src[i] & 0x7f;
}

#ifdef CEF_STRING_TYPE_UTF8
static void force_ascii(const char* src, size_t len, char* dst) {
    if (len < 16) {
        force_ascii_slow(src, len, dst);
        return;
    }

    const size_t bytes_per_word = sizeof(uintptr_t);
    const size_t align_mask = bytes_per_word - 1;
    const size_t src_unalign = To<uintptr_t>(src) & align_mask;
    const size_t dst_unalign = To<uintptr_t>(dst) & align_mask;

    if (src_unalign > 0) {
        if (src_unalign == dst_unalign) {
            const size_t unalign = bytes_per_word - src_unalign;
            force_ascii_slow(src, unalign, dst);
            src += unalign;
            dst += unalign;
            len -= src_unalign;
        } else {
            force_ascii_slow(src, len, dst);
            return;
        }
    }

#if defined(_WIN64) || defined(_LP64)
    const uintptr_t mask = ~0x8080808080808080ll;
#else
    const uintptr_t mask = ~0x80808080l;
#endif

    const uintptr_t* srcw = To<const uintptr_t*>(src);
          uintptr_t* dstw = To<uintptr_t*>(dst);

    for (size_t i = 0, n = len / bytes_per_word; i < n; ++i)
        dstw[i] = srcw[i] & mask;

    const size_t remainder = len & align_mask;
    if (remainder > 0) {
        const size_t offset = len - remainder;
        force_ascii_slow(src + offset, remainder, dst + offset);
    }
}
#else // UTF16 / UTF32
#define force_ascii force_ascii_slow
#endif // CEF_STRING_TYPE_UTF8

template <Encoding E>
static inline CefRefPtr<CefV8Value> DoSliceT(const FormatSliceParam& slice);

template <>
static inline CefRefPtr<CefV8Value> DoSliceT<ASCII>(const FormatSliceParam& slice)
{
    const char* buf = slice.buf->Data() + slice.pos;

    std::vector<cef_char_t> dst(slice.len);
    force_ascii(buf, slice.len, &dst[0]);

    return CefV8Value::CreateString(CefString(&dst[0], slice.len, false));
}

template <>
static inline CefRefPtr<CefV8Value> DoSliceT<BINARY>(const FormatSliceParam& slice)
{
    const char* buf = slice.buf->Data() + slice.pos;
    const size_t len = slice.len / sizeof(cef_char_t);

    const CefString str(To<const cef_char_t*>(buf), len, false);

    return CefV8Value::CreateString(str);
}

template <>
static inline CefRefPtr<CefV8Value> DoSliceT<BASE64>(const FormatSliceParam& slice)
{
    const char* buf = slice.buf->Data() + slice.pos;
    return CefV8Value::CreateString(CefBase64Encode(buf, slice.len));
}

template <>
static inline CefRefPtr<CefV8Value> DoSliceT<HEX>(const FormatSliceParam& slice)
{
    const char* BIT2HEX = "0123456789abcdef";
    const char* buf = slice.buf->Data() + slice.pos;
    const size_t len = slice.len * 2;

    std::vector<cef_char_t> dst(len);
    for (size_t i = 0, k = 0; i < slice.len; ++i) {
        const unsigned val = buf[i];
        dst[k] = BIT2HEX[val >> 4]; ++k;
        dst[k] = BIT2HEX[val & 15]; ++k;
    }

    return CefV8Value::CreateString(CefString(&dst[0], len, false));
}

template <>
static inline CefRefPtr<CefV8Value> DoSliceT<UCS2>(const FormatSliceParam& slice)
{    
    const char* buf = slice.buf->Data() + slice.pos;
    const size_t len = slice.len / 2;
    const bool aligned = To<size_t>(buf) % 2 == 0;

    if (Environment::IsLE() && aligned) { 
#ifdef CEF_STRING_TYPE_UTF16
        const CefString str(To<const cef_char_t*>(buf), len, false);
#else
        const base::string16 str(To<const base::char16*>(buf), len);
#endif // CEF_STRING_TYPE_UTF16
        return CefV8Value::CreateString(str);
    }

    // BE -> LE

    base::string16 dst;
    dst.reserve(len);

    for (unsigned i = 0; i < slice.len; i += 2)
      dst.push_back(buf[i] | (buf[i + 1] << 8));

    return CefV8Value::CreateString(dst);
}

template <>
static inline CefRefPtr<CefV8Value> DoSliceT<UTF8>(const FormatSliceParam& slice)
{
#ifdef CEF_STRING_TYPE_UTF8
    const CefString str(slice.buf->Data() + slice.pos, slice.len, false);
#else
    const std::string str(slice.buf->Data() + slice.pos, slice.len);
#endif // CEF_STRING_TYPE_UTF8
    return CefV8Value::CreateString(str);
}

template <Encoding E>
static inline void SliceT(CefRefPtr<CefV8Value> object, const CefV8ValueList& args,
                          CefRefPtr<CefV8Value>& retval, CefString& except)
{
    const FormatSliceParam slice(object, args, except);

    if (!slice.buf)
        return;

    if (slice.len)
        retval = DoSliceT<E>(slice);
}

template <class T, Environment::Endianness E>
static inline void ReadNumberT(const CefV8ValueList& args,
                               CefRefPtr<CefV8Value>& retval, CefString& except)
{
    NCJS_CHK_GE(args.size(), 2);

    Buffer* buf = Buffer::Get(args[0]);

    if (buf == NULL)
        return BUFFER_ERROR;

    const unsigned offset = args[1]->GetUIntValue();

    NCJS_CHK_LE(offset + sizeof(T), buf->Size());

    T value = *To<T*>(buf->Data() + offset);
    if (E != Environment::GetEndianness())
        ReverseArray(To<char*>(&value), sizeof(T));

    retval = CefV8Value::CreateDouble(value);
}

template <class T, Environment::Endianness E>
static inline void WriteNumberT(const CefV8ValueList& args,
                                CefRefPtr<CefV8Value>& retval, CefString& except)
{
    NCJS_CHK_GE(args.size(), 3);

    Buffer* buf = Buffer::Get(args[0]);

    if (buf == NULL)
        return BUFFER_ERROR;

    const unsigned offset = args[2]->GetUIntValue();

    NCJS_CHK_LE(offset + sizeof(T), buf->Size());

    char* value = buf->Data() + offset;
    *To<T*>(value) = T(args[1]->GetDoubleValue());
    if (E != Environment::GetEndianness())
        ReverseArray(value, sizeof(T));

    retval = CefV8Value::CreateUInt(sizeof(T));
}

/// ----------------------------------------------------------------------------
/// accessors
/// ----------------------------------------------------------------------------

class FlagsAccessor : public JsAccessorT<FlagsAccessor> {
    NCJS_ACCESSOR_GETTER(Get)(const CefRefPtr<CefV8Value> object,
                                    CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        CefRefPtr<Environment> env = Environment::Get(CefV8Context::GetCurrentContext());
        Environment::BufferObjectInfo& info = env->GetBufferObjectInfo();

        retval = env->GetArray().array_buffer_flags;

        unsigned nField = info.FieldsCount();
        unsigned* field = info.Fields();
        
        for (unsigned i = 0; i < nField; ++i) 
            retval->SetValue(i, CefV8Value::CreateInt(field[i]));
    }

    NCJS_ACCESSOR_SETTER(Set)(const CefRefPtr<CefV8Value> object,
                              const CefRefPtr<CefV8Value> value, CefString& except)
    {
        CefRefPtr<Environment> env = Environment::Get(CefV8Context::GetCurrentContext());
        Environment::BufferObjectInfo& info = env->GetBufferObjectInfo();

        unsigned nField = info.FieldsCount();
        unsigned* field = info.Fields();
        
        for (unsigned i = 0; i < nField; ++i)
            field[i] = value->GetValue(i)->GetIntValue();
    }
};

/// ----------------------------------------------------------------------------
/// objects
/// ----------------------------------------------------------------------------

class BufferPrototype : public JsObjecT<BufferPrototype> {

    // buffer.asciiSlice()
    NCJS_OBJECT_FUNCTION(AsciiSlice)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        SliceT<ASCII>(object, args, retval, except);
    }
    // buffer.base64Slice()
    NCJS_OBJECT_FUNCTION(Base64Slice)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        SliceT<BASE64>(object, args, retval, except);
    }
    // buffer.binarySlice()
    NCJS_OBJECT_FUNCTION(BinarySlice)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        SliceT<BINARY>(object, args, retval, except);
    }
    // buffer.hexSlice()
    NCJS_OBJECT_FUNCTION(HexSlice)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        SliceT<HEX>(object, args, retval, except);
    }
    // buffer.ucs2Slice()
    NCJS_OBJECT_FUNCTION(Ucs2Slice)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        SliceT<UCS2>(object, args, retval, except);
    }
    // buffer.utf8Slice()
    NCJS_OBJECT_FUNCTION(Utf8Slice)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        SliceT<UTF8>(object, args, retval, except);
    }
    // buffer.asciiWrite()
    NCJS_OBJECT_FUNCTION(AsciiWrite)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }
    // buffer.base64Write()
    NCJS_OBJECT_FUNCTION(Base64Write)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }
    // buffer.binaryWrite()
    NCJS_OBJECT_FUNCTION(BinaryWrite)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }
    // buffer.hexWrite()
    NCJS_OBJECT_FUNCTION(HexWrite)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }
    // buffer.ucs2Write()
    NCJS_OBJECT_FUNCTION(Ucs2Write)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }
    // buffer.utf8Write()
    NCJS_OBJECT_FUNCTION(Utf8Write)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }
    // buffer.copy()
    NCJS_OBJECT_FUNCTION(Copy)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        Buffer* src = NULL;
        Buffer* dst = NULL;

        if (!args.size() || !(src = Buffer::Get(object)) || !(dst = Buffer::Get(args[0])))
            return BUFFER_ERROR;

        size_t dstStart = 0;
        size_t srcStart = 0;
        size_t srcEnd = src->Size();

        if (NCJS_ARG_IS(UInt, args, 1)) {
            dstStart = args[1]->GetUIntValue();
            if (dstStart > dst->Size())
                return INDEX_ERROR;
        }
        if (NCJS_ARG_IS(UInt, args, 2)) {
            srcStart = args[2]->GetUIntValue();
            if (srcStart > src->Size())
                return INDEX_ERROR;
        }
        if (NCJS_ARG_IS(UInt, args, 3)) {
            srcEnd = args[3]->GetUIntValue();
            if (srcEnd > src->Size() || srcStart > srcEnd)
                return INDEX_ERROR;
        }

        const size_t toCopy = Min(Min(srcEnd - srcStart, dst->Size() - dstStart),
                                  src->Size() - srcStart);

        if (toCopy)
            memmove(dst->Data() + dstStart, src->Data() + srcStart, toCopy);

        retval = CefV8Value::CreateUInt(unsigned(toCopy));
    }

    // object builder

    NCJS_BEGIN_OBJECT_BUILDER()
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("asciiSlice"),  AsciiSlice)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("base64Slice"), Base64Slice)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("binarySlice"), BinarySlice)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("hexSlice"),    HexSlice)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("ucs2Slice"),   Ucs2Slice)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("utf8Slice"),   Utf8Slice)

        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("asciiWrite"),  AsciiWrite)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("base64Write"), Base64Write)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("binaryWrite"), BinaryWrite)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("hexWrite"),    HexWrite)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("ucs2Write"),   Ucs2Write)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("utf8Write"),   Utf8Write)

        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("copy"),        Copy)
    NCJS_END_OBJECT_BUILDER()
};

class BindingObject : public JsObjecT<BindingObject> {

    static inline void WrapBuffer(Buffer* buffer, CefRefPtr<CefV8Value>& retval)
    {
        retval = CefV8Value::CreateObject(NULL);
        retval->SetValue(consts::str_length,
                         CefV8Value::CreateUInt(unsigned(buffer->Size())),
                         V8_PROPERTY_ATTRIBUTE_READONLY);
        retval->SetUserData(buffer);
    }

    // createBuffer()
    NCJS_OBJECT_FUNCTION(CreateBuffer)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        CefRefPtr<Environment> env = Environment::Get(CefV8Context::GetCurrentContext());

        NCJS_CHECK(args.size() == 1);

        WrapBuffer(Buffer::Create(env, args[0]->GetUIntValue()), retval);
    }

    // subArray()
    NCJS_OBJECT_FUNCTION(SubArray)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        const FormatSliceParam slice(object, args, except);

        if (slice.buf == NULL)
            return;

        WrapBuffer(slice.buf->SubBuffer(slice.pos, slice.len), retval);
    }

    // setAt() no throw
    NCJS_OBJECT_FUNCTION(SetAt)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        if (args.size() < 1)
            return;

        unsigned value = 0;

        if (args.size() >= 2) {
            retval = args[1];
            value = retval->GetUIntValue();
        }

        if (Buffer* buf = Buffer::Get(object)) {
            const unsigned offset = args[0]->GetUIntValue();
            if (offset < buf->Size())
                buf->Data()[offset] = As<char>(value);
        }
    }

    // getAt() no throw
    NCJS_OBJECT_FUNCTION(GetAt)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        if (args.size() < 1)
            return;

        if (Buffer* buf = Buffer::Get(object)) {
            const unsigned offset = args[0]->GetUIntValue();
            if (offset < buf->Size())
                retval = CefV8Value::CreateUInt(As<unsigned char>(buf->Data()[offset]));
        }
    }

    // object builder

    NCJS_BEGIN_OBJECT_BUILDER()
        // functions
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("createBuffer"), CreateBuffer)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("subarray"), SubArray)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("setAt"), SetAt)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("getAt"), GetAt)
        // accessors
        NCJS_MAP_OBJECT_ACCESSOR(consts::str_flags, FlagsAccessor)
    NCJS_END_OBJECT_BUILDER()
};

/// ----------------------------------------------------------------------------
/// ModuleBuffer
/// ----------------------------------------------------------------------------

class ModuleBuffer : public JsObjecT<ModuleBuffer> {

    // buffer.createFromString()
    NCJS_OBJECT_FUNCTION(CreateFromString)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }

    // buffer.createFromArrayBuffer()
    NCJS_OBJECT_FUNCTION(CreateFromArrayBuffer)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }

    // buffer.byteLengthUtf8()
    NCJS_OBJECT_FUNCTION(ByteLengthUtf8)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        NCJS_CHECK(NCJS_ARG_IS(String, args, 0));

#ifdef CEF_STRING_TYPE_UTF8
        const size_t len = args[0]->GetStringValue().length();
#else
        const size_t len = args[0]->GetStringValue().ToString().length();
#endif // CEF_STRING_TYPE_UTF8

        retval = CefV8Value::CreateUInt(unsigned(len));
    }

    // buffer.compare()
    NCJS_OBJECT_FUNCTION(Compare)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        Buffer* aBuf = NULL;
        Buffer* bBuf = NULL;

        if (args.size() < 2 ||
            !(aBuf = Buffer::Get(args[0])) || !(bBuf = Buffer::Get(args[1])))
            return BUFFER_ERROR;

        const size_t len = Min(aBuf->Size(), bBuf->Size());
        int res = len > 0 ? memcmp(aBuf->Data(), bBuf->Data(), len) : 0;

        if (res == 0) {
            if (aBuf->Size() > bBuf->Size())
                res = 1;
            else if (aBuf->Size() < bBuf->Size())
                res = -1;
        } else {
            res = res > 0 ? 1 : -1;
        }

        retval = CefV8Value::CreateInt(res);
    }

    // buffer.fill()
    NCJS_OBJECT_FUNCTION(Fill)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        NCJS_CHECK(args.size() >= 4);

        Buffer* buf = Buffer::Get(args[0]);

        if (buf == NULL)
            return BUFFER_ERROR;

        const size_t start = args[2]->GetUIntValue();
        const size_t end = args[3]->GetUIntValue();
        const size_t len = end - start;

        NCJS_CHK_LE(len + start, buf->Size());

        if (args[1]->IsInt()) {
            const int value = args[1]->GetUIntValue() & 0xFF;
            memset(buf->Data() + start, value, len);
            return;
        } // else string

#ifdef CEF_STRING_TYPE_UTF8
        const CefString str = args[1]->GetStringValue();
#else
        const std::string str = args[1]->GetStringValue().ToString();
#endif // CEF_STRING_TYPE_UTF8

        if (str.length() == 0)
            return;

        memcpy(buf->Data() + start, str.c_str(), Min(str.length(), len));

        if (str.length() >= len)
            return;

        size_t filled = str.length();
        char* src = buf->Data() + start;
        char* dst = src + filled;
        while (filled < len - filled) {
            memcpy(dst, src, filled);
            dst += filled;
            filled *= 2;
        }

        if (filled < len) {
            memcpy(dst, src, len - filled);
            filled = len;
        }
    }

    // buffer.indexOfBuffer()
    NCJS_OBJECT_FUNCTION(IndexOfBuffer)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }

    // buffer.indexOfNumber()
    NCJS_OBJECT_FUNCTION(IndexOfNumber)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }

    // buffer.indexOfString()
    NCJS_OBJECT_FUNCTION(IndexOfString)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        except = consts::str_err_notimpl;
    }

    // buffer.readDoubleBE()
    NCJS_OBJECT_FUNCTION(ReadDoubleBE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        ReadNumberT<double, Environment::BIG_ENDIAN>(args, retval, except);
    }

    // buffer.readDoubleLE()
    NCJS_OBJECT_FUNCTION(ReadDoubleLE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        ReadNumberT<double, Environment::LITTLE_ENDIAN>(args, retval, except);
    }

    // buffer.readFloatBE()
    NCJS_OBJECT_FUNCTION(ReadFloatBE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        ReadNumberT<float, Environment::BIG_ENDIAN>(args, retval, except);
    }

    // buffer.readFloatLE()
    NCJS_OBJECT_FUNCTION(ReadFloatLE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        ReadNumberT<float, Environment::LITTLE_ENDIAN>(args, retval, except);
    }

    // buffer.writeDoubleBE()
    NCJS_OBJECT_FUNCTION(WriteDoubleBE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        WriteNumberT<double, Environment::BIG_ENDIAN>(args, retval, except);
    }

    // buffer.writeDoubleLE()
    NCJS_OBJECT_FUNCTION(WriteDoubleLE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        WriteNumberT<double, Environment::LITTLE_ENDIAN>(args, retval, except);
    }

    // buffer.writeFloatBE()
    NCJS_OBJECT_FUNCTION(WriteFloatBE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        WriteNumberT<float, Environment::BIG_ENDIAN>(args, retval, except);
    }

    // buffer.writeFloatLE()
    NCJS_OBJECT_FUNCTION(WriteFloatLE)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        WriteNumberT<float, Environment::LITTLE_ENDIAN>(args, retval, except);
    }

    // buffer.setupBufferJS()
    NCJS_OBJECT_FUNCTION(SetupBufferJS)(CefRefPtr<CefV8Value> object,
        const CefV8ValueList& args, CefRefPtr<CefV8Value>& retval, CefString& except)
    {
        CefRefPtr<CefV8Context> context = CefV8Context::GetCurrentContext();
        CefRefPtr<Environment> env = Environment::Get(context);

        NCJS_CHECK(NCJS_ARG_IS(Object, args, 0));

        env->GetObject().ptype_buffer = args[0];
        BufferPrototype::ObjectBuilder(env, context, args[0]);
        
        NCJS_CHECK(NCJS_ARG_IS(Object, args, 1));
        BindingObject::ObjectBuilder(env, context, args[1]);
    }

    // object factory

    NCJS_BEGIN_OBJECT_FACTORY()
        // constants
        NCJS_MAP_OBJECT_READONLY(Int, NCJS_REFTEXT("kMaxLength"),               MAX_LENGTH)
        NCJS_MAP_OBJECT_READONLY(Int, NCJS_REFTEXT("kStringMaxLength"),  STRING_MAX_LENGTH)

        // functions
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("setupBufferJS"), SetupBufferJS)

        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("createFromString"),      CreateFromString)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("createFromArrayBuffer"), CreateFromArrayBuffer)

        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("byteLengthUtf8"), ByteLengthUtf8)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("compare"),        Compare)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("fill"),           Fill)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("indexOfBuffer"),  IndexOfBuffer)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("indexOfNumber"),  IndexOfNumber)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("indexOfString"),  IndexOfString)

        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("readDoubleBE"), ReadDoubleBE)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("readDoubleLE"), ReadDoubleLE)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("readFloatBE"),  ReadFloatBE)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("readFloatLE"),  ReadFloatLE)

        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("writeDoubleBE"), WriteDoubleBE)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("writeDoubleLE"), WriteDoubleLE)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("writeFloatBE"),  WriteFloatBE)
        NCJS_MAP_OBJECT_FUNCTION(NCJS_REFTEXT("writeFloatLE"),  WriteFloatLE)
    NCJS_END_OBJECT_FACTORY()

};

/// ----------------------------------------------------------------------------
/// define module
/// ----------------------------------------------------------------------------

NCJS_DEFINE_BUILTIN_MODULE(buffer, ModuleBuffer);

} // ncjs
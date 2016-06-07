#ifndef ncjs_native_nc_h
#define ncjs_native_nc_h
#define _NCJS_EXTRACT_STR_LEN(_STR) _STR, ArraySize(_STR) - 1

#include "ncjs/string.h"

namespace ncjs {
namespace natives {

  const cef_char_t nc_native[] = { 39, 117, 115, 101, 32, 115, 116, 114, 105, 99, 116, 39, 59, 10, 10, 40, 102, 117, 110, 99, 116, 105, 111, 110, 40, 112, 114, 111, 99, 101, 115, 115, 41, 32, 123, 10, 10, 32, 32, 32, 32, 99, 111, 110, 115, 111, 108, 101, 46, 108, 111, 103, 40, 34, 73, 110, 105, 116, 105, 97, 108, 105, 122, 105, 110, 103, 32, 78, 111, 100, 101, 45, 67, 69, 70, 46, 46, 46, 34, 41, 59, 10, 10, 32, 32, 32, 32, 116, 104, 105, 115, 46, 103, 108, 111, 98, 97, 108, 32, 61, 32, 116, 104, 105, 115, 59, 10, 32, 10, 32, 32, 32, 32, 47, 47, 32, 99, 117, 115, 116, 111, 109, 32, 115, 116, 97, 114, 116, 117, 112, 10, 32, 32, 32, 32, 47, 47, 32, 78, 79, 84, 69, 58, 10, 32, 32, 32, 32, 47, 47, 32, 45, 32, 67, 77, 68, 32, 115, 119, 105, 116, 99, 104, 101, 115, 32, 97, 114, 101, 32, 110, 111, 116, 32, 115, 117, 112, 112, 111, 114, 116, 101, 100, 32, 121, 101, 116, 46, 10, 10, 32, 32, 32, 32, 102, 117, 110, 99, 116, 105, 111, 110, 32, 115, 116, 97, 114, 116, 117, 112, 40, 41, 32, 123, 10, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 69, 118, 101, 110, 116, 69, 109, 105, 116, 116, 101, 114, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 40, 39, 101, 118, 101, 110, 116, 115, 39, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 100, 111, 109, 97, 105, 110, 32, 61, 32, 110, 117, 108, 108, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 95, 101, 120, 105, 116, 105, 110, 103, 32, 61, 32, 102, 97, 108, 115, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 95, 95, 112, 114, 111, 116, 111, 95, 95, 32, 61, 32, 79, 98, 106, 101, 99, 116, 46, 99, 114, 101, 97, 116, 101, 40, 69, 118, 101, 110, 116, 69, 109, 105, 116, 116, 101, 114, 46, 112, 114, 111, 116, 111, 116, 121, 112, 101, 44, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 99, 111, 110, 115, 116, 114, 117, 99, 116, 111, 114, 58, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 108, 117, 101, 58, 32, 112, 114, 111, 99, 101, 115, 115, 46, 99, 111, 110, 115, 116, 114, 117, 99, 116, 111, 114, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 69, 118, 101, 110, 116, 69, 109, 105, 116, 116, 101, 114, 46, 99, 97, 108, 108, 40, 112, 114, 111, 99, 101, 115, 115, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 103, 108, 111, 98, 97, 108, 86, 97, 114, 105, 97, 98, 108, 101, 115, 40, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 115, 116, 97, 114, 116, 117, 112, 46, 103, 108, 111, 98, 97, 108, 84, 105, 109, 101, 111, 117, 116, 115, 40, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 115, 116, 97, 114, 116, 117, 112, 46, 112, 114, 111, 99, 101, 115, 115, 67, 111, 110, 102, 105, 103, 40, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 115, 116, 97, 114, 116, 117, 112, 46, 112, 114, 111, 99, 101, 115, 115, 78, 101, 120, 116, 84, 105, 99, 107, 40, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 112, 114, 111, 99, 101, 115, 115, 75, 105, 108, 108, 65, 110, 100, 69, 120, 105, 116, 40, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 115, 116, 97, 114, 116, 117, 112, 46, 112, 114, 111, 99, 101, 115, 115, 83, 105, 103, 110, 97, 108, 72, 97, 110, 100, 108, 101, 114, 115, 40, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 110, 99, 106, 115, 32, 61, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 32, 58, 32, 112, 114, 111, 99, 101, 115, 115, 44, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 66, 117, 102, 102, 101, 114, 32, 58, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 40, 39, 98, 117, 102, 102, 101, 114, 39, 41, 46, 66, 117, 102, 102, 101, 114, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 114, 117, 110, 77, 97, 105, 110, 40, 110, 99, 106, 115, 41, 59, 32, 47, 47, 32, 111, 114, 32, 100, 111, 32, 121, 111, 117, 114, 32, 111, 119, 110, 32, 109, 97, 105, 110, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 110, 99, 106, 115, 59, 10, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 47, 47, 32, 102, 117, 110, 99, 116, 105, 111, 110, 115, 32, 115, 116, 97, 114, 116, 32, 104, 101, 114, 101, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 103, 108, 111, 98, 97, 108, 86, 97, 114, 105, 97, 98, 108, 101, 115, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 103, 108, 111, 98, 97, 108, 46, 71, 76, 79, 66, 65, 76, 32, 61, 32, 103, 108, 111, 98, 97, 108, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 103, 108, 111, 98, 97, 108, 46, 114, 111, 111, 116, 32, 61, 32, 103, 108, 111, 98, 97, 108, 59, 10, 32, 32, 32, 32, 125, 59, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 95, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 32, 61, 32, 110, 117, 108, 108, 59, 10, 10, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 33, 115, 116, 97, 114, 116, 117, 112, 46, 95, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 95, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 32, 61, 32, 112, 114, 111, 99, 101, 115, 115, 46, 98, 105, 110, 100, 105, 110, 103, 40, 39, 99, 111, 110, 115, 116, 97, 110, 116, 115, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 115, 116, 97, 114, 116, 117, 112, 46, 95, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 112, 114, 111, 99, 101, 115, 115, 75, 105, 108, 108, 65, 110, 100, 69, 120, 105, 116, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 101, 120, 105, 116, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 99, 111, 100, 101, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 99, 111, 100, 101, 32, 124, 124, 32, 99, 111, 100, 101, 32, 61, 61, 61, 32, 48, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 101, 120, 105, 116, 67, 111, 100, 101, 32, 61, 32, 99, 111, 100, 101, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 33, 112, 114, 111, 99, 101, 115, 115, 46, 95, 101, 120, 105, 116, 105, 110, 103, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 95, 101, 120, 105, 116, 105, 110, 103, 32, 61, 32, 116, 114, 117, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 101, 109, 105, 116, 40, 39, 101, 120, 105, 116, 39, 44, 32, 112, 114, 111, 99, 101, 115, 115, 46, 101, 120, 105, 116, 67, 111, 100, 101, 32, 124, 124, 32, 48, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 114, 101, 97, 108, 108, 121, 69, 120, 105, 116, 40, 112, 114, 111, 99, 101, 115, 115, 46, 101, 120, 105, 116, 67, 111, 100, 101, 32, 124, 124, 32, 48, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 107, 105, 108, 108, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 112, 105, 100, 44, 32, 115, 105, 103, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 101, 114, 114, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 112, 105, 100, 32, 33, 61, 32, 40, 112, 105, 100, 32, 124, 32, 48, 41, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 110, 101, 119, 32, 84, 121, 112, 101, 69, 114, 114, 111, 114, 40, 39, 105, 110, 118, 97, 108, 105, 100, 32, 112, 105, 100, 39, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 112, 114, 101, 115, 101, 114, 118, 101, 32, 110, 117, 108, 108, 32, 115, 105, 103, 110, 97, 108, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 48, 32, 61, 61, 61, 32, 115, 105, 103, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 101, 114, 114, 32, 61, 32, 112, 114, 111, 99, 101, 115, 115, 46, 95, 107, 105, 108, 108, 40, 112, 105, 100, 44, 32, 48, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 115, 105, 103, 32, 61, 32, 115, 105, 103, 32, 124, 124, 32, 39, 83, 73, 71, 84, 69, 82, 77, 39, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 115, 116, 97, 114, 116, 117, 112, 46, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 40, 41, 91, 115, 105, 103, 93, 32, 38, 38, 32, 115, 105, 103, 46, 115, 108, 105, 99, 101, 40, 48, 44, 32, 51, 41, 32, 61, 61, 61, 32, 39, 83, 73, 71, 39, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 101, 114, 114, 32, 61, 32, 112, 114, 111, 99, 101, 115, 115, 46, 95, 107, 105, 108, 108, 40, 112, 105, 100, 44, 32, 115, 116, 97, 114, 116, 117, 112, 46, 108, 97, 122, 121, 67, 111, 110, 115, 116, 97, 110, 116, 115, 40, 41, 91, 115, 105, 103, 93, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 110, 101, 119, 32, 69, 114, 114, 111, 114, 40, 39, 85, 110, 107, 110, 111, 119, 110, 32, 115, 105, 103, 110, 97, 108, 58, 32, 39, 32, 43, 32, 115, 105, 103, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 101, 114, 114, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 101, 114, 114, 110, 111, 69, 120, 99, 101, 112, 116, 105, 111, 110, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 40, 39, 117, 116, 105, 108, 39, 41, 46, 95, 101, 114, 114, 110, 111, 69, 120, 99, 101, 112, 116, 105, 111, 110, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 101, 114, 114, 110, 111, 69, 120, 99, 101, 112, 116, 105, 111, 110, 40, 101, 114, 114, 44, 32, 39, 107, 105, 108, 108, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 116, 114, 117, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 115, 116, 97, 114, 116, 117, 112, 46, 114, 117, 110, 77, 97, 105, 110, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 110, 99, 106, 115, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 77, 111, 100, 117, 108, 101, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 40, 39, 109, 111, 100, 117, 108, 101, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 112, 97, 116, 104, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 40, 39, 112, 97, 116, 104, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 109, 111, 100, 117, 108, 101, 32, 61, 32, 110, 101, 119, 32, 77, 111, 100, 117, 108, 101, 40, 39, 46, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 102, 105, 108, 101, 110, 97, 109, 101, 32, 61, 32, 112, 97, 116, 104, 46, 114, 101, 115, 111, 108, 118, 101, 40, 112, 114, 111, 99, 101, 115, 115, 46, 97, 114, 103, 118, 91, 49, 93, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 109, 111, 100, 117, 108, 101, 46, 108, 111, 97, 100, 40, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 97, 114, 103, 118, 91, 49, 93, 32, 61, 32, 102, 105, 108, 101, 110, 97, 109, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 109, 111, 100, 117, 108, 101, 46, 102, 105, 108, 101, 110, 97, 109, 101, 32, 61, 32, 102, 105, 108, 101, 110, 97, 109, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 109, 111, 100, 117, 108, 101, 46, 101, 120, 112, 111, 114, 116, 115, 32, 61, 32, 110, 99, 106, 115, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 109, 111, 100, 117, 108, 101, 46, 112, 97, 116, 104, 115, 32, 61, 32, 77, 111, 100, 117, 108, 101, 46, 95, 110, 111, 100, 101, 77, 111, 100, 117, 108, 101, 80, 97, 116, 104, 115, 40, 112, 97, 116, 104, 46, 100, 105, 114, 110, 97, 109, 101, 40, 102, 105, 108, 101, 110, 97, 109, 101, 41, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 115, 99, 114, 105, 112, 116, 32, 61, 32, 39, 95, 110, 99, 106, 115, 46, 95, 95, 102, 105, 108, 101, 110, 97, 109, 101, 32, 61, 32, 95, 95, 102, 105, 108, 101, 110, 97, 109, 101, 59, 92, 110, 39, 32, 43, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 39, 95, 110, 99, 106, 115, 46, 101, 120, 112, 111, 114, 116, 115, 32, 61, 32, 101, 120, 112, 111, 114, 116, 115, 59, 92, 110, 39, 32, 43, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 39, 95, 110, 99, 106, 115, 46, 109, 111, 100, 117, 108, 101, 32, 61, 32, 109, 111, 100, 117, 108, 101, 59, 92, 110, 39, 32, 43, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 39, 95, 110, 99, 106, 115, 46, 95, 95, 100, 105, 114, 110, 97, 109, 101, 32, 61, 32, 95, 95, 100, 105, 114, 110, 97, 109, 101, 59, 92, 110, 39, 32, 43, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 39, 95, 110, 99, 106, 115, 46, 114, 101, 113, 117, 105, 114, 101, 32, 61, 32, 114, 101, 113, 117, 105, 114, 101, 59, 92, 110, 39, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 103, 108, 111, 98, 97, 108, 46, 95, 110, 99, 106, 115, 32, 61, 32, 110, 99, 106, 115, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 109, 111, 100, 117, 108, 101, 46, 95, 99, 111, 109, 112, 105, 108, 101, 40, 115, 99, 114, 105, 112, 116, 44, 32, 102, 105, 108, 101, 110, 97, 109, 101, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 109, 111, 100, 117, 108, 101, 46, 108, 111, 97, 100, 101, 100, 32, 61, 32, 116, 114, 117, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 100, 101, 108, 101, 116, 101, 32, 103, 108, 111, 98, 97, 108, 46, 95, 110, 99, 106, 115, 59, 10, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 47, 47, 32, 98, 117, 105, 108, 100, 32, 109, 105, 110, 105, 109, 97, 108, 32, 109, 111, 100, 117, 108, 101, 32, 115, 121, 115, 116, 101, 109, 10, 10, 32, 32, 32, 32, 47, 47, 32, 78, 101, 105, 116, 104, 101, 114, 32, 67, 69, 70, 32, 110, 111, 114, 32, 74, 97, 118, 97, 83, 99, 114, 105, 112, 116, 32, 104, 97, 118, 101, 32, 115, 99, 114, 105, 112, 116, 32, 99, 111, 109, 112, 105, 108, 105, 110, 103, 32, 65, 80, 73, 44, 10, 32, 32, 32, 32, 47, 47, 32, 115, 111, 32, 119, 101, 32, 106, 117, 115, 116, 32, 109, 97, 107, 101, 32, 97, 32, 39, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 39, 32, 109, 111, 100, 117, 108, 101, 32, 114, 101, 112, 108, 97, 99, 101, 109, 101, 110, 116, 32, 104, 101, 114, 101, 46, 10, 32, 32, 32, 32, 102, 117, 110, 99, 116, 105, 111, 110, 32, 98, 105, 110, 100, 67, 111, 110, 116, 101, 120, 116, 105, 102, 121, 77, 111, 100, 117, 108, 101, 40, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 102, 117, 110, 99, 116, 105, 111, 110, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 83, 99, 114, 105, 112, 116, 40, 99, 111, 100, 101, 44, 32, 111, 112, 116, 105, 111, 110, 115, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 116, 104, 105, 115, 46, 99, 111, 110, 115, 116, 114, 117, 99, 116, 111, 114, 32, 33, 61, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 83, 99, 114, 105, 112, 116, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 69, 114, 114, 111, 114, 40, 39, 77, 117, 115, 116, 32, 99, 97, 108, 108, 32, 118, 109, 46, 83, 99, 114, 105, 112, 116, 32, 97, 115, 32, 97, 32, 99, 111, 110, 115, 116, 114, 117, 99, 116, 111, 114, 46, 39, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 102, 105, 108, 101, 110, 97, 109, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 111, 112, 116, 105, 111, 110, 115, 32, 33, 61, 61, 32, 117, 110, 100, 101, 102, 105, 110, 101, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 116, 121, 112, 101, 111, 102, 32, 111, 112, 116, 105, 111, 110, 115, 32, 61, 61, 61, 32, 39, 111, 98, 106, 101, 99, 116, 39, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 111, 102, 102, 115, 101, 116, 115, 32, 97, 114, 101, 32, 110, 111, 116, 32, 115, 117, 112, 112, 111, 114, 116, 101, 100, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 111, 112, 116, 105, 111, 110, 115, 46, 108, 105, 110, 101, 79, 102, 102, 115, 101, 116, 32, 33, 61, 61, 32, 117, 110, 100, 101, 102, 105, 110, 101, 100, 32, 38, 38, 32, 111, 112, 116, 105, 111, 110, 115, 46, 108, 105, 110, 101, 79, 102, 102, 115, 101, 116, 32, 33, 61, 32, 48, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 69, 114, 114, 111, 114, 40, 39, 34, 108, 105, 110, 101, 79, 102, 102, 115, 101, 116, 34, 32, 109, 117, 115, 116, 32, 98, 101, 32, 48, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 111, 112, 116, 105, 111, 110, 115, 46, 99, 111, 108, 117, 109, 110, 79, 102, 102, 115, 101, 116, 32, 33, 61, 61, 32, 117, 110, 100, 101, 102, 105, 110, 101, 100, 32, 38, 38, 32, 111, 112, 116, 105, 111, 110, 115, 46, 99, 111, 108, 117, 109, 110, 79, 102, 102, 115, 101, 116, 32, 33, 61, 32, 48, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 69, 114, 114, 111, 114, 40, 39, 34, 99, 111, 108, 117, 109, 110, 79, 102, 102, 115, 101, 116, 34, 32, 109, 117, 115, 116, 32, 98, 101, 32, 48, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 39, 100, 105, 115, 112, 108, 97, 121, 69, 114, 114, 111, 114, 115, 39, 32, 105, 115, 32, 105, 103, 110, 111, 114, 101, 100, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 102, 105, 108, 101, 110, 97, 109, 101, 32, 61, 32, 111, 112, 116, 105, 111, 110, 115, 46, 102, 105, 108, 101, 110, 97, 109, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 105, 102, 32, 40, 116, 121, 112, 101, 111, 102, 32, 111, 112, 116, 105, 111, 110, 115, 32, 61, 61, 61, 32, 39, 115, 116, 114, 105, 110, 103, 39, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 102, 105, 108, 101, 110, 97, 109, 101, 32, 61, 32, 111, 112, 116, 105, 111, 110, 115, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 84, 121, 112, 101, 69, 114, 114, 111, 114, 40, 39, 111, 112, 116, 105, 111, 110, 115, 32, 109, 117, 115, 116, 32, 98, 101, 32, 97, 110, 32, 111, 98, 106, 101, 99, 116, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 115, 99, 114, 105, 112, 116, 32, 61, 32, 99, 111, 100, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 102, 105, 108, 101, 110, 97, 109, 101, 32, 33, 61, 61, 32, 117, 110, 100, 101, 102, 105, 110, 101, 100, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 115, 99, 114, 105, 112, 116, 32, 43, 61, 32, 39, 92, 110, 47, 47, 64, 32, 115, 111, 117, 114, 99, 101, 85, 82, 76, 61, 39, 32, 43, 32, 102, 105, 108, 101, 110, 97, 109, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 101, 108, 115, 101, 32, 99, 104, 114, 111, 109, 105, 117, 109, 32, 119, 105, 108, 108, 32, 117, 115, 101, 32, 118, 109, 88, 88, 32, 97, 115, 32, 102, 105, 108, 101, 110, 97, 109, 101, 46, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 83, 99, 114, 105, 112, 116, 46, 112, 114, 111, 116, 111, 116, 121, 112, 101, 46, 114, 117, 110, 73, 110, 84, 104, 105, 115, 67, 111, 110, 116, 101, 120, 116, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 111, 112, 116, 105, 111, 110, 115, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 100, 105, 115, 112, 108, 97, 121, 69, 114, 114, 111, 114, 115, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 114, 101, 115, 117, 108, 116, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 111, 112, 116, 105, 111, 110, 115, 32, 33, 61, 61, 32, 117, 110, 100, 101, 102, 105, 110, 101, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 116, 121, 112, 101, 111, 102, 32, 111, 112, 116, 105, 111, 110, 115, 32, 61, 61, 61, 32, 39, 111, 98, 106, 101, 99, 116, 39, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 100, 105, 115, 112, 108, 97, 121, 69, 114, 114, 111, 114, 115, 32, 61, 32, 111, 112, 116, 105, 111, 110, 115, 46, 100, 105, 115, 112, 108, 97, 121, 69, 114, 114, 111, 114, 115, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 39, 116, 105, 109, 101, 111, 117, 116, 39, 32, 105, 115, 32, 105, 103, 110, 111, 114, 101, 100, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 84, 121, 112, 101, 69, 114, 114, 111, 114, 40, 39, 111, 112, 116, 105, 111, 110, 115, 32, 109, 117, 115, 116, 32, 98, 101, 32, 97, 110, 32, 111, 98, 106, 101, 99, 116, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 100, 105, 115, 112, 108, 97, 121, 69, 114, 114, 111, 114, 115, 32, 33, 61, 61, 32, 102, 97, 108, 115, 101, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 115, 117, 108, 116, 32, 61, 32, 101, 118, 97, 108, 40, 116, 104, 105, 115, 46, 115, 99, 114, 105, 112, 116, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 114, 121, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 115, 117, 108, 116, 32, 61, 32, 101, 118, 97, 108, 40, 116, 104, 105, 115, 46, 115, 99, 114, 105, 112, 116, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 32, 99, 97, 116, 99, 104, 32, 40, 101, 41, 32, 123, 125, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 114, 101, 115, 117, 108, 116, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 32, 61, 32, 123, 32, 67, 111, 110, 116, 101, 120, 116, 105, 102, 121, 83, 99, 114, 105, 112, 116, 32, 58, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 83, 99, 114, 105, 112, 116, 32, 125, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 47, 32, 97, 100, 100, 32, 116, 111, 32, 98, 105, 110, 100, 105, 110, 103, 32, 99, 97, 99, 104, 101, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 98, 105, 110, 100, 105, 110, 103, 46, 95, 99, 97, 99, 104, 101, 46, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 32, 61, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 99, 111, 110, 116, 101, 120, 116, 105, 102, 121, 59, 10, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 118, 97, 114, 32, 67, 111, 110, 116, 101, 120, 116, 105, 102, 121, 77, 111, 100, 117, 108, 101, 32, 61, 32, 98, 105, 110, 100, 67, 111, 110, 116, 101, 120, 116, 105, 102, 121, 77, 111, 100, 117, 108, 101, 40, 41, 59, 10, 10, 32, 32, 32, 32, 102, 117, 110, 99, 116, 105, 111, 110, 32, 114, 117, 110, 73, 110, 84, 104, 105, 115, 67, 111, 110, 116, 101, 120, 116, 40, 99, 111, 100, 101, 44, 32, 111, 112, 116, 105, 111, 110, 115, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 115, 99, 114, 105, 112, 116, 32, 61, 32, 110, 101, 119, 32, 67, 111, 110, 116, 101, 120, 116, 105, 102, 121, 77, 111, 100, 117, 108, 101, 46, 67, 111, 110, 116, 101, 120, 116, 105, 102, 121, 83, 99, 114, 105, 112, 116, 40, 99, 111, 100, 101, 44, 32, 111, 112, 116, 105, 111, 110, 115, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 115, 99, 114, 105, 112, 116, 46, 114, 117, 110, 73, 110, 84, 104, 105, 115, 67, 111, 110, 116, 101, 120, 116, 40, 41, 59, 10, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 102, 117, 110, 99, 116, 105, 111, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 102, 105, 108, 101, 110, 97, 109, 101, 32, 61, 32, 105, 100, 32, 43, 32, 39, 46, 106, 115, 39, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 105, 100, 32, 61, 32, 105, 100, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 101, 120, 112, 111, 114, 116, 115, 32, 61, 32, 123, 125, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 108, 111, 97, 100, 101, 100, 32, 61, 32, 102, 97, 108, 115, 101, 59, 10, 32, 32, 32, 32, 125, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 95, 115, 111, 117, 114, 99, 101, 32, 61, 32, 112, 114, 111, 99, 101, 115, 115, 46, 98, 105, 110, 100, 105, 110, 103, 40, 39, 110, 97, 116, 105, 118, 101, 115, 39, 41, 59, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 95, 99, 97, 99, 104, 101, 32, 61, 32, 123, 125, 59, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 105, 100, 32, 61, 61, 32, 39, 110, 97, 116, 105, 118, 101, 95, 109, 111, 100, 117, 108, 101, 39, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 99, 97, 99, 104, 101, 100, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 103, 101, 116, 67, 97, 99, 104, 101, 100, 40, 105, 100, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 99, 97, 99, 104, 101, 100, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 99, 97, 99, 104, 101, 100, 46, 101, 120, 112, 111, 114, 116, 115, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 105, 102, 32, 40, 33, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 101, 120, 105, 115, 116, 115, 40, 105, 100, 41, 41, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 114, 111, 119, 32, 110, 101, 119, 32, 69, 114, 114, 111, 114, 40, 39, 78, 111, 32, 115, 117, 99, 104, 32, 110, 97, 116, 105, 118, 101, 32, 109, 111, 100, 117, 108, 101, 32, 39, 32, 43, 32, 105, 100, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 114, 111, 99, 101, 115, 115, 46, 109, 111, 100, 117, 108, 101, 76, 111, 97, 100, 76, 105, 115, 116, 46, 112, 117, 115, 104, 40, 39, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 32, 39, 32, 43, 32, 105, 100, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 110, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 32, 61, 32, 110, 101, 119, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 40, 105, 100, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 110, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 99, 97, 99, 104, 101, 40, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 110, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 99, 111, 109, 112, 105, 108, 101, 40, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 110, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 101, 120, 112, 111, 114, 116, 115, 59, 10, 32, 32, 32, 32, 125, 59, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 103, 101, 116, 67, 97, 99, 104, 101, 100, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 95, 99, 97, 99, 104, 101, 91, 105, 100, 93, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 101, 120, 105, 115, 116, 115, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 95, 115, 111, 117, 114, 99, 101, 46, 104, 97, 115, 79, 119, 110, 80, 114, 111, 112, 101, 114, 116, 121, 40, 105, 100, 41, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 99, 111, 110, 115, 116, 32, 69, 88, 80, 79, 83, 69, 95, 73, 78, 84, 69, 82, 78, 65, 76, 83, 32, 61, 32, 112, 114, 111, 99, 101, 115, 115, 46, 101, 120, 101, 99, 65, 114, 103, 118, 46, 115, 111, 109, 101, 40, 102, 117, 110, 99, 116, 105, 111, 110, 40, 97, 114, 103, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 97, 114, 103, 46, 109, 97, 116, 99, 104, 40, 47, 94, 45, 45, 101, 120, 112, 111, 115, 101, 91, 45, 95, 93, 105, 110, 116, 101, 114, 110, 97, 108, 115, 36, 47, 41, 59, 10, 32, 32, 32, 32, 125, 41, 59, 32, 32, 32, 32, 32, 32, 32, 32, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 105, 102, 32, 40, 69, 88, 80, 79, 83, 69, 95, 73, 78, 84, 69, 82, 78, 65, 76, 83, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 110, 111, 110, 73, 110, 116, 101, 114, 110, 97, 108, 69, 120, 105, 115, 116, 115, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 101, 120, 105, 115, 116, 115, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 105, 115, 73, 110, 116, 101, 114, 110, 97, 108, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 102, 97, 108, 115, 101, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 59, 10, 32, 32, 32, 32, 125, 32, 101, 108, 115, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 110, 111, 110, 73, 110, 116, 101, 114, 110, 97, 108, 69, 120, 105, 115, 116, 115, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 101, 120, 105, 115, 116, 115, 40, 105, 100, 41, 32, 38, 38, 32, 33, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 105, 115, 73, 110, 116, 101, 114, 110, 97, 108, 40, 105, 100, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 105, 115, 73, 110, 116, 101, 114, 110, 97, 108, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 105, 100, 46, 115, 116, 97, 114, 116, 115, 87, 105, 116, 104, 40, 39, 105, 110, 116, 101, 114, 110, 97, 108, 47, 39, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 59, 10, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 103, 101, 116, 83, 111, 117, 114, 99, 101, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 105, 100, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 95, 115, 111, 117, 114, 99, 101, 91, 105, 100, 93, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 119, 114, 97, 112, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 115, 99, 114, 105, 112, 116, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 119, 114, 97, 112, 112, 101, 114, 91, 48, 93, 32, 43, 32, 115, 99, 114, 105, 112, 116, 32, 43, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 119, 114, 97, 112, 112, 101, 114, 91, 49, 93, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 119, 114, 97, 112, 112, 101, 114, 32, 61, 32, 91, 10, 32, 32, 32, 32, 32, 32, 32, 32, 39, 40, 102, 117, 110, 99, 116, 105, 111, 110, 32, 40, 101, 120, 112, 111, 114, 116, 115, 44, 32, 114, 101, 113, 117, 105, 114, 101, 44, 32, 109, 111, 100, 117, 108, 101, 44, 32, 95, 95, 102, 105, 108, 101, 110, 97, 109, 101, 44, 32, 95, 95, 100, 105, 114, 110, 97, 109, 101, 41, 32, 123, 32, 39, 44, 10, 32, 32, 32, 32, 32, 32, 32, 32, 39, 92, 110, 125, 41, 59, 39, 10, 32, 32, 32, 32, 93, 59, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 112, 114, 111, 116, 111, 116, 121, 112, 101, 46, 99, 111, 109, 112, 105, 108, 101, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 115, 111, 117, 114, 99, 101, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 103, 101, 116, 83, 111, 117, 114, 99, 101, 40, 116, 104, 105, 115, 46, 105, 100, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 115, 111, 117, 114, 99, 101, 32, 61, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 119, 114, 97, 112, 40, 115, 111, 117, 114, 99, 101, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 118, 97, 114, 32, 102, 110, 32, 61, 32, 114, 117, 110, 73, 110, 84, 104, 105, 115, 67, 111, 110, 116, 101, 120, 116, 40, 115, 111, 117, 114, 99, 101, 44, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 102, 105, 108, 101, 110, 97, 109, 101, 58, 32, 116, 104, 105, 115, 46, 102, 105, 108, 101, 110, 97, 109, 101, 44, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 108, 105, 110, 101, 79, 102, 102, 115, 101, 116, 58, 32, 48, 10, 32, 32, 32, 32, 32, 32, 32, 32, 125, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 102, 110, 40, 116, 104, 105, 115, 46, 101, 120, 112, 111, 114, 116, 115, 44, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 114, 101, 113, 117, 105, 114, 101, 44, 32, 116, 104, 105, 115, 44, 32, 116, 104, 105, 115, 46, 102, 105, 108, 101, 110, 97, 109, 101, 41, 59, 10, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116, 104, 105, 115, 46, 108, 111, 97, 100, 101, 100, 32, 61, 32, 116, 114, 117, 101, 59, 10, 32, 32, 32, 32, 125, 59, 10, 10, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 112, 114, 111, 116, 111, 116, 121, 112, 101, 46, 99, 97, 99, 104, 101, 32, 61, 32, 102, 117, 110, 99, 116, 105, 111, 110, 40, 41, 32, 123, 10, 32, 32, 32, 32, 32, 32, 32, 32, 78, 97, 116, 105, 118, 101, 77, 111, 100, 117, 108, 101, 46, 95, 99, 97, 99, 104, 101, 91, 116, 104, 105, 115, 46, 105, 100, 93, 32, 61, 32, 116, 104, 105, 115, 59, 10, 32, 32, 32, 32, 125, 59, 10, 32, 32, 32, 32, 10, 32, 32, 32, 32, 114, 101, 116, 117, 114, 110, 32, 115, 116, 97, 114, 116, 117, 112, 40, 41, 59, 10, 10, 125, 41, 59, 10, 10, 47, 47, 64, 32, 115, 111, 117, 114, 99, 101, 85, 82, 76, 61, 110, 99, 46, 106, 115, 0 };

static const CefString s_nc(_NCJS_EXTRACT_STR_LEN(nc_native), false);

}
}

#endif
/*
 * This is free and unencumbered software released into the public domain.
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 */


#ifndef ftr_io_operations_h
#define ftr_io_operations_h

#include<ftr_broke_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// UNSIGNED
/***********************************************/
// break into little endian 
FTR_API void ftr_break_u16l(ftr_u16 val, struct ftr_brokeu16 * target);

FTR_API void ftr_break_u32l(ftr_u32 val, struct ftr_brokeu32 * target);

FTR_API void ftr_break_u64l(ftr_u64 val, struct ftr_brokeu64 * target);

// assemble from little endian

FTR_API ftr_u16 ftr_assemble_u16l(const struct ftr_brokeu16 * val);

FTR_API ftr_u32 ftr_assemble_u32l(const struct ftr_brokeu32 * val);

FTR_API ftr_u64 ftr_assemble_u64l(const struct ftr_brokeu64 * val);

// break into big endian

FTR_API void ftr_break_u16b(ftr_u16 val, struct ftr_brokeu16 * target);

FTR_API void ftr_break_u32b(ftr_u32 val, struct ftr_brokeu32 * target);

FTR_API void ftr_break_u64b(ftr_u64 val, struct ftr_brokeu64 * target);

// assemble into big endian

FTR_API ftr_u16 ftr_assemble_u16b(const struct ftr_brokeu16 * val);

FTR_API ftr_u32 ftr_assemble_u32b(const struct ftr_brokeu32 * val);

FTR_API ftr_u64 ftr_assemble_u64b(const struct ftr_brokeu64 * val);
/**********************************************/

// SIGNED
/*********************************************/
// break into little endian

FTR_API void ftr_break_s16l(ftr_s16 val, struct ftr_brokes16 * target);

FTR_API void ftr_break_s32l(ftr_s32 val, struct ftr_brokes32 * target);

FTR_API void ftr_break_s64l(ftr_s64 val, struct ftr_brokes64 * target);

// assemble into little endian

FTR_API ftr_s16 ftr_assemble_s16l(const struct ftr_brokes16 * val);

FTR_API ftr_s32 ftr_assemble_s32l(const struct ftr_brokes32 * val);

FTR_API ftr_s64 ftr_assemble_s64l(const struct ftr_brokes64 * val);

// break into big endian

FTR_API void ftr_break_s16b(ftr_s16 val, struct ftr_brokes16 * target);

FTR_API void ftr_break_s32b(ftr_s32 val, struct ftr_brokes32 * target);

FTR_API void ftr_break_s64b(ftr_s64 val, struct ftr_brokes64 * target);

// assemble into big endian

FTR_API ftr_s16 ftr_assemble_s16b(const struct ftr_brokes16 * val);

FTR_API ftr_s32 ftr_assemble_s32b(const struct ftr_brokes32 * val);

FTR_API ftr_s64 ftr_assemble_s64b(const struct ftr_brokes64 * val);

// FLOATING POINT
/***************************************/

// Pack float into u32 integer, not incredibly good at preserving precision
FTR_API ftr_u32 ftr_pack_float_u32(float val);

FTR_API float ftr_unpack_float_u32(ftr_u32 val);

/* 
 * Pack floating point value into unsigned integer, good at preserving 
 * precision for floats and doubles
 */
FTR_API ftr_u64 ftr_pack_IEEE754(long double val, unsigned bits, unsigned expbits);

FTR_API long double ftr_unpack_IEEE754(ftr_u64 val, unsigned bits, unsigned expbits);

#define ftr_pack_double_u32(val) (ftr_pack_IEEE754((val), 32, 8))
#define ftr_pack_double_u64(val) (ftr_pack_IEEE754((val), 64, 11))

#define ftr_unpack_double_u32(val) (ftr_unpack_IEEE754((val), 32, 8))
#define ftr_unpack_double_u64(val) (ftr_unpack_IEEE754((val), 64, 11)) 

#ifdef __cplusplus
}
#endif

#endif


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


#ifndef ftr_broke_types_h
#define ftr_broke_types_h

#include<ftr_config.h>
#include<ftr_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// UNSIGNED

struct FTR_API ftr_brokeu16 {
    ftr_u8 bytes[2];
};

void FTR_API ftr_copy_brokeu16(const struct ftr_brokeu16 * source,
        struct ftr_brokeu16 * target);

struct ftr_brokeu32 {
    ftr_u8 bytes[4];
};

void FTR_API ftr_copy_brokeu32(const struct ftr_brokeu32 * source, 
        struct ftr_brokeu32 * target);

struct FTR_API ftr_brokeu64 {
    ftr_u8 bytes[8];
};

void FTR_API ftr_copy_brokeu64(const struct ftr_brokeu64 * source, 
        struct ftr_brokeu64 * target);

// SIGNED

struct FTR_API ftr_brokes16 {
    ftr_u8 bytes[2];
};

void FTR_API ftr_copy_brokes16(const struct ftr_brokes16 * source, 
        struct ftr_brokes16 * target);

struct FTR_API ftr_brokes32 {
    ftr_u8 bytes[4];
};

void FTR_API ftr_copy_brokes32(const struct ftr_brokes32 * source, 
        struct ftr_brokes32 * target);

struct FTR_API ftr_brokes64 {
    ftr_u8 bytes[8];
};

void FTR_API ftr_copy_brokes64(const struct ftr_brokes64 * source, 
        struct ftr_brokes64 * target);

#ifdef __cplusplus
}
#endif

#endif


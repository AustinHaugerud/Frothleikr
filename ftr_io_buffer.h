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


#ifndef ftr_io_buffer_h
#define ftr_io_buffer_h

#ifdef __cplusplus
extern "C" {
#endif

#include"ftr_broke_types.h"
#include"ftr_config.h"

struct FTR_API ftr_io_buffer {

    ftr_u8 * data;

    ftr_u64 size;

};

struct FTR_API ftr_io_buffer * ftr_create_buffer(unsigned int size);

void FTR_API ftr_write_bytes(struct ftr_io_buffer * buffer, ftr_u8 * bytes, 
        ftr_u64 len, ftr_u64 pos);

void FTR_API ftr_read_bytes(struct ftr_io_buffer * buffer, ftr_u8 * bytes, 
        ftr_u64 len,ftr_u64 read_pos);

void FTR_API ftr_clear_buffer(struct ftr_io_buffer * buffer);

void FTR_API ftr_free_buffer(struct ftr_io_buffer * buffer);

// Specialized write functions
/*******************************/

// These functions take broken values, so endianness is of little concern here


// Unsigned

void FTR_API ftr_write_u16(struct ftr_io_buffer * buffer, struct ftr_brokeu16 * val, 
        ftr_u64 pos);

void FTR_API ftr_write_u32(struct ftr_io_buffer * buffer, struct ftr_brokeu32 * val, 
        ftr_u64 pos);

void FTR_API ftr_write_u64(struct ftr_io_buffer * buffer, struct ftr_brokeu64 * val, 
        ftr_u64 pos);


// Signed

void FTR_API ftr_write_s16(struct ftr_io_buffer * buffer, struct ftr_brokes16 * val, 
        ftr_u64 pos);

void FTR_API ftr_write_s32(struct ftr_io_buffer * buffer, struct ftr_brokes32 * val, 
        ftr_u64 pos);

void FTR_API ftr_write_s64(struct ftr_io_buffer * buffer, struct ftr_brokes64 * val, 
        ftr_u64 pos);

/*********************************/

// Specialized read functions

// Unsigned

void FTR_API ftr_read_u16(struct ftr_io_buffer * buffer,struct ftr_brokeu16 * target, 
        ftr_u64 pos);

void FTR_API ftr_read_u32(struct ftr_io_buffer * buffer,struct ftr_brokeu32 * target, 
        ftr_u64 pos);

void FTR_API ftr_read_u64(struct ftr_io_buffer * buffer,struct ftr_brokeu64 * target, 
        ftr_u64 pos);

// Signed

void FTR_API ftr_read_s16(struct ftr_io_buffer * buffer,struct ftr_brokes16 * target, 
        ftr_u64 pos);

void FTR_API ftr_read_s32(struct ftr_io_buffer * buffer,struct ftr_brokes32 * target, 
        ftr_u64 pos);

void FTR_API ftr_read_s64(struct ftr_io_buffer * buffer,struct ftr_brokes64 * target, 
        ftr_u64 pos);

#ifdef __cplusplus
}
#endif

#endif


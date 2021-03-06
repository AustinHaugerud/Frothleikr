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

#include<ftr_broke_types.h>
#include<ftr_config.h>
#include<ftr_io_logger.h>

#ifdef __cplusplus
extern "C" {
#endif

struct FTR_API ftr_io_buffer {

    ftr_u8 * data;

    ftr_u64 size;

    ftr_u64 seek_pos;

    int seek_enabled;

    struct ftr_io_logger * logger; 

};

FTR_API struct ftr_io_buffer * ftr_create_buffer(unsigned int size);

FTR_API void ftr_write_bytes(struct ftr_io_buffer * buffer, const ftr_u8 * bytes, 
        ftr_u64 len, ftr_u64 pos);

FTR_API void ftr_read_bytes(const struct ftr_io_buffer * buffer, ftr_u8 * bytes, 
        ftr_u64 len,ftr_u64 read_pos);

FTR_API void ftr_free_buffer(struct ftr_io_buffer * buffer);

FTR_API void ftr_bind_logger(struct ftr_io_buffer * buffer, 
        struct ftr_io_logger * logger);

void ftr_hlog(const struct ftr_io_buffer * buffer, const char * entry);

// Specialized write functions
/*******************************/

// These functions take broken values, so endianness is of little concern here


// Unsigned

FTR_API void ftr_write_u16(struct ftr_io_buffer * buffer, const struct ftr_brokeu16 * val, 
        ftr_u64 pos);

FTR_API void ftr_write_u32(struct ftr_io_buffer * buffer, const struct ftr_brokeu32 * val, 
        ftr_u64 pos);

FTR_API void ftr_write_u64(struct ftr_io_buffer * buffer, const struct ftr_brokeu64 * val, 
        ftr_u64 pos);


// Signed

FTR_API void ftr_write_s16(struct ftr_io_buffer * buffer, const struct ftr_brokes16 * val, 
        ftr_u64 pos);

FTR_API void ftr_write_s32(struct ftr_io_buffer * buffer, const struct ftr_brokes32 * val, 
        ftr_u64 pos);

FTR_API void ftr_write_s64(struct ftr_io_buffer * buffer, const struct ftr_brokes64 * val, 
        ftr_u64 pos);

/*********************************/

// Specialized read functions

// Unsigned

FTR_API void ftr_read_u16(const struct ftr_io_buffer * buffer,
        struct ftr_brokeu16 * target, 
        ftr_u64 pos);

FTR_API void ftr_read_u32(const struct ftr_io_buffer * buffer,
        struct ftr_brokeu32 * target, 
        ftr_u64 pos);

FTR_API void ftr_read_u64(const struct ftr_io_buffer * buffer,
        struct ftr_brokeu64 * target, 
        ftr_u64 pos);

// Signed

FTR_API void ftr_read_s16(const struct ftr_io_buffer * buffer,
        struct ftr_brokes16 * target, 
        ftr_u64 pos);

FTR_API void ftr_read_s32(const struct ftr_io_buffer * buffer,
        struct ftr_brokes32 * target, 
        ftr_u64 pos);

FTR_API void ftr_read_s64(const struct ftr_io_buffer * buffer,
        struct ftr_brokes64 * target, 
        ftr_u64 pos);

#ifdef __cplusplus
}
#endif

#endif


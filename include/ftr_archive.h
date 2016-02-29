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

#ifndef ftr_archive_h
#define ftr_archive_h

#include<ftr_config.h>
#include<ftr_types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ftr_io_buffer;
struct ftr_io_buffer_seeker;

struct FTR_API ftr_archive {

    void (*archive_write)(struct ftr_io_buffer * buffer, void * parent,
            ftr_u64 pos);

    void (*archive_read)(struct ftr_io_buffer * buffer, void * parent,
            ftr_u64 pos);

    void (*archive_swrite)(struct ftr_io_buffer_seeker * seeker, void * parent);

    void (*archive_sread)(struct ftr_io_buffer_seeker * seeker, void * parent);

    void * parent;
};

FTR_API void ftr_archive_bind_write(struct ftr_archive * archive
        ,void (*func)(struct ftr_io_buffer * buffer,void * parent,ftr_u64));

FTR_API void ftr_archive_bind_read(struct ftr_archive * archive,
        void (*func)(struct ftr_io_buffer * buffer,void * parent,ftr_u64));

FTR_API void  ftr_archive_bind_swrite(struct ftr_archive * archive,
        void (*func)(struct ftr_io_buffer_seeker * seeker, void *parent));

FTR_API void ftr_archive_bind_sread(struct ftr_archive * archive,
        void (*func)(struct ftr_io_buffer_seeker * seeker, void * parent));

FTR_API void ftr_write(struct ftr_io_buffer * buffer,
        struct ftr_archive * archive, ftr_u64 pos);

FTR_API void ftr_read(struct ftr_io_buffer * buffer,
        struct ftr_archive * archive, ftr_u64 pos);

FTR_API void ftr_swrite(struct ftr_io_buffer_seeker * seeker,
        struct ftr_archive * archive);

FTR_API void tr_sread(struct ftr_io_buffer_seeker * seeker,
        struct ftr_archive * archive);

#ifdef __cplusplus
}
#endif

#endif


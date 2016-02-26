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

#include<ftr_archive.h>
#include<ftr_io_buffer.h>
#include<ftr_io_buffer_seeker.h>

void ftr_archive_bind_write(struct ftr_archive * archive,
        void (*func)(struct ftr_io_buffer * buffer,void * parent)) {
    archive->archive_write = func;
}

void ftr_archive_bind_read(struct ftr_archive * archive,
        void (*func)(struct ftr_io_buffer * buffer, void * parent)) {
    archive->archive_read = func;
}

void ftr_archive_bind_swrite(struct ftr_archive * archive,
        void(*func)(struct ftr_io_buffer_seeker * seeker, void * parent)) {
    archive->archive_swrite = func;
}

void ftr_archive_bind_sread(struct ftr_archive * archive,
        void(*func)(struct ftr_io_buffer_seeker * seeker, void * parent)) {
    archive->archive_sread = func;
}

void ftr_write(struct ftr_io_buffer * buffer,
        struct ftr_archive * archive) {
    archive->archive_write(buffer, archive->parent);
}

void ftr_read(struct ftr_io_buffer * buffer,
        struct ftr_archive * archive) {
    archive->archive_read(buffer, archive->parent);
}

void ftr_swrite(struct ftr_io_buffer_seeker * seeker,
        struct ftr_archive * archive) {
    archive->archive_swrite(seeker, archive->parent);
}

void ftr_sread(struct ftr_io_buffer_seeker * seeker,
        struct ftr_archive * archive) {
    archive->archive_sread(seeker, archive->parent);
}


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


#include<ftr_io_buffer_seeker.h>
#include<ftr_io_buffer.h>
#include<ftr_broke_types.h>
#include<ftr_io_logger.h>
#include<string.h>

/*
 * Modes
 *
 * r = read
 * w = write
 *
 * Cannot use both directions
 * l = forward direction
 * h = reverse direction
 *
 * Cannot use both seek bases
 *
 * b = seek_beg
 * e = seek_end
 */

int fmode(const char * modes, char mode) {

    int len = strlen(modes);

    for(int i = 0; i < len; ++i) {
        if(mode == modes[i])
            return 0;
    }

    return 1;
}

void hlog(const struct ftr_io_buffer_seeker * seeker, const char * entry) {
    if(seeker->buffer->logger != 0)
        ftr_log_entry(seeker->buffer->logger, entry);
}

// ex: ftr_init_seeker( buffer, seeker, "rhe")
// This would set up a seeker for read only from end to beg

void ftr_init_seeker(struct ftr_io_buffer * buffer,
        struct ftr_io_buffer_seeker * seeker, 
        const char * modes) {

    seeker->buffer = buffer;
    seeker->seek_pos = 0;

    seeker->read_enabled = fmode(modes, 'r');
    seeker->write_enabled  = fmode(modes, 'w');

    if(fmode(modes, 'h') == 0) {
        seeker->direction = ftr_op_backward;
        seeker->seek_pos = buffer->size;
    }
    else seeker->direction = ftr_op_forward;

    if(fmode(modes,'e') == 0) seeker->base = ftr_seek_end;
    else seeker->base = ftr_seek_beg;

}

void ftr_close_seeker(struct ftr_io_buffer_seeker *seeker) {
    seeker->buffer = 0;
    seeker->seek_pos = -1;
    seeker->read_enabled = -1;
    seeker->write_enabled = -1;
}

void ftr_reset_seek_pos(struct ftr_io_buffer_seeker * seeker, 
        ftr_seek_base seek_base,
        ftr_u64 pos) {

    if(seek_base == ftr_seek_end) {
        seeker->seek_pos = seeker->buffer->size - pos;
    }

    else if(seek_base == ftr_seek_beg) {
        seeker->seek_pos = pos;
    }
}

void ftr_swrite_bytes(struct ftr_io_buffer_seeker * seeker,
        const ftr_u8 * bytes,
        ftr_u64 size) {

    if(seeker->write_enabled != 0)
        return;

    // Memory allocation isn't meant to occur if writing end to beg
    // Reverse per unit, not per byte
    if(seeker->direction == ftr_op_backward) {
        seeker->seek_pos -= size;
        ftr_write_bytes(seeker->buffer, bytes, size, seeker->seek_pos);
    } 
    else {
        ftr_write_bytes(seeker->buffer,bytes,size,seeker->seek_pos);
        seeker->seek_pos += size;
    }

    hlog(seeker, "sw-bytes");
}

void ftr_swrite_u16(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokeu16 * val) {
    ftr_swrite_bytes(seeker, val->bytes, sizeof(ftr_u16));
    hlog(seeker, "sw-u16");
}

void ftr_swrite_u32(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokeu32 * val) {
    ftr_swrite_bytes(seeker, val->bytes, sizeof(ftr_u32));
    hlog(seeker, "sw-u32");
}

void ftr_swrite_u64(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokeu64 * val) {
    ftr_swrite_bytes(seeker, val->bytes, sizeof(ftr_u64));
    hlog(seeker, "sw-u64");
}

void ftr_swrite_s16(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokes16 * val) {
    ftr_swrite_bytes(seeker, val->bytes, sizeof(ftr_s16));
    hlog(seeker, "sw-s16");
}

void ftr_swrite_s32(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokes32 * val) {
    ftr_swrite_bytes(seeker, val->bytes, sizeof(ftr_s32));
    hlog(seeker, "sw-s32");
}

void ftr_swrite_s64(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokes64 * val) {
    ftr_swrite_bytes(seeker, val->bytes, sizeof(ftr_s64));
    hlog(seeker, "sw-s64");
}

// sread functions

void ftr_sread_bytes(struct ftr_io_buffer_seeker * seeker,
        ftr_u8 * bytes_target,
        ftr_u64 size) {

    if(seeker->read_enabled != 0)
        return;

    ftr_u64 pos = seeker->seek_pos;

    if(seeker->direction == ftr_op_backward) {

        for(int i = 0; i < size; ++i) {
            bytes_target[i] = seeker->buffer->data[pos - 1 - i];
            seeker->seek_pos -= size;
        }  
    }

    else {
        ftr_read_bytes(seeker->buffer, bytes_target, size, 
                seeker->seek_pos);
        seeker->seek_pos += size;
    }
    hlog(seeker, "sr-bytes");
}

void ftr_sread_u16(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokeu16 * val) {
    ftr_sread_bytes(seeker, val->bytes, sizeof(ftr_u16));
    hlog(seeker, "sr-u16");
}

void ftr_sread_u32(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokeu32 * val) {
    ftr_sread_bytes(seeker, val->bytes, sizeof(ftr_u32));
    hlog(seeker, "sr-u32");
}

void ftr_sread_u64(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokeu64 * val) {
    ftr_sread_bytes(seeker, val->bytes, sizeof(ftr_u64));
    hlog(seeker, "sr-u64");
}

void ftr_sread_s16(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokes16 * val) {
    ftr_sread_bytes(seeker, val->bytes, sizeof(ftr_s16));
    hlog(seeker, "sr-s16");
}

void ftr_sread_s32(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokes32 * val) {
    ftr_sread_bytes(seeker, val->bytes, sizeof(ftr_s32));
    hlog(seeker, "sr-s32");
}

void ftr_sread_s64(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokes64 * val) {
    ftr_sread_bytes(seeker, val->bytes, sizeof(ftr_s64));
    hlog(seeker, "sr-s64");
}


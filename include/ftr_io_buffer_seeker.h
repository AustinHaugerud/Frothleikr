#ifndef ftr_io_buffer_seeker_h
#define ftr_io_buffer_seeker_h

#ifdef __cplusplus
extern "C" {
#endif

#include<ftr_types.h>
#include<ftr_config.h>

struct ftr_io_buffer;

struct ftr_brokeu16;
struct ftr_brokeu32;
struct ftr_brokeu64;

struct ftr_brokes16;
struct ftr_brokes32;
struct ftr_brokes64;

typedef enum { ftr_seek_beg, ftr_seek_end } ftr_seek_base;

typedef enum { ftr_op_forward, ftr_op_backward } ftr_op_direction;

struct FTR_API ftr_io_buffer_seeker {

    struct ftr_io_buffer * buffer;

    ftr_u64 seek_pos;

    int read_enabled;
    int write_enabled;

    ftr_op_direction direction;
    ftr_seek_base base;
};

void FTR_API ftr_init_seeker(struct ftr_io_buffer * buffer,
        struct ftr_io_buffer_seeker * seeker, 
        const char * modes);

void FTR_API ftr_close_seeker(struct ftr_io_buffer_seeker *seeker);

void FTR_API ftr_reset_seek_pos(struct ftr_io_buffer_seeker * seeker, 
        ftr_seek_base seek_base,
        ftr_u64 pos);

// swrite functions

void FTR_API ftr_swrite_bytes(struct ftr_io_buffer_seeker * seeker, 
        const ftr_u8 * bytes,
        ftr_u64 size);

void FTR_API ftr_swrite_u16(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokeu16 * val);

void FTR_API ftr_swrite_u32(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokeu32 * val);

void FTR_API ftr_swrite_u64(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokeu64 * val);

void FTR_API ftr_swrite_s16(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokes16 * val);

void FTR_API ftr_swrite_s32(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokes32 * val);

void FTR_API ftr_swrite_s64(struct ftr_io_buffer_seeker * seeker,
        const struct ftr_brokes64 * val);

// sread functions

void FTR_API ftr_sread_bytes(struct ftr_io_buffer_seeker * seeker, 
        ftr_u8 * bytes_target,
        ftr_u64 size);

void FTR_API ftr_sread_u16(struct ftr_io_buffer_seeker * seeker, 
        struct ftr_brokeu16 * target);

void FTR_API ftr_sread_u32(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokeu32 * target);

void FTR_API ftr_sread_u64(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokeu64 * target);

void FTR_API ftr_sread_s16(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokes16 * target);

void FTR_API ftr_sread_s32(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokes32 * target);

void FTR_API ftr_sread_s64(struct ftr_io_buffer_seeker * seeker,
        struct ftr_brokes64 * target);

#ifdef __cplusplus
}
#endif

#endif


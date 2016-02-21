#include"ftr_io_buffer.h"
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<inttypes.h>
#include<string.h>

struct ftr_io_buffer * ftr_create_buffer(unsigned int size) {

#ifdef __cplusplus
    struct ftr_io_buffer * buffer 
        = (ftr_io_buffer*)malloc(sizeof(ftr_io_buffer));
#else
    struct ftr_io_buffer * buffer
        = malloc(sizeof(struct ftr_io_buffer));
#endif

    buffer->size = size;

    if(size == 0) {
        buffer->data = 0;
        return buffer;
    }

#ifdef __cplusplus
    buffer->data = (ftr_u8*)malloc(sizeof(ftr_u8) * size);
#else
    buffer->data = malloc(sizeof(ftr_u8) * size);
#endif
    return buffer;

}

void ftr_write_bytes(struct ftr_io_buffer * buffer, ftr_u8 * bytes, 
        ftr_u64 len, ftr_u64 pos) {

    ftr_s64 new_alloc_size = ((ftr_s64)pos + (ftr_s64)len) - (ftr_s64)buffer->size;

    if(new_alloc_size < 0) new_alloc_size = 0;
  
#ifdef __cplusplus
    ftr_u8 * dat = (ftr_u8*)realloc(buffer->data, buffer->size + new_alloc_size);
#else
    ftr_u8 * dat = realloc(buffer->data, buffer->size + new_alloc_size);
#endif

    if(dat != NULL)
        buffer->data = dat;
 
    memcpy(&buffer->data[pos], bytes, len); 

    buffer->size += len;
}

void ftr_read_bytes(struct ftr_io_buffer * buffer, ftr_u8 * bytes, 
        ftr_u64 len, ftr_u64 read_pos) {

    memcpy(bytes, &buffer->data[read_pos], len);
}

void ftr_clear_buffer(struct ftr_io_buffer * buffer) {
    buffer->size = 0;
    free(buffer->data);
}

void ftr_free_buffer(struct ftr_io_buffer * buffer) {
    ftr_clear_buffer(buffer);
    free(buffer);
}

// Specialized write functions
/*********************************/

// Unsigned

void ftr_write_u16(struct ftr_io_buffer * buffer, struct ftr_brokeu16 * val, 
        ftr_u64 pos) {
    ftr_write_bytes(buffer, val->bytes, sizeof(ftr_u16), pos);
}

void ftr_write_u32(struct ftr_io_buffer * buffer, struct ftr_brokeu32 * val, 
        ftr_u64 pos) {
    ftr_write_bytes(buffer, val->bytes, sizeof(ftr_u32), pos);
}

void ftr_write_u64(struct ftr_io_buffer * buffer, struct ftr_brokeu64 * val, 
        ftr_u64 pos) {
    ftr_write_bytes(buffer, val->bytes, sizeof(ftr_u64), pos);
}

// Signed

void ftr_write_s16(struct ftr_io_buffer * buffer, struct ftr_brokes16 * val, 
        ftr_u64 pos) {
    ftr_write_bytes(buffer, val->bytes, sizeof(ftr_s16), pos);
}

void ftr_write_s32(struct ftr_io_buffer * buffer, struct ftr_brokes32 * val, 
        ftr_u64 pos) {
    ftr_write_bytes(buffer, val->bytes, sizeof(ftr_s32), pos);
}

void ftr_write_s64(struct ftr_io_buffer * buffer, struct ftr_brokes64 * val, 
        ftr_u64 pos) {
    ftr_write_bytes(buffer, val->bytes, sizeof(ftr_s64), pos);
}

/******************************/

// Sepcialized read functions

// Unsigned 

void ftr_read_u16(struct ftr_io_buffer *buffer, struct ftr_brokeu16 *target, 
        ftr_u64 pos) {
    ftr_read_bytes(buffer, target->bytes, sizeof(ftr_u16), pos);
}

void ftr_read_u32(struct ftr_io_buffer *buffer, struct ftr_brokeu32 *target, 
        ftr_u64 pos) {
    ftr_read_bytes(buffer, target->bytes, sizeof(ftr_u32), pos);
}

void ftr_read_u64(struct ftr_io_buffer *buffer, struct ftr_brokeu64 *target, 
        ftr_u64 pos) {
    ftr_read_bytes(buffer, target->bytes, sizeof(ftr_u64), pos);
}

// Signed

void ftr_read_s16(struct ftr_io_buffer *buffer, struct ftr_brokes16 *target, 
        ftr_u64 pos) {
    ftr_read_bytes(buffer, target->bytes, sizeof(ftr_s16), pos);
}

void ftr_read_s32(struct ftr_io_buffer *buffer, struct ftr_brokes32 *target, 
        ftr_u64 pos) {
    ftr_read_bytes(buffer, target->bytes, sizeof(ftr_s32), pos);
}

void ftr_read_s64(struct ftr_io_buffer *buffer, struct ftr_brokes64 *target, 
        ftr_u64 pos) {
    ftr_read_bytes(buffer, target->bytes, sizeof(ftr_s64), pos);
}

/****************************/


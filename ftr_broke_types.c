#include"ftr_broke_types.h"
#include<string.h>

void ftr_copy_brokeu16(struct ftr_brokeu16 * source, 
        struct ftr_brokeu16 * target) {

    memcpy(&target->bytes, &source->bytes, sizeof(ftr_u16));
}

void ftr_copy_brokeu32(struct ftr_brokeu32 * source, 
        struct ftr_brokeu32 * target) {

    memcpy(&target->bytes, &source->bytes, sizeof(ftr_u32));
}

void ftr_copy_brokeu64(struct ftr_brokeu64 * source, 
        struct ftr_brokeu64 * target) {

    memcpy(&target->bytes, &source->bytes, sizeof(ftr_u64));
}

void ftr_copy_brokes16(struct ftr_brokes16 * source, 
        struct ftr_brokes16 * target) {

    memcpy(&target->bytes, &source->bytes, sizeof(ftr_s16));
}

void ftr_copy_brokes32(struct ftr_brokes32 * source, 
        struct ftr_brokes32 * target) {

    memcpy(&target->bytes, &source->bytes, sizeof(ftr_s32));
}

void ftr_copy_brokes64(struct ftr_brokes64 * source, 
        struct ftr_brokes64 * target) {

    memcpy(&target->bytes, &source->bytes, sizeof(ftr_s64));
}


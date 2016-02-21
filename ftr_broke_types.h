#ifndef ftr_broke_types_h
#define ftr_broke_types_h

#ifdef __cplusplus
extern "C" {
#endif

#include"ftr_config.h"
#include"ftr_types.h"

// UNSIGNED

struct FTR_API ftr_brokeu16 {
    ftr_u8 bytes[2];
};

void FTR_API ftr_copy_brokeu16(struct ftr_brokeu16 * source,
        struct ftr_brokeu16 * target);

struct ftr_brokeu32 {
    ftr_u8 bytes[4];
};

void FTR_API ftr_copy_brokeu32(struct ftr_brokeu32 * source, 
        struct ftr_brokeu32 * target);

struct FTR_API ftr_brokeu64 {
    ftr_u8 bytes[8];
};

void FTR_API ftr_copy_brokeu64(struct ftr_brokeu64 * source, 
        struct ftr_brokeu64 * target);

// SIGNED

struct FTR_API ftr_brokes16 {
    ftr_u8 bytes[2];
};

void FTR_API ftr_copy_brokes16(struct ftr_brokes16 * source, 
        struct ftr_brokes16 * target);

struct FTR_API ftr_brokes32 {
    ftr_u8 bytes[4];
};

void FTR_API ftr_copy_brokes32(struct ftr_brokes32 * source, 
        struct ftr_brokes32 * target);

struct FTR_API ftr_brokes64 {
    ftr_u8 bytes[8];
};

void FTR_API ftr_copy_brokes64(struct ftr_brokes64 * source, 
        struct ftr_brokes64 * target);

#ifdef __cplusplus
}
#endif

#endif


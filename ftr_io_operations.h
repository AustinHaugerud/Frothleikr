#ifndef ftr_io_operations_h
#define ftr_io_operations_h

#ifdef __cplusplus
extern "C" {
#endif

#include"ftr_broke_types.h"

// UNSIGNED
/***********************************************/
// break into little endian 
void ftr_break_u16l(ftr_u16 val, struct ftr_brokeu16 * target);

void ftr_break_u32l(ftr_u32 val, struct ftr_brokeu32 * target);

void ftr_break_u64l(ftr_u64 val, struct ftr_brokeu64 * target);

// assemble from little endian

ftr_u16 ftr_assemble_u16l(struct ftr_brokeu16 * val);

ftr_u32 ftr_assemble_u32l(struct ftr_brokeu32 * val);

ftr_u64 ftr_assemble_u64l(struct ftr_brokeu64 * val);

// break into big endian

void ftr_break_u16b(ftr_u16 val, struct ftr_brokeu16 * target);

void ftr_break_u32b(ftr_u32 val, struct ftr_brokeu32 * target);

void ftr_break_u64b(ftr_u64 val, struct ftr_brokeu64 * target);

// assemble into big endian

ftr_u16 ftr_assemble_u16b(struct ftr_brokeu16 * val);

ftr_u32 ftr_assemble_u32b(struct ftr_brokeu32 * val);

ftr_u64 ftr_assemble_u64b(struct ftr_brokeu64 * val);
/**********************************************/

// SIGNED
/*********************************************/
// break into little endian

void ftr_break_s16l(ftr_s16 val, struct ftr_brokes16 * target);

void ftr_break_s32l(ftr_s32 val, struct ftr_brokes32 * target);

void ftr_break_s64l(ftr_s64 val, struct ftr_brokes64 * target);

// assemble into little endian

ftr_s16 ftr_assemble_s16l(struct ftr_brokes16 * val);

ftr_s32 ftr_assemble_s32l(struct ftr_brokes32 * val);

ftr_s64 ftr_assemble_s64l(struct ftr_brokes64 * val);

// break into big endian

void ftr_break_s16b(ftr_s16 val, struct ftr_brokes16 * target);

void ftr_break_s32b(ftr_s32 val, struct ftr_brokes32 * target);

void ftr_break_s64b(ftr_s64 val, struct ftr_brokes64 * target);

// assemble into big endian

ftr_s16 ftr_assemble_s16b(struct ftr_brokes16 * val);

ftr_s32 ftr_assemble_s32b(struct ftr_brokes32 * val);

ftr_s64 ftr_assemble_s64b(struct ftr_brokes64 * val);

// FLOATING POINT
/***************************************/

// Pack float into u32 integer, not incredibly good at preserving precision
ftr_u32 ftr_pack_float_u32(float val);

float ftr_unpack_float_u32(ftr_u32 val);

/* 
 * Pack floating point value into unsigned integer, good at preserving 
 * precision for floats and doubles
 */
ftr_u64  __ftr_pack_IEEE754(long double val, unsigned bits, unsigned expbits);

long double __ftr_unpack_IEEE754(ftr_u64 val, unsigned bits, unsigned expbits);

#define ftr_pack_double_u32(val) (__ftr_pack_IEEE754((val), 32, 8))
#define ftr_pack_double_u64(val) (__ftr_pack_IEEE754((val), 64, 11))

#define ftr_unpack_double_u32(val) (__ftr_unpack_IEEE754((val), 32, 8))
#define ftr_unpack_double_u64(val) (__ftr_unpack_IEEE754((val), 64, 11)) 

#ifdef __cplusplus
}
#endif

#endif


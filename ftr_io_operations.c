#include"ftr_io_operations.h"

// UNSIGNED
/***********************************************/

// Break into little endian
void ftr_break_u16l(ftr_u16 val, struct ftr_brokeu16 * target) {
    target->bytes[0] = (val) & 0xFF;
    target->bytes[1] = (val >> 8) & 0xFF; 
}

void ftr_break_u32l(ftr_u32 val, struct ftr_brokeu32 * target) {

    target->bytes[0] = (val) & 0xFF;
    target->bytes[1] = (val >> 8) & 0xFF;
    target->bytes[2] = (val >> 16) & 0xFF;
    target->bytes[3] = (val >> 24) & 0xFF;
}

void ftr_break_u64l(ftr_u64 val, struct ftr_brokeu64 * target) {

    target->bytes[0] = (val) & 0xFF;
    target->bytes[1] = (val >> 8) & 0xFF;
    target->bytes[2] = (val >> 16) & 0xFF;
    target->bytes[3] = (val >> 24) & 0xFF;
    target->bytes[4] = (val >> 32) & 0xFF;
    target->bytes[5] = (val >> 40) & 0xFF;
    target->bytes[6] = (val >> 48) & 0xFF;
    target->bytes[7] = (val >> 56) & 0xFF;

}

// Assemble into little endian

ftr_u16 ftr_assemble_u16l(struct ftr_brokeu16 * val) {

    ftr_u16 aval;

    aval  = val->bytes[0] | (val->bytes[1] << 8);

    return aval;
}

ftr_u32 ftr_assemble_u32l(struct ftr_brokeu32 * val) {

    ftr_u32 aval;
    ftr_u8 * bytes = &val->bytes[0];

    aval = bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24);

    return aval;

}

ftr_u64 ftr_assemble_u64l(struct ftr_brokeu64 * val) {

    ftr_u64 aval;
    ftr_u8 * bytes = &val->bytes[0]; 

    aval = bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24)
        | ((ftr_u64)bytes[4] << 32) 
        | ((ftr_u64)bytes[5] << 40)
        | ((ftr_u64)bytes[6] << 48)
        | ((ftr_u64)bytes[7] << 56);

    return aval;
}

// Break into big endian

void ftr_break_u16b(ftr_u16 val, struct ftr_brokeu16 * target) {

    target->bytes[0] = (val >> 8) & 0xFF;
    target->bytes[1] = (val) & 0xFF;
 
}

void ftr_break_u32b(ftr_u32 val, struct ftr_brokeu32 * target) {
    
    target->bytes[0] = (val >> 24) & 0xFF;
    target->bytes[1] = (val >> 16) & 0xFF;
    target->bytes[2] = (val >> 8) & 0xFF;
    target->bytes[3] = (val) & 0xFF; 
}

void ftr_break_u64b(ftr_u64 val, struct ftr_brokeu64 * target) {

    target->bytes[0] = (val >> 56) & 0xFF;
    target->bytes[1] = (val >> 48) & 0xFF;
    target->bytes[2] = (val >> 40) & 0xFF;
    target->bytes[3] = (val >> 32) & 0xFF;
    target->bytes[4] = (val >> 24) & 0xFF;
    target->bytes[5] = (val >> 16) & 0xFF;
    target->bytes[6] = (val >> 8) & 0xFF;
    target->bytes[7] = (val) & 0xFF; 
}

// Assemble into big endian

ftr_u16 ftr_assemble_u16b(struct ftr_brokeu16 * val) {
    ftr_u16 aval;
    
    aval = (val->bytes[0] << 8) | (val->bytes[1]);

    return aval;
}

ftr_u32 ftr_assemble_u32b(struct ftr_brokeu32 * val) {
    ftr_u32 aval;
    ftr_u8 * bytes = &val->bytes[0];

    aval =
        (bytes[0] << 24) | (bytes[1] << 16) 
        | (bytes[2] << 8) | (bytes[3]);

    return aval;
}

ftr_u64 ftr_assemble_u64b(struct ftr_brokeu64 * val) {
    ftr_u64 aval;
    ftr_u8 * bytes = &val->bytes[0];

    aval =
        ((ftr_u64)bytes[0] << 56) |
        ((ftr_u64)bytes[1] << 48) |
        ((ftr_u64)bytes[2] << 40) |
        ((ftr_u64)bytes[3] << 32) |
        (bytes[4] << 24) |
        (bytes[5] << 16) |
        (bytes[6] << 8)  |
        (bytes[7]);

    return aval;
}

// SIGNED
/**********************************************/

// Break into little endian

void ftr_break_s16l(ftr_s16 val, struct ftr_brokes16 * target) {
    
    target->bytes[0] = val & 0xFF;
    target->bytes[1] = (val >> 8) & 0xFF; 
}

void ftr_break_s32l(ftr_s32 val, struct ftr_brokes32 * target) {

    target->bytes[0] = val & 0xFF;
    target->bytes[1] = (val >> 8) & 0xFF;
    target->bytes[2] = (val >> 16) & 0xFF;
    target->bytes[3] = (val >> 24) & 0xFF;
 
}

void ftr_break_s64l(ftr_s64 val, struct ftr_brokes64 * target) {
    
    target->bytes[0] = val & 0xFF;
    target->bytes[1] = (val >> 8) & 0xFF;
    target->bytes[2] = (val >> 16) & 0xFF;
    target->bytes[3] = (val >> 24) & 0XFF;
    target->bytes[4] = (val >> 32) & 0xFF;
    target->bytes[5] = (val >> 40) & 0xFF;
    target->bytes[6] = (val >> 48) & 0xFF;
    target->bytes[7] = (val >> 56) & 0xFF; 

}

// Assemble into little endian

ftr_s16 ftr_assemble_s16l(struct ftr_brokes16 * val) {
    ftr_u16 aval;

    aval = val->bytes[0] | (val->bytes[1] << 8);

    ftr_s16 aval2;

    if(aval <= 0x7fffu) { aval2 = aval; }
    else { aval2 = -1 - (ftr_s16)(0xffffu - aval); }

    return aval2;
}

ftr_s32 ftr_assemble_s32l(struct ftr_brokes32 * val) {
    ftr_u32 aval;

    aval = val->bytes[0] | (val->bytes[1] << 8)
        | (val->bytes[2] << 16) | (val->bytes[3] << 24);

    ftr_s32 aval2;

    if(aval <= 0x7fffffffu) { aval2 = aval; }
    else { aval2 = -1 - (ftr_u32)(0xffffffffu - aval); }

    return aval2;
}

ftr_s64 ftr_assemble_s64l(struct ftr_brokes64 * val) {
    ftr_u64 aval;
    ftr_u8 * bytes = &val->bytes[0];

    aval 
        =
        (ftr_u64)bytes[0] | 
        ((ftr_u64)bytes[1] << 8) |
        ((ftr_u64)bytes[2] << 16) |
        ((ftr_u64)bytes[3] << 24) |
        ((ftr_u64)bytes[4] << 32) |
        ((ftr_u64)bytes[5] << 40) |
        ((ftr_u64)bytes[6] << 48) |
        ((ftr_u64)bytes[7] << 56); 

    ftr_s64 aval2;

    if(aval <= 0x7fffffffffffffffu) { aval2 = aval; }
    else { aval2 = -1 - (ftr_s64)(0xffffffffffffffffu - aval); }

    return aval2;
    
}

// Break into big endian

void ftr_break_s16b(ftr_s16 val, struct ftr_brokes16 * target) { 

    target->bytes[0] = (val >> 8) & 0xFF;
    target->bytes[1] = (val) & 0xFF; 
}

void ftr_break_s32b(ftr_s32 val, struct ftr_brokes32 * target) { 

    target->bytes[0] = (val >> 24) & 0xFF;
    target->bytes[1] = (val >> 16) & 0xFF;
    target->bytes[2] = (val >> 8) & 0xFF;
    target->bytes[3] = val & 0xFF;
 
}

void ftr_break_s64b(ftr_s64 val, struct ftr_brokes64 * target) {
    
    target->bytes[0] = (val >> 56) & 0xFF;
    target->bytes[1] = (val >> 48) & 0xFF;
    target->bytes[2] = (val >> 40) & 0xFF;
    target->bytes[3] = (val >> 32) & 0xFF;
    target->bytes[4] = (val >> 24) & 0xFF;
    target->bytes[5] = (val >> 16) & 0xFF;
    target->bytes[6] = (val >> 8) & 0xFF;
    target->bytes[7] = val & 0xFF;
 
}

// Assemble into big endian

ftr_s16 ftr_assemble_s16b(struct ftr_brokes16 * val) {
    ftr_s16 aval;

    aval = (val->bytes[0] << 8) | val->bytes[1];

    ftr_s16 aval2;

    if(aval <= 0x7fffu) { aval2 = aval; }
    else { aval2 = -1 - (ftr_s16)(0xffffu - aval); }

    return aval2;
}

ftr_s32 ftr_assemble_s32b(struct ftr_brokes32 * val) {
    ftr_s32 aval;
    ftr_u8 * bytes = &val->bytes[0];

    aval = (bytes[0] << 24) | (bytes[1] << 16) 
        | (bytes[2] << 8) | bytes[3];

    ftr_s32 aval2;

    if(aval <= 0x7fffffffu) { aval2 = aval; }
    else { aval2 = -1 - (ftr_u32)(0xffffffffu - aval); }

    return aval2;
}

ftr_s64 ftr_assemble_s64b(struct ftr_brokes64 * val) {
    ftr_s64 aval;
    ftr_u8 * bytes = &val->bytes[0];

    aval =
        ((ftr_s64)bytes[0] << 56) |
        ((ftr_s64)bytes[1] << 48) |
        ((ftr_s64)bytes[2] << 40) |
        ((ftr_s64)bytes[3] << 32) |
        (bytes[4] << 24) |
        (bytes[5] << 16) |
        (bytes[6] << 8)  |
        (bytes[7]);

    ftr_s64 aval2;

    if(aval <= 0x7fffffffffffffffu) { aval2 = aval; }
    else { aval2 = -1 - (ftr_s64)(0xffffffffffffffffu - aval); }

    return aval2; 
}

// FLOATING POINT
/*******************************************************/

ftr_u32 ftr_pack_float_u32(float val) {
    ftr_u32 pval;
    ftr_u32 sign;

    if( val < 0) { sign = 1; val = -val; }
    else { sign = 0; }

    pval = ((((ftr_u32)val) & 0x7fff) << 16) | (sign << 31);
    pval |= (ftr_u32)(((val - (int)val) * 65536.f)) & 0xffff;

    return pval;
}

float ftr_unpack_float_u32(ftr_u32 val) {
    float uval = ((val >> 16) & 0x7fff);
    uval += (val & 0xffff) / 65536.f;

    if(((val >> 31) & 0x1) == 0x1) { uval = -uval; }

    return uval;
}

ftr_u64 __ftr_pack_IEEE754(long double val, unsigned bits, unsigned expbits) {
    long double fnorm;
    int shift;
    long long sign, exp, significand;
    unsigned significandbits = bits - expbits - 1;

    if(val == 0.f)
        return 0;

    if(val < 0) {
        sign = 1;
        fnorm = -val;
    }

    else {
        sign = 0;
        fnorm = val;
    }

    shift = 0;

    while(fnorm >= 2.f) {
        fnorm /= 2.f;
        shift++;
    }

    while(fnorm < 1.f) {
        fnorm *= 2.f;
        shift--;
    }
    fnorm = fnorm - 1.f;

    significand = fnorm * ((1LL << significandbits) + 0.5f);

    exp = shift + ((1 << (expbits-1)) -1);

    return (sign << (bits-1)) | (exp << (bits - expbits - 1)) | significand;
}

long double __ftr_unpack_IEEE754(ftr_u64 val, unsigned bits, unsigned expbits) {
    long double result;
    long long shift;
    unsigned bias;
    unsigned significandbits = bits - expbits - 1;

    if(val == 0) return 0.0;

    result = (val & ((1LL << significandbits) - 1));
    result /= (1LL << significandbits);
    result += 1.f;

    bias = (1 << (expbits - 1)) - 1;
    shift = ((val >> significandbits) & ((1LL << expbits) - 1)) - bias;

    while(shift > 0) {
        result *= 2.0f;
        shift--;
    }

    while(shift < 0) {
        result /= 2.0;
        shift++;
    }

    result *= (val >> (bits - 1)) &1? - 1.0 : 1.0;

    return result;
}


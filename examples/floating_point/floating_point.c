#include"../../frothleikr.h"
#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main(void) {

    /*
     * Frothleikr will help you serialize your floating point values
     * into a portable format following the IEEE-754 standard
     *
     * Rather than breaking the float directly into a byte-by-byte
     * sequence, Frothleikr will pack floating point values
     * into integer types.
     *
     * There are two provided functions for doing this
     *
     * ftr_pack_float_u32(float)
     *
     * This method is simple and quick, but it is not
     * incredibly reliable for keeping precision
     *
     * ftr_pack_IEEE754(...)
     *
     * This method isn't meant to be used directly, instead
     * you'll most likely want to use the macros overlaying it
     *
     * ftr_pack_double_u32(double)
     * ftr_pack_double_u64(double)
     *
     * Using those macros will allow you store with much
     * better precision, and if you pack in a u64 integer,
     * you can store larger floating point values
     * 
     * Both of these functions will preserve the sign of the 
     * floating point value
     *
     * Once your floating point values have been packed,
     * you can break them like a regular ftr_uintx
     */


    float float_ex = 3.1415f;

    double double32_ex = -1.12345678f;

    long double double64_ex = 999999999999.123f;

    ftr_u32 pfloat_ex = ftr_pack_float_u32(float_ex);

    ftr_u32 pdouble32_ex = ftr_pack_double_u32(double32_ex);

    ftr_u64 pdouble64_ex = ftr_pack_double_u64(double64_ex);

    float ufloat_ex = ftr_unpack_float_u32(pfloat_ex);

    double udouble32_ex = ftr_unpack_double_u32(pdouble32_ex);

    long double udouble64_ex = ftr_unpack_double_u64(pdouble64_ex);

    printf("Float ex %f to %i back to %f\n", float_ex, pfloat_ex, ufloat_ex);

    printf("Double 32 ex %f to %i back to %f\n", double32_ex, pdouble32_ex, udouble32_ex);

    printf("Double 64 ex %Le to % " PRIu64 " to %Le\n", double64_ex, pdouble64_ex, udouble64_ex);

    float error1 = float_ex - ufloat_ex;

    double error2 = double32_ex - udouble32_ex;

    long double error3 = double64_ex - double64_ex;

    // Lets display the amount of error
    printf("Error 1: %f\n", error1);
    printf("Error 2: %f\n", error2);
    printf("Error 3: %Le\n", error3);

    return 0; 
}


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



#include"../../frothleikr.h"
#include<stdio.h>

int main(void) {

    /*
     * In this example, you see how you can convert a simple integer into
     * a portable array of bytes
     */


    /* 
     * Frothleikr typedefs types guarenteed to be the same across platforms for you
     * You're completely free to use something such as "int32_t" instead if you wish
     * Be careful about types that vary in size such as plain "int" however
     */

    ftr_s32 my_pos_int = 123;

    ftr_s32 my_neg_int = -321;


    /*
     * Frothleikr uses "broke" structures to store converted integers
     * An array of unsigned chars is used internally to store the
     * integer in a byte by byte sequence
     */

    struct ftr_brokes32 my_broke_pos_int;

    struct ftr_brokes32 my_broke_neg_int;

    /*
     * Here we use the "break" functions
     * This is where you must choose your endianness 
     *
     * There should be no reason for you to ever have  the need to reverse endianness
     * As long as you make sure to stick with the endianness you chose, your program will
     * be able to break and assemble the data properly regardless of whether it run on a big
     * or little endian mahcine
     */

    /*
     * In this case, we'll for no particular reason choose big endian
     * Again, even if your machine is little endian, this will work fine
     * The same goes for vice. versa. 
     *
     * For all break functions, the endianness is denoted by the letter at the
     * the end of the name of the function
     * 'l' = little endian
     * 'b' = big endian
     */

    ftr_break_s32b(my_pos_int, &my_broke_pos_int);

    ftr_break_s32b(my_neg_int, &my_broke_neg_int);

    /*
     * Our two ftr_brokes32 structures now hold the data of our two original signed integers
     * in their own 4 byte arrays 
     *
     * At this point, you can access those bytes if you wish
     *
     * ftr_u8 nbyte = broke_int->bytes[n];
     *
     * You can also dump it to an instance of the struct ftr_io_buffer, which is discussed in a different example
     *
     * In this case, we'll simply reassemble them into two new ints
     */


    /*
     * Note how we specify big endian again here
     * It is absolutely vital you keep your endianness consistent
     * Do this, and you will have no need for byte swaps
     */

    ftr_s32 remade_pos_int = ftr_assemble_s32b(&my_broke_pos_int);

    ftr_s32 remade_neg_int = ftr_assemble_s32b(&my_broke_neg_int);

    /*
     * Now let's print our reassembled integer values and see if they match
     */

    printf("My pos int was %i , reassembled it's %i!\n", my_pos_int, remade_pos_int);
    printf("My neg int was %i , reassembled it's %i!\n", my_neg_int, remade_neg_int);

    /*
     * For this example, no memory clean up is necessary as nothing has been dynamically allocated
     */

    return 0;
}


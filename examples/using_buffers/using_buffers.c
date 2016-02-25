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


#include<frothleikr.h>
#include<stdio.h>

int main(void) {

    /*
     * ftr_io_buffer is a very simple wrapper around a byte array
     * If you want to, you can use your own byte array as a buffer
     * Using ftr_io_buffer however, many of the write operations
     * are already done for you
     */

    /*
     * First let's create our buffer
     *
     * You can allocate your buffer with ftr_create_buffer(size)
     *
     * In this case, we can pass the size as 0 since we have
     * nothing to allocate for right this moment
     *
     * If you were planning on manually loading some data
     * into the buffer, then you'll want to pre-allocate
     * the buffer
     *
     * i.e. fread()
     * or
     * i.e. memcpy()
     */

    struct ftr_io_buffer * buffer = ftr_create_buffer(0);

    /*
     * You are provided with a series of functions to
     * make writing to a buffer quick and simple
     *
     * ftr_write_u16(...)
     * ...
     * ...
     *
     * ftr_read_u16(...)
     * ...
     * ...
     *
     * ftr_write_s16(..)
     *
     * and so on.
     *
     * None of these functions are concerned about
     * whether the data is broken down as big or 
     * little endian, you just need to remember
     * that yourself when reassembling
     *
     * We'll throw a signed 32-bit int in
     */

    ftr_s32 my_signed_int = -100;

    struct ftr_brokes32 my_broke_signed_int;

    ftr_break_s32b(my_signed_int, &my_broke_signed_int);

    // We have our signed int prepared to be tossed in

    /* 
     * args: target buffer, source ftr_brokes32, write position
     * Note, it's important to know what happens based
     * on the write position you specify
     *
     * If you write so that the data doesn't fit in the buffer, 
     * the buffer will be realloc'd to append the bytes
     * Obviously writing to the end will always cause a realloc
     *
     * If you write so that the data does fit in the buffer,
     * the bytes are simply overwritten, the bytes will 
     * not be inserted, be prepared to overwrite the
     * previous values stored at those bytes in the buffer
     */

    ftr_write_s32(buffer, &my_broke_signed_int, 0);

    /*
     * All of the read & write functions are actually
     * just wrappers around...
     * 
     * write_bytes(...) & read_bytes(...)
     *
     * You may find these useful if you're doing something
     * such as dealing with arrays of bytes
     *
     * Let us demonstrate with some random bytes
     */

    ftr_u8 bytes[4] = { 8, 34, 76, 92 };

    /*
     * args: buffer, source bytes, num. bytes, write pos
     */

    ftr_write_bytes(buffer, bytes, sizeof(bytes), buffer->size);

    /*
     * Now let's imagine our buffer got shipped off to do 
     * whatever purpose it was made for, and that now
     * it's time to recover it's data after loading
     * it back into memory
     */

    struct ftr_brokes32 reading_broke_signed_int;

    ftr_read_s32(buffer, &reading_broke_signed_int, 0);

    ftr_s32 read_signed_int = ftr_assemble_s32b(&reading_broke_signed_int);

    ftr_u8 read_bytes[4];

    // Read bytes will never realloc a destination array
    ftr_read_bytes(buffer, read_bytes, sizeof(read_bytes), sizeof(ftr_s32));

    /*
     * Now let's confirm things went as planned
     */

    printf("%i to %i\n", my_signed_int, read_signed_int);

    for(int i = 0; i < 4; ++i) {
        printf("Arr[%i] - %i to %i\n", i, (int)bytes[i], (int)read_bytes[i]);
    }

    /*
     * There's one last important step!
     * We need to free our memory!
     */

    ftr_free_buffer(buffer);

    /*
     * If you wanted to delete the buffers data without
     * deleting the buffer itself, use
     *
     * ftr_clear_buffer(buffer);
     */

    {
        struct ftr_io_buffer * buffer = ftr_create_buffer(4 * sizeof(ftr_u32));
        struct ftr_io_buffer_seeker seeker;
        struct ftr_io_logger * logger = ftr_create_logger();
        ftr_init_seeker(buffer, &seeker, "wh"); // open to write and reverse
        ftr_bind_logger(buffer, logger);

        ftr_u32 ints[4] = { 100, 200, 300, 400 };

        struct ftr_brokeu32 broke_ints[4];

        for(int i = 0; i < 4; ++i) {
            ftr_break_u32b(ints[i], &broke_ints[i]);
            ftr_swrite_u32(&seeker, &broke_ints[i]);
            printf((char*)broke_ints[i].bytes);
        }

        struct ftr_io_buffer_seeker seeker2;
        ftr_init_seeker(buffer, &seeker2, "rh");

        struct ftr_brokeu32 broke_ints2[4];
        ftr_u32 ints2[4];

        printf("\n\n");
        for(int i = 0; i < 4; ++i) {
            ftr_sread_u32(&seeker2, &broke_ints2[i]);
            ints2[i] = ftr_assemble_u32b(&broke_ints2[i]);
            printf("%i\n", ints[i]);
        }

        // Let's view what was logged

        for(int i = 0; i < logger->size; ++i) {
            if(logger->entries[i].entry_name) {
                printf("Log[%i]\n", i);
                printf(logger->entries[i].entry_name);
            }
        }

        ftr_free_logger(logger);
    }

    return 0;
}


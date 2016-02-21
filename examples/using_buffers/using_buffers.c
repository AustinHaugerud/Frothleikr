#include"../../frothleikr.h"
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

    return 0;
}


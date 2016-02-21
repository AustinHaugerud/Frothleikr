#include<stdio.h>
#include"../../frothleikr.h"

int main(void) {

    /*
     * As long as your data has been properly broken down into
     * a byte by byte representation, you should have no
     * problem saving that array to a file
     *
     * You'll most likely want to use a buffer, but you're
     * by no means required to do so
     *
     * To demonstrate this, we'll write some data from a broke integer
     * and then we'll write some data from a buffer
     */ 


    {
 
        FILE * f = fopen("a.bin", "wb");

        ftr_u32 my_u32 = 4000;

        printf("Single int val: %i\n", my_u32);

        struct ftr_brokeu32 my_broke_u32;

        ftr_break_u32b(my_u32,&my_broke_u32);

        fwrite(my_broke_u32.bytes, sizeof(ftr_u8), sizeof(ftr_u32), f);


        /*
        * Now we'll use a buffer, which is also very simple
        */

        struct ftr_io_buffer * buffer = ftr_create_buffer(0);

        // We'll create some data to throw in the buffer
        ftr_u32 my_ints[4] =  { 100, 200, 300, 400 };

        struct ftr_brokeu32 my_broke_ints[4];

        for(int i = 0; i < 4; ++i) {
            printf("Array[%i] = %i\n", i, my_ints[i]);
            ftr_break_u32b(my_ints[i], &my_broke_ints[i]);
            ftr_write_u32(buffer, &my_broke_ints[i], i * sizeof(ftr_u32));
        }

        // Now we can dump the entire buffers content to the file

        fwrite(buffer->data, sizeof(ftr_u8), buffer->size, f);

        ftr_free_buffer(buffer);

        fclose(f);

    }

    // Now we'll read the data back

    {
        FILE * f = fopen("a.bin","rb");

        ftr_u32 my_u32;
        struct ftr_brokeu32 my_brokeu32;

        fread(my_brokeu32.bytes, sizeof(ftr_u8), sizeof(ftr_u32), f);

        my_u32 = ftr_assemble_u32b(&my_brokeu32);

        printf("Read single int: %i\n", my_u32);

        /*
         * Now we'll read the buffer in one fell swoop
         * Take note of how the buffer is preallocated with the size of the array
         * If we forgot to do this, fread() would try to write to memory
         * we haven't allocated, and we'd then get a segfault
         */

        struct ftr_io_buffer * buffer = ftr_create_buffer(4 * sizeof(ftr_u32));
       
        fread(buffer->data, sizeof(ftr_u8), 4 * sizeof(ftr_u32), f);
        
        ftr_u32 my_ints[4];
        struct ftr_brokeu32 my_broke_ints[4];

        for(int i = 0; i < 4; ++i) { 
            ftr_read_u32(buffer, &my_broke_ints[i], i * sizeof(ftr_u32));
            my_ints[i] = ftr_assemble_u32b(&my_broke_ints[i]);  
            printf("Read Array[%i] = %i\n", i, my_ints[i]);
        }
    }
    
    return 0;
}


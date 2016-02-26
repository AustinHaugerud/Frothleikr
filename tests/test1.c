#include<frothleikr.h>
#include<stdlib.h>
#include<stdio.h>

int main() {

    const ftr_u64 buffer_size = 1000;

    { 
        ftr_u32 * integers = malloc(sizeof(ftr_u32) * buffer_size);

        struct ftr_io_buffer * buffer = ftr_create_buffer(buffer_size * sizeof(ftr_u32));
        struct ftr_io_buffer_seeker seeker;

        ftr_init_seeker(buffer, &seeker, "w");

        for(int i = 0; i < buffer_size; ++i) {
            integers[i] = i;
            struct ftr_brokeu32 bu32;
            ftr_break_u32b(integers[i], &bu32);
            ftr_swrite_u32(&seeker, &bu32);
        }

        FILE * f = fopen("out.bin","w");

        fwrite(buffer->data, buffer->size,1,f);

        free(integers);
        ftr_free_buffer(buffer);
    }

    {
        struct ftr_io_buffer * buffer = ftr_create_buffer(buffer_size * sizeof(ftr_u32));
        FILE * f = fopen("out.bin", "r");

        fread(buffer->data,buffer_size * sizeof(ftr_u32),1,f);

        struct ftr_io_buffer_seeker seeker;
        ftr_init_seeker(buffer, &seeker, "r");

        ftr_u32 * integers = malloc(sizeof(ftr_u32) * buffer_size);

        for(int i = 0; i < buffer_size; ++i) {
            struct ftr_brokeu32 bu32;
            ftr_sread_u32(&seeker, &bu32);
            integers[i] = ftr_assemble_u32b(&bu32);
            printf("%i\n",integers[i]);
        }

        free(integers);
        ftr_free_buffer(buffer);

    }

    return 0;
}


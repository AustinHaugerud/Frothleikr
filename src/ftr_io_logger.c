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



#include<ftr_io_logger.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct ftr_io_logger * ftr_create_logger(void) {

    struct ftr_io_logger * logger;

#ifdef __cplusplus
    logger = (struct ftr_io_logger*)malloc(sizeof(struct ftr_io_logger));
#else
    logger = malloc(sizeof(struct ftr_io_logger));
#endif

    logger->size = 0;
    logger->alloc_size;
    logger->entries = 0;

}

void ftr_free_logger(struct ftr_io_logger * logger) {

    for(ftr_u64 i = 0; i < logger->size; ++i) {
        free(logger->entries[i].entry_name);
    }
    free(logger->entries);
    free(logger);
}

void ftr_log_entry(struct ftr_io_logger * logger, const char * name) {

    logger->size++;

    if(logger->entries == 0) {

    #ifdef __cplusplus
        logger->entries = (struct ftr_io_log_entry*)malloc(
                sizeof(struct ftr_io_log_entry));
    #else
        logger->entries = malloc(sizeof(struct ftr_io_log_entry));
    #endif

    }

    
    struct ftr_io_log_entry * en 
        = realloc(logger->entries, logger->size * 
            sizeof(struct ftr_io_log_entry));
    if(en)
        logger->entries = en; 

    char * entry_name;

#ifdef __cplusplus
    entry_name = (char*)malloc(strlen(name));
#else
    entry_name = malloc(strlen(name));
    //printf("str C-alloc %i \n", strlen(name));
#endif

    logger->entries[logger->size-1].entry_name
        = memcpy(entry_name, name, strlen(name));
    logger->entries[logger->size-1].range = 1;
}


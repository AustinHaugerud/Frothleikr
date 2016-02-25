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
        //printf("CPP-alloc");
    #else
        logger->entries = malloc(sizeof(struct ftr_io_log_entry));
        //printf("C-alloc\n");
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
}

void FTR_API ftr_compress_log(struct ftr_io_logger * logger) {

}


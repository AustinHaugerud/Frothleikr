#include"ftr_util.h"
#include<stdint.h>

int ftr_is_bendian(void) {

    union {
        uint32_t i;
        char c[4];
    } be_int = {0x01020304};

    return be_int.c[0] == 1;
}

int ftr_is_lendian(void) {
    return (!ftr_is_bendian());
}


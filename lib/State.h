#ifndef _STATE_H_
#define _STATE_H_
#include <stdint.h>

typedef struct {
    uint32_t id;
    char* name;
    double value;
    int percentage;
} State;
#endif

#ifndef FLICK_H
#define FLICK_H

#include <stdint.h>
#include <stdbool.h>

#include "matrix.h"


typedef enum {
    FLICK_DIR_NONE   = 0,
    FLICK_DIR_UP     = DIR_UP,
    FLICK_DIR_DOWN   = DIR_DOWN,
    FLICK_DIR_LEFT   = DIR_LEFT,
    FLICK_DIR_RIGHT  = DIR_RIGHT,
} FlickDirection;

void flickInit();

void flickProcess();

#endif

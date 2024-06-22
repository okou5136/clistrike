#ifndef DRAW_H
#define DRAW_H

#include <ncurses.h>
#include "data.h"

typedef enum DrawDirection {
    Vertical,
    Horizontal,
} DrawDirection;

void draw_line(WINDOW * win, POSITION pos, DrawDirection direct, int x_length, int y_length);

void render(WINDOW * win, OBJ ** object, int delta);


#endif

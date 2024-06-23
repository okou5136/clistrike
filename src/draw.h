#ifndef DRAW_H
#define DRAW_H

#include <ncurses.h>
#include "data.h"

typedef enum DrawDirection {
    Vertical,
    Horizontal,
} DrawDirection;

//void draw_line(WINDOW * win, COORDINATE pos, DrawDirection direct, int x_length, int y_length);

// function for drawing object log
void draw_log(WINDOW * win, OBJ * object[], int maxline);

void render(WINDOW * win, OBJ * object[], int delta);


#endif

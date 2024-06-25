#ifndef DRAW_H
#define DRAW_H

#include <ncurses.h>
#include "data.h"

// the reason why x and y length are not defined as COORDINATE is these variables are most likely set manually.
void draw_line(WINDOW * win, OBJ object, COORDINATE max);

// function for drawing object log
void draw_log(WINDOW * win, OBJ * object[], COORDINATE max);

/*void render(WINDOW * win, OBJ * object[], int delta);*/


#endif

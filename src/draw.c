#include <ncurses.h>
#include "draw.h"
#include "data.h"

void draw_line(WINDOW * win, COORDINATE pos, DrawDirection direct, int x_length, int y_length, COORDINATE max) {
}

void draw_log(WINDOW * win, OBJ * object[], COORDINATE max) {

    printw("MAX-X: %d\nMAX-Y: %d\n", max.x, max.y);
    
    for(int i = 0; object[i] != NULL; i++) {
        mvprintw(max.y - 1 - i, 0, "objnumber[%d]: braille position[%d][%d], cell position[%d][%d]", 
                i,
                object[i] -> position.x % BTABLEH,
                object[i] -> position.y % BTABLEV,
                object[i] -> position.x / BTABLEH,
                object[i] -> position.y / BTABLEV
                );
    }
}
/**/
/*void render(WINDOW * win, OBJ * objects[], int delta) {*/
/*}*/

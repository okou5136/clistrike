#include <ncurses.h>
#include "draw.h"
#include "data.h"

/*void draw_line(WINDOW * win, OBJ pos, DrawDirection direct, int x_length, int y_length) {*/
/*    int y_max, x_max = 0;*/
/**/
/*    getmaxyx(win, y_max, x_max);*/
/**/
/*}*/

void draw_log(WINDOW * win, OBJ * object[], int maxline) {
    for(int i = 0; object[i] != NULL; i++) {
        mvprintw(maxline - 1 - i, 0, "objnumber[%d]: braille position[%d][%d], cell position[%d][%d]", 
                i,
                object[i] -> position.x % BTABLEH,
                object[i] -> position.y % BTABLEV,
                object[i] -> position.x / BTABLEH,
                object[i] -> position.y / BTABLEV
                );
    }
}

void render(WINDOW * win, OBJ * objects[], int delta) {
    int y_max, x_max;
    int i = 0;

    getmaxyx(win, y_max, x_max);

}

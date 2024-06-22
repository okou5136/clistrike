#include <ncurses.h>
#include "draw.h"
#include "data.h"

void draw_line(WINDOW * win, OBJ pos, DrawDirection direct, int x_length, int y_length) {
    int y_max, x_max = 0;

    getmaxyx(win, y_max, x_max);

}


void render(WINDOW * win, OBJ * objects[], int delta) {
    int y_max, x_max;
    int i = 0;

    getmaxyx(win, y_max, x_max);

    for(i = 0; i < sizeof(objects); i++) {
        *objects[i].
    }
}

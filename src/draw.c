#include <ncurses.h>
#include "draw.h"
#include "data.h"

// matrix table for calculating brailles.
// look https://en.wikipedia.org/wiki/Braille_Patterns#Identifying,_naming_and_ordering
const int braille_table[BTABLEH][BTABLEV] = {
    {
        0x1, // top left
        0x2, 
        0x4,
        0x40, //bottom left 
    },
    {
        0x8, // top right
        0x10,
        0x20,
        0x80, // bottom right
    }
};

void draw_line(WINDOW * win, OBJ object, COORDINATE max) {
    int i = 0;

    for(i = 0; object.size.x > i; i++) {
        mvwprintw(win, object.position.y / BTABLEV,
                 object.position.x / BTABLEH,
                 "%lc",
                 (BOFFSET + braille_table[object.position.x % BTABLEH][object.position.y % BTABLEV])
                 );
    }
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

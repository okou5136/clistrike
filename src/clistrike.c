#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

// header files for unicode support. needed to render brailles.
#include <wchar.h>
#include <locale.h>

#include "data.h"

// offset for the brailles
#define BOFFSET 0x2800 
#define BTABLEH 2
#define BTABLEV 4

int main(int argc, char ** argv) {

    // nescessary for the unicode character to be correctly rendered
    setlocale(LC_ALL, "");
        
    // create variables for maximum screen size
    int maxline, maxcol;

    // struct that contains the current position
    // for further information, look data.h/.c
    POSITION current_position = {
        0,
        0,
    };


    int i = 0;
    int j = 0;

    int character;

    // matrix table for calculating brailles.
    // look https://en.wikipedia.org/wiki/Braille_Patterns#Identifying,_naming_and_ordering
    int braille_table[BTABLEH][BTABLEV] = {
        {
            0x1,
            0x2,
            0x4,
            0x40,
        },
        {
            0x8,
            0x10,
            0x20,
            0x80,
        }
    };

    // initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    clear();
    getmaxyx(stdscr, maxline, maxcol);

    printw("MAX-Y: %d\nMAX-X: %d\n", maxcol, maxline);

    current_position.x = (maxcol - 1) / 2;
    current_position.y = (maxline - 1)  / 2;

    while(i == 0) {
        getmaxyx(stdscr, maxline, maxcol);
        printw("MAX-Y: %d\nMAX-X: %d\n", maxcol, maxline);

        character = getch();

        switch(character) {
            case 'q':
                printw("ended...\npress any key to end.");
                i = 1;
                break;
            case 'r':
                printw("continue...\n");
                break;
            case 'd':
                if((current_position.x + 1) / BTABLEH >= maxcol)
                    break;
                current_position.x++;
                break;
            case 'a':
                if((current_position.x - 1) / BTABLEH <= 0) 
                    break;
                current_position.x--;
                break;
            case 's':
                if((current_position.y + 1) / BTABLEV >= maxline)
                    break;
                current_position.y++;
                break;
            case 'w':
                if((current_position.y - 1) / BTABLEV <= 0) 
                    break;
                current_position.y--;
                break;
        }

        mvprintw(
                current_position.y  / BTABLEV,
                current_position.x  / BTABLEH,
                "%lc",
                (BOFFSET +
                    braille_table[current_position.x % BTABLEH][current_position.y % BTABLEV]
                    ));

        mvprintw(maxline - 1, 0, "current main braille[%d][%d]", current_position.x % BTABLEH, current_position.y % BTABLEV);
        mvprintw(maxline - 2, 0, "current main cell[%d][%d]", current_position.x / BTABLEH, current_position.y / BTABLEV);
        refresh();

        move(0, 0);
    }


    getch();
    endwin();

    return 0;
}

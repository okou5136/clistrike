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


    // pointer for storing objects and its counter
    int objcounter = 0;
    OBJ * objpoint[100];

    // struct that contains the current position
    // for further information, look data.h/.c
    OBJ player = {
        {
            0,
            0,
        }, // field for size
        {
            0,
            0,
        }, // field for position
    };


    objpoint[objcounter] = &player;
    objcounter++;


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

    player.position.x = (maxcol - 1) / 2;
    player.position.y = (maxline - 1)  / 2;
    player.size.x = 1;
    player.size.y = 1;

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
                if((player.position.x + player.size.x) / BTABLEH >= maxcol)
                    break;
                player.position.x++;
                break;
            case 'a':
                if((player.position.x - player.size.x) / BTABLEH <= 0) 
                    break;
                player.position.x--;
                break;
            case 's':
                if((player.position.y + player.size.y) / BTABLEV >= maxline)
                    break;
                player.position.y++;
                break;
            case 'w':
                if((player.position.y - player.size.y) / BTABLEV <= 0) 
                    break;
                player.position.y--;
                break;
        }

        clear();

        for(i = 0; i <= objcounter; i++) {
            mvprintw(maxline - i, 0, "objnumber[%d]: braille position[%d][%d], cell position[%d][%d]", 
                    i,
                    objpoint[i] -> position.x % BTABLEH,
                    objpoint[i] -> position.y % BTABLEV,
                    objpoint[i] -> position.x / BTABLEH,
                    objpoint[i] -> position.y / BTABLEV
                    );
        }

        refresh();

        move(0, 0);
    }

    getch();
    endwin();

    return 0;
}

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// header files for unicode support. needed to render brailles.
#include <wchar.h>
#include <locale.h>

#include "data.h"
#include "draw.h"
#include "error.h"
#include "opt.h"


int main(int argc, char ** argv) {

    // nescessary for the unicode character to be correctly rendered
    setlocale(LC_ALL, "");

    // create variables for maximum screen size
    COORDINATE  max;

    int i = 0;
    int j = 0;


    OPTION arg = parsearg(argc, argv);

    // pointer for storing objects and its counter
    int objcounter = 0;
    OBJ * objpoint[100] = {NULL};

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

    int character;

    // matrix table for calculating brailles.
    // look https://en.wikipedia.org/wiki/Braille_Patterns#Identifying,_naming_and_ordering
    int braille_table[BTABLEH][BTABLEV] = {
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

    // initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    clear();
    getmaxyx(stdscr, max.y, max.x);

    player.position.x = (max.x - 1) / 2;
    player.position.y = (max.y - 1)  / 2;
    player.size.x = 1;
    player.size.y = 1;


    if(arg.bitopt.debug) {
        draw_log(stdscr, objpoint, max);
    }

    while(i == 0) {
        getmaxyx(stdscr, max.y, max.x);

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
                if((player.position.x + player.size.x) / BTABLEH >= max.x)
                    break;
                player.position.x++;
                break;
            case 'a':
                if((player.position.x - player.size.x) / BTABLEH <= 0) 
                    break;
                player.position.x--;
                break;
            case 's':
                if((player.position.y + player.size.y) / BTABLEV >= max.y)
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

        if(arg.bitopt.debug) {
            draw_log(stdscr, objpoint, max);
        }


        refresh();

        move(0, 0);
    }

    getch();
    endwin();

    return 0;
}

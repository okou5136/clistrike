#include <stdio.h>
#include <errno.h>

#include "error.h"
#include "data.h"

void print_help(int depth) {
    if(depth >= 2) {
        puts("AUTHOR: ");
        puts("DESCRIPTION: simple game implemented in c \n");
    }
    if(depth >= 1) {
        puts("USAGE: clistrike [OPTION]");
    }
    if(depth >= 2) {
        puts("\nOPTION:");
        indent("-d: activate debug mode", 1);
        indent("    this option displays screen size and information on each object", 1);
    }
}

void indent(const char * character, int depth) {
    for(int i = 0; i <= depth; i++)
        printf("   ");

    printf("%s\t\n", character);
}

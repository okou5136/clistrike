#include <stdlib.h>
#include <string.h>
#include "opt.h"
#include "error.h"
#include "data.h"

OPTION parsearg(int argc, char ** argv) {

    OPTION result = {
        {False},
    };
    for(int i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "-h")) {
            print_help(0);
            exit(0);
        }
        else if(!strcmp(argv[i], "-d")) {
            result.bitopt.debug = True;
        }
    }
    return result;
}

#ifndef OPT_H
#define OPT_H

#include "data.h"

typedef struct BitOpt {
   BOOL debug;
} BitOpt;

typedef struct Option {
    BitOpt bitopt;
} OPTION;

OPTION parsearg(int argc, char ** argv);

#endif

#include "data.h"

typedef struct PositionComp {
    int braille;
    int global;
} PCOMPONENT;

struct PositionStruct {
    PCOMPONENT x;
    PCOMPONENT y;
};

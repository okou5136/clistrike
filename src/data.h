#ifndef DATA_H
#define DATA_H

// BOFFSET is short for Braille OFFSET. (all the braille characters defined on Unicode begin with 0x28xx)
#define BOFFSET 0x2800

// Braille TABLE Horizontal/Vertical. Dimention of a braille character
#define BTABLEH 2
#define BTABLEV 4

typedef enum BOOL {
    False = 0,
    True
} BOOL;

// it's not exactly a coordinate but just a set of X and Y.
// implemented this because sometime it's convinient to pass them as a whole.
typedef struct CoordinateStruct {
    int x;
    int y;
} COORDINATE;

typedef struct Object {
    COORDINATE size;

    COORDINATE position; // position on the screen
} OBJ;

#endif


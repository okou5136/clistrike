#ifndef DATA_H_
#define DATA_H_

#define BOFFSET 0x2800
#define BTABLEH 2
#define BTABLEV 4

typedef enum BOOL {
    False = 0,
    True
} BOOL;


typedef struct CoordinateStruct {
    int x;
    int y;
} COORDINATE;

typedef struct Object {
    COORDINATE size;

    COORDINATE position;
} OBJ;


#endif


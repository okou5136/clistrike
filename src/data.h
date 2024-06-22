#ifndef DATA_H_
#define DATA_H_

typedef struct CoordinateStruct {
    int x;
    int y;
} COORDINATE;

typedef struct Object {
    COORDINATE size;

    COORDINATE position;
} OBJ;


#endif


CC = gcc
CFLAGS = 
SOURCES = ./src/clistrike.c
DESTINATION = ./exe/clistrike

all: comp run clean

comp:
    $(CC) $(SOURCES) -o $(DESTINATION)
run:
    $(DESTINATION)
clean:
    rm $(DESTINATION)



CC=gcc
CFLAGS=-Wall -O3 -std=gnu99 -fomit-frame-pointer -pipe -march=native
#CFLAGS=-Wall -std=gnu99 -g
LINKER_FLAGS=

all: 
    $(CC) $(CFLAGS) -o deck deck.c $(LINKER_FLAGS)

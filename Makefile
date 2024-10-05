all: main

PROJECT_NAME = target_Sistemas
CC=gcc
SRC_DIR = ./src
LIB_DIR = ./lib

PKG_CFLAGS = $(shell pkg-config --cflags libxml-2.0) -lm
PKG_LIBS = $(shell pkg-config --libs libxml-2.0) -lm

$(PROJECT_NAME): main

main: main.c
	$(CC) -I$(LIB_DIR) $(PKG_CFLAGS) -o $@ $< $(PKG_LIBS)
main-debug: main.c
	$(CC) -I$(LIB_DIR) $(PKG_CFLAGS) -o $@ $< $(PKG_LIBS)

clean:
	rm -f main main-debug
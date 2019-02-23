CC=gcc
CFLAGS=-c -Wall
DEBUG_FLAGS=-c -g -Wall

all: wc

wc: wc.o
	$(CC) wc.o -o wc 

map: map.o
	$(CC) map.o -o map

main: main.o
	$(CC) main.o -o main

wc-debug: wc-debug.o
	$(CC) wc.o -o wc-debug

map.o: map.c
	$(CC) $(CFLAGS) map.c

wc.o: wc.c
	$(CC) $(CFLAGS) wc.c

wc-debug.o: wc.c
	$(CC) $(DEBUG_FLAGS) wc.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *o wc
	rm *o map
	rm *o main
	
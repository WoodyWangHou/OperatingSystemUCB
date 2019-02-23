CC=gcc
CFLAGS=-c -Wall
DEBUG_FLAGS=-c -g -Wall

all: wc

wc: wc.o
	$(CC) wc.o -o wc 

wc-debug: wc-debug.o
	$(CC) wc.o -o wc-debug

wc.o: wc.c
	$(CC) $(CFLAGS) wc.c

wc-debug.o: wc.c
	$(CC) $(DEBUG_FLAGS) wc.c

clean:
	rm *o wc
	
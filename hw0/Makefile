CC=gcc
CFLAGS=-c -Wall

all: wc

wc: wc.o
	$(CC) wc.o -o wc 

wc.o: wc.c
	$(CC) $(CFLAGS) wc.c

clean:
	rm *o wc
	
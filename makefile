CC=gcc
CFLAGS=-g -Wall
OBJS=main.o Board.o CollSprite.o MatxSprite.o

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses
	./main

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o main
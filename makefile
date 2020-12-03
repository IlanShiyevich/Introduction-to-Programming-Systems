CC = gcc
FLAGS = -Wall -g
AR = ar -rcs

all: mains

mains: main.o libMyBank.a
	$(CC) $(FLAGS) -o mains main.o libMyBank.a

libMyBank.a: myBank.o
	$(AR) libMyBank.a myBank.o

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: all clean

clean:
	rm -f *.o *.a mains

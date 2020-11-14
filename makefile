AR=ar
CC=gcc

all: progmaind progmains

progmaind: main.o libmyMath.so
		$(CC)  -o progmaind main.o ./libmyMath.so
progmains: main.o libmyMath.a
		$(CC)  -o progmains main.o ./libmyMath.a
libmyMath.so: basicMath.o power.o
		$(CC) -shared -o libmyMath.so basicMath.o power.o
libmyMath.a: basicMath.o power.o
		$(AR) -rcs libmyMath.a basicMath.o power.o


main.o: main.c myMath.h
		$(CC)  -c main.c
			
basicMath.o: basicMath.c
		$(CC)  -c basicMath.c

power.o: power.c
		$(CC)  -c power.c



.PHONY: clean

clean: 
		rm -f *.o progmaind progmains *.a *.so

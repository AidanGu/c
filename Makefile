CC = clang

sqrt_main: sqrt_main.o sqrt_lib.o
	$(CC) sqrt_main.o sqrt_lib.o -o sqrt_main

sqrt_main.o: sqrt_main.c sqrt_lib.h
	$(CC) -c sqrt_main.c

sqrt_lib.o: sqrt_lib.c sqrt_lib.h
	$(CC) -c sqrt_lib.c

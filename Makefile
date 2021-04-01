main: main.c
	gcc -o main main.c -pedantic -ansi -lm 

test: main.c test.c  
	gcc -o test main.c test.c -pedantic -ansi -lm -DTEST

all: main.c test.c
	gcc -o main main.c -pedantic -ansi -lm 
	gcc -o test main.c test.c -pedantic -ansi -lm -DTEST
all: main.c 
	gcc -o task1 main.c 

test: test.c calculator.c
	gcc -o test_tas1 test.c calculator.c
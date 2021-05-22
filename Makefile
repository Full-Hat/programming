all: main.c calculator.c
	gcc -o task1 main.c calculator.c 
test: test.c calculator.c
	gcc -o task1_test test.c calculator.c

all: main.c stringStack.c stackStack.c
	gcc -o analyzer main.c stringStack.c stackStack.c -std=c89

test: test.c stringStack.c stackStack.c
	gcc -o test test.c stringStack.c stackStack.c -std=c89 
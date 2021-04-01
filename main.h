#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>

int** createKeyHole(int y, int x, int stdValue);
void freeKeyHole(int** keyHole, int y, int x);
void printKeyHole(int** keyHole, int y, int x);
int checkAria(int xFrom, int yFrom, int** key, int xK, int yK, int** keyHole);
int checkHole(int** keyHole, int xH, int yH, int** key, int xK, int yK);

#endif
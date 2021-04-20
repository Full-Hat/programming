#include "main.h"
#include <stdlib.h>

int** createKeyHole(int x, int y, int stdValue)
{
    int** keyHole;

    int i;
    int ind;
    keyHole = (int**)malloc(x * sizeof(int*));
    for(i = 0; i < x; ++i)
    {
        keyHole[i] = (int*)malloc(y*sizeof(int));
        for(ind = 0; ind < y; ++ind)
        {
            keyHole[i][ind] = stdValue;
        }
    }

    return keyHole;
}

void freeKeyHole(int** keyHole, int x, int y)
{
    int i;
    for(i = 0; i < x; ++i)
    {
        free(keyHole[i]);
    }
    free(keyHole);
}

void printKeyHole(int** keyHole, int x, int y)
{
    int xI, yI;
    for(xI = 0; xI < x; ++xI)
    { 
        for(yI = 0; yI < y; ++yI)
        {
            printf("%d ", keyHole[xI][yI]);
        }
        printf("\n");
    }
}

int checkAria(int xFrom, int yFrom, int** key, int xK, int yK, int** keyHole)
{
    int checker = 0;
    int xI, yI;
    int kxI = 0, kyI = 0;
    for(xI = xFrom, kxI = 0; kxI < xK; ++xI, ++kxI)
    {
        for(yI = yFrom, kyI = 0; kyI < yK; ++yI, ++kyI)
        {
            if(key[kxI][kyI] == 1 && keyHole[xI][yI] != 0)
            {
                checker = 1;
                break;
            }
        }

        if(checker == 1) { break; }
    }
    if(checker == 0) { return 1; }

    checker = 0;
    for(xI = xFrom, kyI = 0; kyI < yK; ++xI, ++kyI)
    {
        for(yI = yFrom, kxI = xK - 1; kxI >= 0; ++yI, --kxI)
        {
            if(key[kxI][kyI] == 1 && keyHole[xI][yI] != 0)
            {
                checker = 1;
                break;
            }
        }

        if(checker == 1) { break; }
    }
    if(checker == 0) { return 1; }

    checker = 0;
    for(xI = xFrom, kxI = xK - 1; kxI >= 0; ++xI, --kxI)
    {
        for(yI = yFrom, kyI = yK - 1; kyI >= 0; ++yI, --kyI)
        {
            if(key[kxI][kyI] == 1 && keyHole[xI][yI] != 0)
            {
                checker = 1;
                break;
            }
        }

        if(checker == 1) { break; }
    }
    if(checker == 0) { return 1; }

    checker = 0;
    for(xI = xFrom, kyI = yK - 1; kyI >= 0; ++xI, --kyI)
    {
        for(yI = yFrom, kxI = 0; kxI < xK; ++yI, ++kxI)
        {
            if(key[kxI][kyI] == 1 && keyHole[xI][yI] != 0)
            {
                checker = 1;
                break;
            }
        }

        if(checker == 1) { break; }
    }
    if(checker == 0) { return 1; }

    return 0;
}

int checkHole(int** keyHole, int xH, int yH, int** key, int xK, int yK)
{
    int xInd = 0, yInd = 0;
    for(xInd = 0; xInd < xH - xK + 1; ++xInd)
    {
        for(yInd = 0; yInd < yH - yK + 1; ++yInd)
        {
            if(checkAria(xInd, yInd, key, xK, yK, keyHole))
            {
                return 1;
            }
        }
    }

    return 0;
} 

void readHole(int*** hole, int *xOut, int *yOut, char fileName[50])
{
    int data;
    int x = 0, y = 0;
    int xI = 0, yI = 0;
    FILE* fin;

    char buff[50];

    fin  = fopen(fileName, "r");

    fscanf(fin, "%d%d", &x, &y);
    (*hole) = createKeyHole(x, y, 0);
    printf("Create hole: %d, %d\n\n", x, y);

    for(xI = 0; xI < x; ++xI)
    {
        for(yI = 0; yI < y && fscanf(fin, "%d", &data) != EOF; ++yI)
        {
            (*hole)[xI][yI] = data;
        }
    }

    *xOut = x;
    *yOut = y;
}

#ifndef TEST
int main()
{
    int xH, yH;
    int**keyHole, **key;
    int xK, yK;

    readHole(&keyHole, &xH, &yH, "hole_data.txt");
    readHole(&key, &xK, &yK, "keyhole_data.txt");

    printf("\nKey hole: \n");
    printKeyHole(keyHole, xH, yH);
    printf("\nKey: \n");
    printKeyHole(key, xK, yK);


    printf("\n\n");
    printf("%s open!", checkHole(keyHole, xH, yH, key, xK, yK) == 0 ? "Can't" : "Can");

    freeKeyHole(keyHole, xH, yH);
    freeKeyHole(key, xK, yK);
    return 0;
}
#endif
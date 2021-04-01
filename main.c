#include "main.h"

int** createKeyHole(int y, int x, int stdValue)
{
    int** keyHole;

    int i;
    int ind;
    keyHole = (int**)malloc(y * sizeof(int*));
    for(i = 0; i < y; ++i)
    {
        keyHole[i] = (int*)malloc(x*sizeof(int));
        for(ind = 0; ind < x; ++ind)
        {
            keyHole[i][ind] = stdValue;
        }
    }

    return keyHole;
}

void freeKeyHole(int** keyHole, int y, int x)
{
    int i;
    for(i = 0; i < y; ++i)
    {
        free(keyHole[i]);
    }
    free(keyHole);
}

void printKeyHole(int** keyHole, int y, int x)
{
    int xI, yI;
    for(xI = 0; xI < y; ++xI)
    { 
        for(yI = 0; yI < x; ++yI)
        {
            printf("%d ", keyHole[xI][yI]);
        }
        printf("\n");
    }
}

int checkAria(int xFrom, int yFrom, int** key, int xK, int yK, int** keyHole)
{
    int xI, yI;
    for(xI = xFrom; xI < xK; ++xI)
    {
        for(yI = yFrom; yI < yK; ++yI)
        {
            if(key[xI][yI] == 1 && keyHole[xI][yI] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int checkHole(int** keyHole, int xH, int yH, int** key, int xK, int yK)
{
    int xInd = 0, yInd = 0;
    for(; xInd < xH - xK; ++xInd)
    {
        for(; yInd < yH - yK; ++yInd)
        {
            if(checkAria(xInd, yInd, key, xK, yK, keyHole))
            {
                return 1;
            }
        }
    }

    xInd = xH - xK - 1; 
    yInd = 0;
    for(; xInd >= 0; --xInd)
    {
        for(; yInd < yH - yK; ++yInd)
        {
            if(checkAria(xInd, yInd, key, xK, yK, keyHole))
            {
                return 1;
            }
        }
    }

    xInd = 0; 
    yInd = yH - yK - 1;
    for(; xInd < xH - xK; ++xInd)
    {
        for(; yInd >= 0; --yInd)
        {
            if(checkAria(xInd, yInd, key, xK, yK, keyHole))
            {
                return 1;
            }
        }
    }

    xInd = xH - xK - 1; 
    yInd = yH - yK - 1;
    for(; xInd >= 0; --xInd)
    {
        for(; yInd >= 0; --yInd)
        {
            if(checkAria(xInd, yInd, key, xK, yK, keyHole))
            {
                return 1;
            }
        }
    }

    return 0;
}

#ifndef TEST
int main()
{
    int xH, yH;
    int**keyHole, **key;
    int xK, yK;

    printf("Enter hole size: ");
    scanf("%d%d", &xH, &yH);
    keyHole = createKeyHole(yH, xH, 0);
    printf("Enter key size: ");
    scanf("%d%d", &xK, &yK);
    key = createKeyHole(yK, xK, 1);
    
    keyHole[3][3] = 1;
    keyHole[2][2] = 1;
    keyHole[2][1] = 1;
    key[2][1] = 0;
    key[2][2] = 0;
    key[1][0] = 0;

    printf("\nKey hole: \n");
    printKeyHole(keyHole, yH, xH);
    printf("\nKey: \n");
    printKeyHole(key, yK, xK);


    printf("\n\n");
    printf("%s open!", checkHole(keyHole, xH, yH, key, xK, yK) == 0 ? "Can't" : "Can");

    freeKeyHole(keyHole, yH, xH);
    freeKeyHole(key, yK, xK);
    return 0;
}
#endif
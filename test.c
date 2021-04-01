#include "main.h"  

#include <assert.h>

int main()
{
    const int xK = 3;
    const int yK = 3;
    const int xH = 5; 
    const int yH = 5;
    int** keyHole = createKeyHole(yH, xH, 0);
    int** key = createKeyHole(yK, xK, 1);
    keyHole[3][3] = 1;
    keyHole[2][2] = 1;
    keyHole[2][1] = 1;
    key[2][1] = 0;
    key[2][2] = 0;
    key[1][0] = 0;
    
    assert(checkHole(keyHole, xH, yH, key, xK, yK) == 1);

    freeKeyHole(keyHole, yH, xH);
    freeKeyHole(key, yK, xK);

    printf("Test passed successfully!");

    return 0;
}
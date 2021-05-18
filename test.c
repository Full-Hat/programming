#include "utils.h"
#include "stringStack.h"
#include "stackStack.h"

#include <assert.h>
#include <stdio.h>


int main()
{
    /*  TEST 1
    Test utils functions: 
    1) isAnagrams(const char*, const char*) -- must return 1 if args are anagrams, else return 0
    */ 
    assert(isAnagrams("1234", "1234"));
    assert(isAnagrams("1324", "1234"));
    assert(!isAnagrams("1234", "12345"));
    assert(!isAnagrams("12345", "1234"));
    assert(!isAnagrams("12345", "12343"));
    assert(isAnagrams("12345", "54321"));
    printf("Utils test \t\t:: status :: \tOK\n");

    /*  TEST 2
    Test stack functions:
    */ 
    struct StringStack s;  
    initss(&s);
    pushss(&s, "Hello world");  
    assert(strcmp(peekss(&s), "Hello world") == 0);
    assert(sizess(&s) == 1); 
    pushss(&s, "You are well :D");
    assert(sizess(&s) == 2); 
    assert(strcmp(popss(&s), "You are well :D") == 0);
    assert(sizess(&s) == 1);
    clearss(&s);
    assert(sizess(&s) == 0);
    printf("StringStack test \t:: status :: \tOK\n");

    pushss(&s, "Hello world!");

    struct StackStack ss;

    initst(&ss);
    pushst(&ss, &s);  
    assert(strcmp(peekss(peekst(&ss)), "Hello world!") == 0);
    assert(sizest(&ss) == 1);  
    struct StringStack s1;
    initss(&s1);
    pushss(&s1, "Hello world!");
    pushss(&s1, "You are well :D");
    pushst(&ss, &s1);
    assert(sizest(&ss) == 2);
    assert(strcmp(popss(popst(&ss)), "You are well :D") == 0);
    assert(strcmp(peekss(peekst(&ss)), "Hello world!") == 0);
    assert(sizest(&ss) == 1); 
    clearst(&ss);
    assert(sizest(&ss) == 0); 
    printf("StackStack test \t:: status :: \tOK\n");

    /*  TEST 2
    Test text analyzer
    */
    

    printf("Test passes successfully!");
    return 0;
}
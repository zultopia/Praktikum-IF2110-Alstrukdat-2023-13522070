/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "wordmachine.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax) {
            currentWord.Length = NMax;
    }
    else {
        currentWord.Length = i;
    }
}
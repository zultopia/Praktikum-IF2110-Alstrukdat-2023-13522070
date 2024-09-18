/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "wordmachine.h"

// Prints word from Mesin Kata
int printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);
   }
}

int main() {
    Word word;
    int count = 0;
    int i = 0;
    START();
    IgnoreBlanks();
    while ((currentChar != MARK)) {
        word.TabWord[i] = currentChar;
        ADV();
        i++;
    } if(i > NMax) {
        word.Length = NMax;
    } else {
        word.Length = i;
    }
    count = word.Length;
    printWord(word);
    printf("\n");
    printf("%d\n",count);
}


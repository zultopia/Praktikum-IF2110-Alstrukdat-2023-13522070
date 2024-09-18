/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "wordmachine.h"
#include <stdio.h>

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

boolean compareWord(Word w1, Word w2) {
    int i;
    if (w1.Length < w2.Length) {
        for (i = 0; i < w1.Length; i++) {
            if (w1.TabWord[i] < w2.TabWord[i]) {
                return true;
            } else if (w1.TabWord[i] > w2.TabWord[i]) {
                return false;
            }
        }
        return true;
    } else {
        for (i = 0; i < w2.Length; i++) {
            if (w1.TabWord[i] < w2.TabWord[i]) {
                return true;
            } else if (w1.TabWord[i] > w2.TabWord[i]) {
                return false;
            }
        }
        return false;
    }
}

int main() {
    int i, j, k, count;
    Word words[100];
    i = 0;
    boolean sort;
    Word temp;
    
    STARTWORD();
    while (!EndWord) {
        words[i].Length = currentWord.Length;
        for (j = 0; j < currentWord.Length; j++) {
            words[i].TabWord[j] = currentWord.TabWord[j];
        }
        
        i++;
        ADVWORD();
    }

    sort = false;
    while (!sort) {
        sort = true;
        for (j = 0; j < i-1; j++) {
            if (compareWord(words[j+1], words[j])) {
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
                sort = false;
            }
        }
    }
    for (j = 0; j < i; j++) {
        printWord(words[j]);
        printf("\n");
    }
    return 0;
}
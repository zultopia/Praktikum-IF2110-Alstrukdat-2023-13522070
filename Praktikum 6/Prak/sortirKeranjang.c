/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "stack.h"

int lenStack (Stack s){
    int count = 0;
    int temp;
    if (IsEmpty(s)){
        return 0;
    }
    while (!IsEmpty(s)){
        Pop(&s,&temp);
        count++;
    }
    return count;
}

void SortirKeranjang (Stack * S1, Stack * S2){
    CreateEmpty(S2);
    int lengthS1 = lenStack(*S1);
    int temp[lengthS1];
    int i, val;
    for (i = 0; i < lengthS1; i++){
        Pop(S1, &val);
        temp[i]= val;
    }
    int j;
    for (i = 0; i < lengthS1; i++){
        for (j = 0; j < lengthS1 - i - 1; j++){
            if (temp[j] < temp[j+1]){
                int swap;
                swap = temp[j];
                temp[j]= temp[j+1];
                temp[j+1]= swap;
            }
        }
    }
    int rest;
    for (i = 0 ; i < lengthS1; i++){
        Push(S2, temp[i]);
        Pop (S1, &rest);
    }
}
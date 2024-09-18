/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "boolean.h"
#include "list_circular.h"

int main(){
    int N, i , j , step;
    Address playerNow, kiriCurrPemain, pemainOut;
    List l;
    CreateList(&l);
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        insertLast(&l, i + 1);
    }

    playerNow = FIRST(l);
    while (NEXT(playerNow) != FIRST(l)) {
        playerNow = NEXT(playerNow);
    }
    kiriCurrPemain = playerNow;
    playerNow = NEXT(kiriCurrPemain);

    i = 0;
    scanf("%d", &step);
    while(i < N - 1) {
        while(step < 0) {
            step += N - i;
        }
        for(j = 0; j < step; j++) {
            playerNow = NEXT(playerNow);
            kiriCurrPemain = NEXT(kiriCurrPemain);
        }
        NEXT(kiriCurrPemain) = NEXT(playerNow);
        pemainOut = playerNow;
        playerNow = NEXT(playerNow);
        deallocate(pemainOut);
        if(i < N - 2) {
            scanf("%d", &step);
            if(step > 0) {
                step--;
            }
        }
        i++;    
    }
    printf("%d\n", INFO(playerNow));
    return 0;
}
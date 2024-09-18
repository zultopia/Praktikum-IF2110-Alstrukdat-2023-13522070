/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik rumah, perjalanan;
    readList(&rumah);
    readList(&perjalanan);

    int i;
    insertFirst(&perjalanan,0);
    for (i = 0 ; i < listLength(perjalanan)-1 ; i++) {
        ELMT(perjalanan,i+1) += ELMT(perjalanan,i);
    }

    int truk1 = 0;
    int truk2 = 0;
    int truk3 = 0;
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;

    for (i = 0 ; i < listLength(rumah) ; i++) {
        if (ELMT(rumah, i) == 0) {
            continue;
        }
        else if (ELMT(rumah, i) == 1){
            truk1++;
            idx1 = i;
        }
        else if (ELMT(rumah, i) == 2){
            truk2++;
            idx2 = i;
        }
        else if (ELMT(rumah, i) == 3){
            truk3++;
            idx3 = i;
        }
    }
    int time1, time2, time3, totalTime;
    time1 = truk1 + ELMT(perjalanan,idx1)*2;
    time2 = truk2 + ELMT(perjalanan,idx2)*2;
    time3 = truk3 + ELMT(perjalanan,idx3)*2;

    totalTime = time1 + time2 + time3;
    printf("%d\n", totalTime);

    return 0;
}
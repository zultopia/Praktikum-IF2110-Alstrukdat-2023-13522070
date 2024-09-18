/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listdin.h"

void deleteFirst(ListDin *l, ElType *val) {
    int i;
    if(!(isEmpty(*l))) {
        *val = ELMT(*l, IDX_MIN);
        for (i = IDX_MIN; i<= getLastIdx(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        NEFF(*l) -= 1;
    }
}

int main() {
    ListDin tumpukan1,tumpukan2,tumpukanf;
    CreateListDin(&tumpukan1,100000);
    CreateListDin(&tumpukan2,100000);
    CreateListDin(&tumpukanf,100000);

    readList(&tumpukan1);
    readList(&tumpukan2);

    while (!isEmpty(tumpukan1) && !isEmpty(tumpukan2)) {
        int kartu1 = ELMT(tumpukan1, getFirstIdx(tumpukan1));
        int kartu2 = ELMT(tumpukan2, getFirstIdx(tumpukan2));

        if (kartu1 >= kartu2) {
            insertLast(&tumpukanf, kartu1);
            deleteFirst(&tumpukan1, &kartu1);
        } else {
            insertLast(&tumpukanf, kartu2);
            deleteFirst(&tumpukan2, &kartu2);
        }
    }

    // Menambahkan kartu yang tersisa jika ada
    while (!isEmpty(tumpukan1)) {
        int kartu1 = ELMT(tumpukan1, getFirstIdx(tumpukan1));
        insertLast(&tumpukanf, kartu1);
        deleteFirst(&tumpukan1, &kartu1);
    }

    while (!isEmpty(tumpukan2)) {
        int kartu2 = ELMT(tumpukan2, getFirstIdx(tumpukan2));
        insertLast(&tumpukanf, kartu2);
        deleteFirst(&tumpukan2, &kartu2);
    }
    printList(tumpukanf);
    printf("\n");
    return 0;
}
/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l1, l2, l;
    // Input elemen-elemen array pertama
    readList(&l1);

    // Input elemen-elemen array kedua
    readList(&l2);

    // Gabungkan dan urutkan array
    CreateListStatik(&l);

    // Salin elemen array pertama ke array gabungan
    for (int i = 0; i < listLength(l1); i++) {
        insertLast(&l, ELMT(l1, i));
    }

    // Salin elemen array kedua ke array gabungan
    for (int j = 0; j < listLength(l2); j++) {
        insertLast(&l, ELMT(l2, j));
    }

    // Urutkan array gabungan
    sortList(&l, 1);

    // Tampilkan array gabungan
    printList(l);
    printf("\n");
    return 0;
}

/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik array1, array2, hasil;
    
    CreateListStatik(&array1);
    CreateListStatik(&array2);
    CreateListStatik(&hasil);

    readList(&array1);
    readList(&array2);

    int carry = 0; // Carry bit
    int max_length = listLength(array1) > listLength(array2) ? listLength(array1) : listLength(array2);

    for (int i = 1; i <= max_length; i++) {
        int digit1 = 0, digit2 = 0;

        if (isIdxEff(array1, listLength(array1) - i)) {
            digit1 = ELMT(array1, listLength(array1) - i);
        }

        if (isIdxEff(array2, listLength(array2) - i)) {
            digit2 = ELMT(array2, listLength(array2) - i);
        }

        int sum = digit1 + digit2 + carry;
        carry = sum / 10; // Carry bit dihitung

        insertFirst(&hasil, sum % 10); // Sisa hasil penjumlahan dimasukkan ke array hasil
    }

    if (carry > 0) {
        insertFirst(&hasil, carry); // Menambahkan carry bit jika masih ada
    }
    printList(hasil);
    printf("\n");

    return 0;
}
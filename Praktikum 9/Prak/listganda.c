/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <stdlib.h>
#include "listganda.h"

/* Fungsi untuk membuat node baru */
Address newNode(ElType val) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = val;
        NEXT(P) = NULL;
        PREV(P) = NULL;
    }
    return P;
}

/* Fungsi untuk menciptakan list kosong */
void createListGanda(ListGanda *l) {
    CURRENT(*l) = NULL;
}

/* Fungsi untuk memeriksa apakah list kosong */
boolean isEmpty(ListGanda l) {
    return CURRENT(l) == NULL;
}

/* Fungsi untuk memeriksa apakah list terdiri dari satu elemen */
boolean isOneElement(ListGanda l) {
    return !isEmpty(l) && NEXT(CURRENT(l)) == CURRENT(l) && PREV(CURRENT(l)) == CURRENT(l);
}

/* Fungsi untuk menghitung panjang list */
int length(ListGanda l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        int count = 1;
        Address current = CURRENT(l);
        Address next = NEXT(current);
        while (next != CURRENT(l)) {
            count++;
            current = next;
            next = NEXT(current);
        }
        return count;
    }
}

/* Fungsi untuk memutar list sebanyak k langkah */
void rotate(ListGanda *l, int k) {
    if (!isEmpty(*l)) {
        if (k >= 0) {
            for (int i = 0; i < k; i++) {
                CURRENT(*l) = NEXT(CURRENT(*l));
            }
        } else {
            for (int i = 0; i < -k; i++) {
                CURRENT(*l) = PREV(CURRENT(*l));
            }
        }
    }
}

/* Fungsi untuk menyisipkan elemen setelah elemen yang ditunjuk saat ini */
void insertAfterCurrent(ListGanda *l, ElType x) {
    Address P = newNode(x);
    if (P != NULL) {
        if (isEmpty(*l)) {
            CURRENT(*l) = P;
            NEXT(P) = P;
            PREV(P) = P;
        } else {
            Address next = NEXT(CURRENT(*l));
            NEXT(P) = next;
            PREV(P) = CURRENT(*l);
            NEXT(CURRENT(*l)) = P;
            CURRENT(*l) = P;
            PREV(next) = P;
        }
    }
}

/* Fungsi untuk menghapus elemen yang ditunjuk saat ini */
void deleteCurrent(ListGanda *l, ElType *x) {
    if (!isEmpty(*l)) {
        *x = INFO(CURRENT(*l));
        if (isOneElement(*l)) {
            free(CURRENT(*l));
            createListGanda(l);
        } else {
            Address prev = PREV(CURRENT(*l));
            Address next = NEXT(CURRENT(*l));
            NEXT(prev) = next;
            PREV(next) = prev;
            free(CURRENT(*l));
            CURRENT(*l) = next;
        }
    }
}
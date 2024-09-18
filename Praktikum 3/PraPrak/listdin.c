/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */

void CreateListDin(ListDin *l, int capacity) {
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l) {
    if (NEFF(l) > 0) {
        return NEFF(l) - 1;
    } else {
        return IDX_UNDEF;
    }
}

/* ********** TEST INDICES ********** */

boolean isIdxValid(ListDin l, IdxType i) {
    return (i >= IDX_MIN) && (i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return (i >= IDX_MIN) && (i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */

boolean isEmpty(ListDin l) {
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l) {
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */

void readList(ListDin *l) {
   int n, i;
   scanf("%i", &n);
   while (n < 0 || n > CAPACITY(*l)){
        scanf("%i", &n);
   }
   NEFF(*l) = n;
   if (n != 0){
      for (i=0; i<n; i++){
         scanf("%i", &ELMT(*l, i));
      }
   }
}

void printList(ListDin l) {
   int i, len;
   len = listLength(l);
   printf("[");
   if (len != 0){
       for (i = 0; i < len-1; i++){
           printf("%i,", ELMT(l, i));
       }
       printf("%i", ELMT(l, len-1));
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin result;
    int n = NEFF(l1);

    CreateListDin(&result, n);

    for (IdxType i = 0; i < n; i++) {
        if (plus) {
            ELMT(result, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(result, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    NEFF(result) = n;

    return result;
}

/* ********** OPERATOR RELASIONAL ********** */

boolean isListEqual(ListDin l1, ListDin l2) {
    if (NEFF(l1) != NEFF(l2)) {
        return false;
    }

    for (IdxType i = 0; i < NEFF(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }

    return true;
}

/* ********** SEARCHING ********** */

IdxType indexOf(ListDin l, ElType val) {
    for (IdxType i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }

    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */

void extremeValues(ListDin l, ElType *max, ElType *min) {
    if (NEFF(l) > 0) {
        *max = ELMT(l, 0);
        *min = ELMT(l, 0);

        for (IdxType i = 1; i < NEFF(l); i++) {
            if (ELMT(l, i) > *max) {
                *max = ELMT(l, i);
            }
            if (ELMT(l, i) < *min) {
                *min = ELMT(l, i);
            }
        }
    }
}

/* ********** OPERASI LAIN ********** */

void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    for (IdxType i = 0; i < NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
    ElType sum = 0;
    for (IdxType i = 0; i < NEFF(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}

int countVal(ListDin l, ElType val) {
    int count = 0;
    for (IdxType i = 0; i < NEFF(l); i++) {
        if (ELMT(l, i) == val) {
            count++;
        }
    }
    return count;
}

/* ********** SORTING ********** */

static void swap(ElType *a, ElType *b) {
    ElType temp = *a;
    *a = *b;
    *b = temp;
}

void sort(ListDin *l, boolean asc) {
    for (IdxType i = 0; i < NEFF(*l) - 1; i++) {
        for (IdxType j = 0; j < NEFF(*l) - i - 1; j++) {
            if (asc) {
                if (ELMT(*l, j) > ELMT(*l, j + 1)) {
                    swap(&ELMT(*l, j), &ELMT(*l, j + 1));
                }
            } else {
                if (ELMT(*l, j) < ELMT(*l, j + 1)) {
                    swap(&ELMT(*l, j), &ELMT(*l, j + 1));
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */

void insertLast(ListDin *l, ElType val) {
    if (NEFF(*l) < CAPACITY(*l)) {
        ELMT(*l, NEFF(*l)) = val;
        NEFF(*l)++;
    }
}

void deleteLast(ListDin *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, NEFF(*l) - 1);
        NEFF(*l)--;
    }
}

/* ********** MENGUBAH UKURAN ARRAY ********** */

void expandList(ListDin *l, int num) {
    if (CAPACITY(*l) + num > NEFF(*l)) {
        CAPACITY(*l) += num;
        BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
    }
}

void shrinkList(ListDin *l, int num) {
    if (CAPACITY(*l) >= num && NEFF(*l) < CAPACITY(*l) - num) {
        CAPACITY(*l) -= num;
        BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
    }
}

void compressList(ListDin *l) {
    if (NEFF(*l) > 0) {
        CAPACITY(*l) = NEFF(*l);
        BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
    }
}

void dealocateList(ListDin *l) {
    if (BUFFER(*l) != NULL) {
        free(BUFFER(*l));
        CAPACITY(*l) = 0;
        NEFF(*l) = 0;
    }
}

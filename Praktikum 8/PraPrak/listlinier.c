/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    *l = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return l == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    Address p = l;
    int i = 0;

    while (p != NULL && i < idx) {
        p = NEXT(p);
        i++;
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    Address p = *l;
    int i = 0;

    while (p != NULL && i < idx) {
        p = NEXT(p);
        i++;
    }

    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    Address p = l;
    int idx = 0;

    while (p != NULL) {
        if (INFO(p) == val) {
            return idx;
        }
        p = NEXT(p);
        idx++;
    }

    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address p = newNode(val);

    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    Address p = newNode(val);

    if (p != NULL) {
        if (*l == NULL) {
            *l = p;
        } else {
            Address last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx < 0) {
        return; // Invalid index
    }

    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p = *l;
        int i = 0;

        while (p != NULL && i < idx - 1) {
            p = NEXT(p);
            i++;
        }

        if (p != NULL) {
            Address new_node = newNode(val);
            if (new_node != NULL) {
                NEXT(new_node) = NEXT(p);
                NEXT(p) = new_node;
            }
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address p = *l;
        *l = NEXT(p);
        *val = INFO(p);
        free(p);
    }
}

void deleteLast(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address p = *l;
        Address prev = NULL;

        while (NEXT(p) != NULL) {
            prev = p;
            p = NEXT(p);
        }

        if (prev == NULL) {
            *l = NULL;
        } else {
            NEXT(prev) = NULL;
        }

        *val = INFO(p);
        free(p);
    }
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx < 0) {
        return; // Invalid index
    }

    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address p = *l;
        Address prev = NULL;
        int i = 0;

        while (p != NULL && i < idx) {
            prev = p;
            p = NEXT(p);
            i++;
        }

        if (p != NULL) {
            if (prev == NULL) {
                *l = NEXT(p);
            } else {
                NEXT(prev) = NEXT(p);
            }

            *val = INFO(p);
            free(p);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p;

    printf("[");
    p = FIRST(l);
    while(p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if(p != NULL) {
            printf(",");
        }
    }
    printf("]");
}

int length(List l){
    int count;
    Address p;

    if(isEmpty(l)) {
        return 0;
    } 
    else {
        count = 1;
        p = FIRST(l);
        while(NEXT(p) != NULL) {
            count++;
            p = NEXT(p);
        }
        return count;
    }
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List result;
    CreateList(&result);

    Address p1 = l1;
    while (p1 != NULL) {
        insertLast(&result, INFO(p1));
        p1 = NEXT(p1);
    }

    Address p2 = l2;
    while (p2 != NULL) {
        insertLast(&result, INFO(p2));
        p2 = NEXT(p2);
    }

    return result;
}

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
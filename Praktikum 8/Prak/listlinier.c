/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

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
    Address P = FIRST(l);
    int i = 0;

    while (i < idx) {
        P = NEXT(P);
        i++;
    }

    return INFO(P);
}

void setElmt(List *l, int idx, ElType val) {
    Address P = FIRST(*l);
    int i = 0;

    while (i < idx) {
        P = NEXT(P);
        i++;
    }

    INFO(P) = val;
}

int indexOf(List l, ElType val) {
    Address P = FIRST(l);
    int idx = 0;

    while (P != NULL) {
        if (INFO(P) == val) {
            return idx;
        }

        P = NEXT(P);
        idx++;
    }

    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    Address P = newNode(val);
    NEXT(P) = FIRST(*l);
    FIRST(*l) = P;
}

void insertLast(List *l, ElType val) {
    Address P = newNode(val);
    Address Last = FIRST(*l);

    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        while (NEXT(Last) != NULL) {
            Last = NEXT(Last);
        }
        NEXT(Last) = P;
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address P = newNode(val);
        Address Prec = FIRST(*l);
        int i = 0;

        while (i < idx - 1) {
            Prec = NEXT(Prec);
            i++;
        }

        NEXT(P) = NEXT(Prec);
        NEXT(Prec) = P;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address P = FIRST(*l);
        *val = INFO(P);
        FIRST(*l) = NEXT(P);
        free(P);
    }
}

void deleteLast(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address Last = FIRST(*l);
        Address PrecLast = NULL;

        while (NEXT(Last) != NULL) {
            PrecLast = Last;
            Last = NEXT(Last);
        }

        if (PrecLast == NULL) {
            deleteFirst(l, val);
        } else {
            *val = INFO(Last);
            NEXT(PrecLast) = NULL;
            free(Last);
        }
    }
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address P = FIRST(*l);
        Address Prec = NULL;
        int i = 0;

        while (i < idx) {
            Prec = P;
            P = NEXT(P);
            i++;
        }

        *val = INFO(P);
        NEXT(Prec) = NEXT(P);
        free(P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    printf("[");
    Address P = FIRST(l);

    while (P != NULL) {
        printf("%d", INFO(P));

        if (NEXT(P) != NULL) {
            printf(",");
        }

        P = NEXT(P);
    }

    printf("]\n");
}

int length(List l) {
    int count = 0;
    Address P = FIRST(l);

    while (P != NULL) {
        count++;
        P = NEXT(P);
    }

    return count;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);

    Address P1 = FIRST(l1);

    while (P1 != NULL) {
        insertLast(&l3, INFO(P1));
        P1 = NEXT(P1);
    }

    Address P2 = FIRST(l2);

    while (P2 != NULL) {
        insertLast(&l3, INFO(P2));
        P2 = NEXT(P2);
    }

    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
{
    Address now;
    boolean flag = false;
    now = L;
    while(now->next != NULL && !flag){
        if(now==P){
            flag = true;
        }
        now = now->next;
    }
    return flag;
}

Address searchPrec(List L, ElType X)
{
    if(isEmpty(L) || length(L) == 1){
        return NULL;
    }
    Address p = L;
    Address previous;
    while(p != NULL && INFO(p)!= X){
        previous = p;
        p = NEXT(p);
    }
    if(p == NULL){
        return NULL;
    }
    else{
        return previous;
    }
}

ElType maxValue(List l)
{
    int maksimum;
    Address p = l;
    maksimum = p->info;
    while(p != NULL){
        if(INFO(p) > maksimum){
            maksimum = INFO(p);
        }
        p = NEXT(p);
    }
    return maksimum;
}

Address adrMax(List l)
{
    int maksimum = maxValue(l);
    Address p = l;
    while (p != NULL && INFO(p) != maksimum){
        p = NEXT(p);
    }
    return p;
}

ElType minValue(List l)
{
    int minimum;
    Address p = l;
    minimum = INFO(p);
    while (p != NULL){
        if (INFO(p) < minimum){
            minimum = INFO(p);
        }
        p = NEXT(p);
    }
    return minimum;
}

Address adrMin(List l)
{
    int minimum = minValue(l);
    Address p = l;
    while(p != NULL && INFO(p) != minimum){
        p = NEXT(p);
    }
    return p;
}

float average(List l)
{
    float sum = 0;
    int n = 0;
    Address p = l;
    while(p != NULL){
        sum += INFO(p);
        n++;
        p = NEXT(p);
    }
    return sum/n;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l)
{
    Address p = *l;
    int value;
    while(p != NULL){
        deleteFirst(l, &value);
        p = NEXT(p);
    }
    *l = NULL;
}

void copyList(List *l1, List *l2)
{
    *l2 = *l1;
}

void inverseList(List *l)
{
    if(!isEmpty(*l)){
        int n = length(*l);
        int i;
        Address p = *l;
        Address prev;
        Address last;
        while(NEXT(p)!= NULL){
            p = NEXT(p);
        }
        last = p;
        while (p != *l){
            prev = *l;
            while(NEXT(prev) != p){
                prev = NEXT(prev);
            }
            NEXT(p) = prev;
            p = prev;
        }
        NEXT(p) = NULL;
        *l = last;
    }
}

Address newNode(ElType val) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = val;
        NEXT(P) = NULL;
    }
    return P;
}
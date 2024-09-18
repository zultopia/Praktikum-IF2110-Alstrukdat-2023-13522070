/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

/* File : listsirkuler.c */
#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
    Address P = (Address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        INFO(P) = val;
        NEXT(P) = NULL;
    }
    return P;
}

void deallocate(Address P) {
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
    Address P = FIRST(l);
    if (!isEmpty(l)) {
        do {
            if (INFO(P) == val) {
                return P;
            }
            P = NEXT(P);
        } while (P != FIRST(l));
    }
    return NULL;
}

boolean addrSearch(List l, Address p) {
    Address P = FIRST(l);
    if (!isEmpty(l)) {
        do {
            if (P == p) {
                return true;
            }
            P = NEXT(P);
        } while (P != FIRST(l));
    }
    return false;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
  Address p, last;
  p = allocate(val);
  if(p != NULL){
    if(isEmpty(*l)){
      NEXT(p) = p;
    }else{
      last = FIRST(*l);
      while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
      }
      NEXT(p) = FIRST(*l);
      NEXT(last) = p;
    }
    FIRST(*l) = p;
  }
}

void insertLast(List *l, ElType val){
  Address p, last;
  if(isEmpty(*l)){
    insertFirst(l, val);
  }else{
    p = allocate(val);
    if(p != NULL){
      last = FIRST(*l);
      while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
      }
      NEXT(last) = p;
      NEXT(p) = FIRST(*l);
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
  Address p, last;
  p = FIRST(*l);
  *val = INFO(p);
  if(NEXT(FIRST(*l)) == FIRST(*l)){
    FIRST(*l) = NULL;
  }else{
    last = FIRST(*l);
    while(NEXT(last) != FIRST(*l)){
      last = NEXT(last);
    }
    FIRST(*l) = NEXT(FIRST(*l));
    NEXT(last) = FIRST(*l);
  }
  deallocate(p);
}

void deleteLast(List *l, ElType * val){
  Address last, precLast;
  last = FIRST(*l), precLast = NULL;
  while(NEXT(last) != FIRST(*l)){
    precLast = last;
    last = NEXT(last);
  }if(precLast == NULL){
    FIRST(*l) = NULL;
  }else{
    NEXT(precLast) = FIRST(*l);
  }
  *val = INFO(last);
  deallocate(last);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
  Address p;
  if (isEmpty(l)) {
    printf("[]");
  } else {
    p = FIRST(l);
    printf("[");
    do {
        if (NEXT(p) == FIRST(l)) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    } while (p != FIRST(l));
    printf("]");
  }
}
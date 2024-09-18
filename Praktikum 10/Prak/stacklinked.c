/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "stacklinked.h"

// Fungsi untuk mengalokasi dan membuat node baru
Address newNode(ElType x) {
    Address newNode = (Address)malloc(sizeof(Node));
    if (newNode != NIL) {
        INFO(newNode) = x;
        NEXT(newNode) = NIL;
    }
    return newNode;
}

// Fungsi untuk memeriksa apakah Stack kosong
boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NIL;
}

// Fungsi untuk menghitung banyaknya elemen dalam Stack
int length(Stack s) {
    int count = 0;
    Address current = ADDR_TOP(s);
    while (current != NIL) {
        count++;
        current = NEXT(current);
    }
    return count;
}

// Fungsi untuk membuat Stack kosong
void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NIL;
}

// Fungsi untuk menampilkan isi Stack
void DisplayStack(Stack s) {
    Address p;
    p = ADDR_TOP(s);
    printf("[");
    while(p != NULL) {
        if(NEXT(p) != NULL) {
            printf("%d,", INFO(p));
        } else {
            printf("%d", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

// Fungsi untuk menambahkan elemen x ke dalam Stack
void push(Stack *s, ElType x) {
    Address p;
    p = newNode(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

// Fungsi untuk menghapus elemen puncak (Top) dari Stack
void pop(Stack *s, ElType *x) {
    Address temp = ADDR_TOP(*s);
    *x = TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(temp) = NIL;
    free(temp);
    
}
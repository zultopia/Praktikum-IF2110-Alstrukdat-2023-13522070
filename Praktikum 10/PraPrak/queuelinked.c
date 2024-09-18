/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "queuelinked.h"

// Fungsi untuk mengalokasi dan membuat node baru
Address newNode(ElType x) {
    Address newNode = (Address)malloc(sizeof(Node));
    if (newNode != NIL) {
        INFO(newNode) = x;
        NEXT(newNode) = NIL;
    }
    return newNode;
}

// Fungsi untuk memeriksa apakah Queue kosong
boolean isEmpty(Queue q) {
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}

// Fungsi untuk menghitung banyaknya elemen dalam Queue
int length(Queue q) {
    int count = 0;
    Address current = ADDR_HEAD(q);
    while (current != NIL) {
        count++;
        current = NEXT(current);
    }
    return count;
}

// Fungsi untuk membuat Queue kosong
void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

// Fungsi untuk menampilkan isi Queue
void DisplayQueue(Queue q) {
    Address p;
    p = ADDR_HEAD(q);
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

// Fungsi untuk menambahkan elemen x ke dalam Queue
void enqueue(Queue *q, ElType x) {
    Address p;
    p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

// Fungsi untuk menghapus elemen dari depan Queue
void dequeue(Queue *q, ElType *x) {
    Address p;
    p = ADDR_HEAD(*q);
    *x = INFO(p);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NULL) {
        ADDR_TAIL(*q) = NULL;
    }
    free(p);
}
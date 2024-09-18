/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S) {
    return Top(S) == Nil;
}

boolean IsFull(Stack S) {
    return Top(S) == MaxEl - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X) {
    if (!IsFull(*S)) {
        Top(*S)++;
        InfoTop(*S) = X;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X) {
    if (!IsEmpty(*S)) {
        *X = InfoTop(*S);
        Top(*S)--;
    }
}
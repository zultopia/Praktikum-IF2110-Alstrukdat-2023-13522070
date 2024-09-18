/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
    return l == NIL;
}

boolean isOneElmt(List l) {
    return !isEmpty(l) && NEXT(l) == NIL;
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address P = newNode(e);
    if (P != NIL) {
        NEXT(P) = l;
        return P;
    } else {
        return l;
    }
}

List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return l2;
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else {
        return (head(l) == x) || isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}
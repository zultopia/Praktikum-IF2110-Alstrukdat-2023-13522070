/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "stdio.h"
#include "deque.h"

Address newNode(ElType x) {
    Address newNode = (Address)malloc(sizeof(Node));
    if (newNode != NIL) {
        INFO(newNode) = x;
        NEXT(newNode) = NIL;
    }
    return newNode;
}

boolean isEmpty(Deque q) {
    return ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL;
}

int length(Deque q) {
    int count = 0;
    Address current = ADDR_HEAD(q);
    while (current != NIL) {
        count++;
        current = NEXT(current);
    }
    return count;
}

void CreateDeque(Deque *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayDeque(Deque q) {
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

void EnqueueHead(Deque *q, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        } else {
            NEXT(p) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = p;
        }
    }
}

void DequeueHead(Deque *q, ElType *x) {
    Address temp = ADDR_HEAD(*q);
    *x = INFO(temp);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q)) {
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
    } else {
        ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    }
    free(temp);
}

void EnqueueTail(Deque *q, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void DequeueTail(Deque *q, ElType *x) {
    if (length(*q) == 1) {
        DequeueHead(q, x);
    }
    else {
        Address p = ADDR_HEAD(*q);
        *x = TAIL(*q);
        Address temp = ADDR_TAIL(*q);
        while (NEXT(NEXT(p)) != NULL) {
            p = NEXT(p);
        }
        NEXT(p) = NULL;
        ADDR_TAIL(*q) = p;
        free(temp);
    }
}
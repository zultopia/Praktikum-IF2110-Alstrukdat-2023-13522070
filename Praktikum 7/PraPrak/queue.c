/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return ((IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1) || (IDX_TAIL(q) == (IDX_HEAD(q) - 1) % (CAPACITY - 1)));
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else if (IDX_TAIL(q) >= IDX_HEAD(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    } else {
        return (CAPACITY - IDX_HEAD(q)) + (IDX_TAIL(q) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
    if (!isFull(*q)) {
        if (isEmpty(*q)) {
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = 0;
        } else if (IDX_TAIL(*q) == CAPACITY - 1) {
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val) {
    if (!isEmpty(*q)) {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        } else if (IDX_HEAD(*q) == CAPACITY - 1) {
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("[]\n");
        return;
    }

    printf("[");
    int i = IDX_HEAD(q);
    int count = length(q);

    while (count > 0) {
        printf("%d", q.buffer[i]);
        if (count > 1) {
            printf(",");
        }
        i = (i + 1) % CAPACITY;
        count--;
    }

    printf("]\n");
}
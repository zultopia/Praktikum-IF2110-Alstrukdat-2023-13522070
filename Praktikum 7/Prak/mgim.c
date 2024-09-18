/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "queue.h"

int max(int a[]) {
    if (a[0] > a[1]) {
        return a[0];
    } else {
        return a[1];
    }
}

void fway(int n, int r, Queue *Q, int *prev) {
    int a;
    if (n == 0) {
        if (r < *prev) {
            if (!isEmpty(*Q)) {
                dequeue(Q, &a);
            }
            enqueue(Q, r);
            *prev = r;
        }
    } else {
        r++;
        fway(n - 1, r, Q, prev);
        int temp1[2];
        int j;
        int jawaban = n;
        boolean step2 = false;
        for (j = 2; j <= n / 2; j++) {
            if (n % j == 0) {
                temp1[0] = j;
                temp1[1] = n / j;
                if (max(temp1) < jawaban) {
                    jawaban = max(temp1);
                    step2 = true;
                }
            }
        }
        if (step2) {
            fway(jawaban, r, Q, prev);
        }
    }
}

int minimumQueue(Queue *q) {
    int jawaban;
    dequeue(q, &jawaban);
    int temp;
    while (!isEmpty(*q)) {
        dequeue(q, &temp);
        if (temp < jawaban) {
            jawaban = temp;
        }
    }
    return jawaban;
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int temp;

    int hasil = 1;
    Queue q;
    int tempR;

    for (i = 0; i < n; i++) {
        int r = 0;
        CreateQueue(&q);
        scanf("%d", &temp);
        int prev = temp;
        fway(temp, r, &q, &prev);
        int a;

        hasil = hasil * prev;
    }
    if (n == 0) {
        printf("0\n");
    } else {
        printf("%d\n", hasil);
    }

    return 0;
}
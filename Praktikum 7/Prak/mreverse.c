/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "queue.h"

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int i;
    int a[n];
    Queue q;
    CreateQueue(&q);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int b[k];
    for (i = 0; i < k ; i++) {
        b[i] = a[i];
    }
    int c[k];
    int j = 0;
    for (i = k-1; i>= 0; i--) {
        c[j] = b[i];
        j++;
    }
    for (i = 0; i< k; i++) {
        a[i] = c[i];
    }
    for (i = 0; i < n; i++) {
        enqueue(&q, a[i]);
    }
    displayQueue(q);
}
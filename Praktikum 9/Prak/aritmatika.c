/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "list_circular.h"

int main() {
    int N, val;
    List l;
    CreateList(&l);
    boolean valid = true;
    int i = 0;
    scanf("%d", &N);

    for (i = 0; i < N ; i++) {
        scanf("%d", &val);
        insertLast(&l, val);
    }

    Address check = FIRST(l);
    int b = INFO(check);
    check = NEXT(check);
    int a = INFO(check) - b;
    Address test = FIRST(l);
    for (int j = 1; j <= N; j++) {
        int deret = a*(j-1) + b;
        if(deret == INFO(test)) {
            valid = true;
            test = NEXT(test);
        } else {
            valid = false;
            break;
        }
    }
    if (valid) {
        printf("%d %d\n", a ,b);
    } else {
        printf("0 0\n");
    }
}
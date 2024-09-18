/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "stacklinked.h"
#include <stdio.h>

boolean canSort(int n, int arr[]) {
    Stack park, street;
    CreateStack(&park);
    CreateStack(&street);

    int expected = 1; 
    int i = 0; 

    while (i < n || !isEmpty(street)) {
        if (!isEmpty(park) && TOP(park) == expected) {
            int temp;
            pop(&park, &temp);
            expected++;
        } else if (!isEmpty(street) && TOP(street) == expected) {
            int temp;
            pop(&street, &temp);
            expected++;
        } else if (!isEmpty(park) && TOP(park) != expected) {
            int temp;
            pop(&park, &temp);
            push(&street, temp);
        } else if (i < n) {
            push(&street, arr[i]);
            i++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        int plat[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &plat[j]);
        }
        if (canSort(N, plat)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
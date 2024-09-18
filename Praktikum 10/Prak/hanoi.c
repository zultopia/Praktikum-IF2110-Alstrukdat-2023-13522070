/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "stacklinked.h"

int main() {
    int N;
    scanf("%d", &N);
    int Si, Di;
    int i;

    Stack Menara1, Menara2, Menara3;
    CreateStack(&Menara1);
    CreateStack(&Menara2);
    CreateStack(&Menara3);

    int p;
    for (p = 5; p > 0; p--) {
        push(&Menara1, p);
    }

    int temp, temp1;
    boolean found = false;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &Si, &Di);
        if (Si == 1) {
            if (isEmpty(Menara1)) {
                printf("Menara kosong\n");
            } else {
                if (Di == 2) {
                    if (isEmpty(Menara2)) {
                        pop(&Menara1, &temp);
                        push(&Menara2, temp);
                    } else {
                        pop(&Menara1, &temp);
                        pop(&Menara2, &temp1);
                        if (temp1 < temp) {
                            printf("Piringan tidak dapat dipindah\n");
                            push(&Menara1, temp);
                            push(&Menara2, temp1);
                        } else {
                            push(&Menara2, temp1);
                            push(&Menara2, temp);
                        }
                    }
                } else if (Di == 3) {
                    if (isEmpty(Menara3)) {
                        pop(&Menara1, &temp);
                        push(&Menara3, temp);
                    } else {
                        pop(&Menara1, &temp);
                        pop(&Menara3, &temp1);
                        if (temp1 < temp) {
                            printf("Piringan tidak dapat dipindah\n");
                            push(&Menara1, temp);
                            push(&Menara3, temp1);
                        } else {
                            push(&Menara3, temp1);
                            push(&Menara3, temp);
                        }
                    }
                }
            }
        }
        else if (Si == 2) {
            if (isEmpty(Menara2)) {
                printf("Menara kosong\n");
            } else {
                if (Di == 1) {
                    if (isEmpty(Menara1)) {
                        pop(&Menara2, &temp);
                        push(&Menara1, temp);
                    } else {
                        pop(&Menara2, &temp);
                        pop(&Menara1, &temp1);
                        if (temp1 < temp) {
                            printf("Piringan tidak dapat dipindah\n");
                            push(&Menara2, temp);
                            push(&Menara1, temp1);
                        } else {
                            push(&Menara1, temp1);
                            push(&Menara1, temp);
                        }
                    }
                } else if (Di == 3) {
                    if (isEmpty(Menara3)) {
                        pop(&Menara2, &temp);
                        push(&Menara3, temp);
                    } else {
                        pop(&Menara2, &temp);
                        pop(&Menara3, &temp1);
                        if (temp1 < temp) {
                            printf("Piringan tidak dapat dipindah\n");
                            push(&Menara2, temp);
                            push(&Menara3, temp1);
                        } else {
                            push(&Menara3, temp1);
                            push(&Menara3, temp);
                        }
                    }
                }
            }
            
        }
        else if (Si == 3) {
            if (isEmpty(Menara3)) {
                printf("Menara kosong\n");
            } else {
                if (Di == 2) {
                    if (isEmpty(Menara2)) {
                        pop(&Menara3, &temp);
                        push(&Menara2, temp);
                    } else {
                        pop(&Menara3, &temp);
                        pop(&Menara2, &temp1);
                        if (temp1 < temp) {
                            printf("Piringan tidak dapat dipindah\n");
                            push(&Menara3, temp);
                            push(&Menara2, temp1);
                        } else {
                            push(&Menara2, temp1);
                            push(&Menara2, temp);
                        }
                    }
                } else if (Di == 1) {
                    if (isEmpty(Menara1)) {
                        pop(&Menara3, &temp);
                        push(&Menara1, temp);
                    } else {
                        pop(&Menara3, &temp);
                        pop(&Menara1, &temp1);
                        if (temp1 < temp) {
                            printf("Piringan tidak dapat dipindah\n");
                            push(&Menara3, temp);
                            push(&Menara1, temp1);
                        } else {
                            push(&Menara1, temp1);
                            push(&Menara1, temp);
                        }
                    }
                }
            }

        }
    }
    printf("Menara 1: ");
    DisplayStack(Menara1);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(Menara2);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(Menara3);
    printf("\n");
}
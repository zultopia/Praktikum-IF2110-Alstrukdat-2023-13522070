/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    CreateQueue(&q);
    int option, time, total_time = 0, num_stud = 0;
    scanf("%d", &option);
    while (option != 0) {
        if (option == 1) {
            scanf("%d", &time);
            if(isFull(q)) {
                printf("Queue penuh\n");
            }
            else {
                if (time >= 1 && time <= 20) {
                    enqueue(&q, time);
                }
            }
        } else if (option == 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            }
            else {
                dequeue(&q, &time);
                total_time += time;
                num_stud++;
            }
        }
        scanf("%d", &option);
    }
    if (num_stud == 0) {
        printf("%d\n", num_stud);
        printf("Tidak bisa dihitung\n");
    } else {
        float avg_time = (float)total_time /(float)num_stud;
        printf("%d\n", num_stud);
        printf("%.2f\n", avg_time);
    }
    return 0;
}
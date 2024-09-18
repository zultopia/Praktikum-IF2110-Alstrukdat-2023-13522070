/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "listlinier.h"

int main() {
    int n;
    int q;
    scanf("%d",&n);
    scanf("%d",&q);

    List l;
    CreateList(&l);
    float hit = 0;

    if(q > 0) {
        int i, x;
        for(i=0; i<q; i++) {
            scanf("%d",&x);
            
            if(isEmpty(l)) {
                if(length(l) < n) {
                    insertFirst(&l,x);
                }
                printf("miss "); displayList(l); printf("\n");
            }

            else{
                int val;
                if(indexOf(l,x) != IDX_UNDEF) {
                    hit++;
                    deleteAt(&l,indexOf(l,x),&val);
                    insertFirst(&l,x);
                    printf("hit "); displayList(l); printf("\n");
                }
                else if(length(l) < n) {
                    insertFirst(&l,x);
                    printf("miss "); displayList(l); printf("\n");
                }
                else{
                    deleteLast(&l,&val);
                    insertFirst(&l,x);
                    printf("miss "); displayList(l); printf("\n");
                }
            }
        }
        float ratio = hit/q;
        printf("hit ratio: %.2f\n",ratio);
    }
    else{
        printf("hit ratio: %.2f\n",0.00);
    }
}
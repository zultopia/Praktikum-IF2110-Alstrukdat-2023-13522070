/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "listrec.h"

List inputlist(List l, int length){
    if(length != 0) {
        int temp;
        scanf("%d",&temp);
        l = konso(inputlist(l,length-1),temp);
    }
}

List inverseList (List l)
{
    if(isEmpty(l)) {
        return l;
    }
    else if(isOneElmt(l)) {
        return l;
    }
    else {
        return konsb(inverseList(tail(l)),head(l));
    }
}

void splitAtX (List l, int n, ElType x, List *l1, List *l2, int i)
{
    if(isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    }
    else {
        if(i <= n) {
    
            i++;
            splitAtX (tail(l), n, x, l1, l2, i);
            *l1 = konsb(*l1,head(l));
        }
        else {
            splitAtX (tail(l), n, x, l1, l2, i);

            *l2 = konsb(*l2,head(l));
        }
    }

}

void splitOnX (List l, int n, ElType x, List *l1, List *l2)
{
    if(isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    }
    else {
        for(int i=0; i<x; i++){
            *l1 = konso(*l1,head(l));
            l = NEXT(l);
        }
        for(int j=0; j<(n-x-1); j++){
            *l2 = konso(*l2,head(l));
            l = NEXT(l);
        }
        *l2 = konso(*l2,head(l));
    }
}

int main() {
    List l, l1, l2, lr;
    int n, q;
    scanf("%d",&n);
    l = inputlist(l,n);

    scanf("%d",&q);
    int i; int y;
    for(i=0; i<q; i++){
        scanf("%d",&y);
        splitAtX(l,y,y,&l1,&l2,1);
        l = concat(l1,l2);
    }
    displayList(l); 
}
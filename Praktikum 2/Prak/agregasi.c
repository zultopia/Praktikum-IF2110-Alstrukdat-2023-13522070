/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l;
    readList(&l);

    int x;
    scanf("%d",&x);

    // sort
    sortList(&l,true);
    printList(l);printf("\n");

    int i;
    float average,sum = 0;
    for(i=0;i<listLength(l);i++)
    {
        sum += ELMT(l,i);
    }

    // average
    average = sum/listLength(l);
    printf("Average: %.2f\n",average);

    // anu
    ElType max,min;
    extremeValues(l,&max,&min);
    if(indexOf(l,x) != IDX_UNDEF)
    {
        printf("%d\n",indexOf(l,x));
        if(x == max)
        {
            printf("X maksimum\n");
        }
        if(x == min)
        {
            printf("X minimum\n");
        }
        // median
        int idxmed = getLastIdx(l)/2;
        if(x == ELMT(l,idxmed))
        {
            printf("X median\n");
        }
    }

    else
    {
        printf("%d tidak ada\n",x);
    }
    
    return 0;
}
/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listdin.h"

int main()
{
    ListDin A;
    CreateListDin(&A,0);

    int q,i;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        int tipe;
        scanf("%d",&tipe);

        if(tipe==1)
        {
            int x;
            scanf("%d",&x);
            if (CAPACITY(A) == 0)
            {
                expandList(&A,1);
                insertLast(&A,x);

            }
            else if(isFull(A))
            {
                expandList(&A,CAPACITY(A));
                insertLast(&A,x);
            }
            else
            {
                insertLast(&A,x);

            }
        }

        else if(tipe==2)
        {
            if(listLength(A) > 0)
            {
                int val;
                deleteLast(&A,&val);

                if(NEFF(A) <= round(CAPACITY(A)/2))
                {
                    shrinkList(&A,(CAPACITY(A) - round(CAPACITY(A)/2)));
                }
            }

        }

        else
        {
            int cap = CAPACITY(A);
            printf("%d",cap);printf(" ");
            printList(A);
            printf("\n");
        }

    }
    return 0;
}
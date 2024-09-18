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
    ListDin l;
    CreateListDin(&l,100);
    readList(&l);

    if(listLength(l) <= 1)
    {
        printf("0");
        printf("\n");

    }

    else
    {
        int max, min;
        extremeValues(l,&max,&min);
        max = max+1;

        int selisih = abs(max-min);
        printf("%d",selisih);
        printf("\n");
    }

    return 0;
}
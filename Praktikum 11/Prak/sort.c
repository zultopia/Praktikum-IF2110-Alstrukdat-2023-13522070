/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "sort.h"

Address findMiddle(List l) {
    if (l == NULL || NEXT(l) == NULL) {
        return l;
    }

    Address slow = l;
    Address fast = NEXT(l);

    while (fast != NULL && NEXT(fast) != NULL) {
        slow = NEXT(slow);
        fast = NEXT(NEXT(fast));
    }

    return slow;
}

List merge(List l1, List l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }

    if (INFO(l1) <= INFO(l2)) {
        NEXT(l1) = merge(NEXT(l1), l2);
        return l1;
    } else {
        NEXT(l2) = merge(l1, NEXT(l2));
        return l2;
    }
}

List mergeSort(List l) {
    if (l == NULL || NEXT(l) == NULL) {
        return l;
    }

    Address middle = findMiddle(l);
    List left = l;
    List right = NEXT(middle);
    NEXT(middle) = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

List zigZagSort(List l) {
    int array[length(l)];
    int i, n, len = length(l), j;

    List result = NULL;
    Address P = l;

    for (i = 0; i < len; i++) {
        array[i] = INFO(P);
        P = NEXT(P);
    }

    for (i = 0; i < len; i++) {
        int min = array[i], max = array[i];
        int minIdx = i, maxIdx = i;
        if (i % 2 == 0) {
            for (j = i; j < len; j++) {
                if (array[j] < min) {
                    min = array[j];
                    minIdx = j;
                }
            }
            int temp = array[i];
            array[i] = min;
            array[minIdx] = temp;
        } else {
            for (j = i; j < len; j++) {
                if (array[j] > max) {
                    max = array[j];
                    maxIdx = j;
                }
            }
            int temp = array[i];
            array[i] = max;
            array[maxIdx] = temp;
        }
    } for (i = 0; i < len; i++) {
        result = konsb(result, array[i]);
    }
    return result;
}
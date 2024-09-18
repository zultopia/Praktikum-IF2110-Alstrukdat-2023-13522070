/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "listrec.h"
#include <stdlib.h>

Address newNode(ElType x) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;
}

boolean isEmpty(List l) {
    return l == NIL;
}

boolean isOneElmt(List l) {
    return !isEmpty(l) && NEXT(l) == NIL;
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address P = newNode(e);
    if (P != NIL) {
        NEXT(P) = l;
        l = P;
    }
    return l;
}

List konsb(List l, ElType e) {
    Address P = newNode(e);
    Address last = l;
    if (P != NIL) {
        if (isEmpty(l)) {
            l = P;
        } else {
            while (NEXT(last) != NIL) {
                last = NEXT(last);
            }
            NEXT(last) = P;
        }
    }
    return l;
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return l2;
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else {
        return (head(l) == x) || isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx) {
    if (idx == 0 || isEmpty(l)) {
        return konso(l, e);
    } else {
        return konso(insertAt(tail(l), e, idx - 1), head(l));
    }
}

List deleteFirst(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        Address temp = l;
        l = tail(l);
        free(temp);
        return l;
    }
}

List deleteAt(List l, int idx) {
    if (idx == 0 || isEmpty(l)) {
        return deleteFirst(l);
    } else {
        return konso(deleteAt(tail(l), idx - 1), head(l));
    }
}

List deleteLast(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else if (isOneElmt(l)) {
        free(l);
        return NIL;
    } else {
        return konso(deleteLast(tail(l)), head(l));
    }
}

List inverseList(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konsb(inverseList(tail(l)), head(l));
    }
}

void splitPosNeg(List l, List *l1, List *l2) {
    if (isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    } else {
        if (head(l) >= 0) {
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2) {
    if (isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    } else {
        if (head(l) < x) {
            splitOnX(tail(l), x, l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitOnX(tail(l), x, l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

List removeDuplicate(List l, List unique) {
    if (isEmpty(l)) {
        return unique;
    } else {
        if (!isMember(unique, head(l))) {
            unique = konso(unique, head(l));
        }
        return removeDuplicate(tail(l), unique);
    }
}

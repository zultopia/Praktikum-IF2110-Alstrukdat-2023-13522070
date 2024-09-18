/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree) {
    BinTree p = (BinTree)malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = root;
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val) {
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode(Address p) {
    free(p);
}

boolean isTreeEmpty(BinTree p) {
    return p == NULL;
}

boolean isOneElmt(BinTree p) {
    return (p != NULL) && (LEFT(p) == NULL) && (RIGHT(p) == NULL);
}

boolean isUnerLeft(BinTree p) {
    return (p != NULL) && (LEFT(p) != NULL) && (RIGHT(p) == NULL);
}

boolean isUnerRight(BinTree p) {
    return (p != NULL) && (LEFT(p) == NULL) && (RIGHT(p) != NULL);
}

boolean isBinary(BinTree p) {
    return (p != NULL) && (LEFT(p) != NULL) && (RIGHT(p) != NULL);
}

void printPreorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}

void printInorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(");
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}

void printPostorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
    } else {
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d)", ROOT(p));
    }
}

void printTreeLevel(BinTree p, int h, int l)
{
    int N;
    if (!isTreeEmpty(p)) {
        N = h * l;
        while (N > 0) {
            printf(" ");
            N--;
        }
        printf("%d\n", ROOT(p));
        printTreeLevel(LEFT(p), h, l + 1);
        printTreeLevel(RIGHT(p), h, l + 1);
    }
}

void printTree(BinTree p, int h) {
     printTreeLevel(p, h, 0);
}

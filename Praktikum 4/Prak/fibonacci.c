/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "matrix.h"

// Fungsi untuk menghitung matriks pangkat dengan mod
Matrix PangkatMatrix(Matrix m, unsigned long long pangkat) {
    if (pangkat == 0) {
        Matrix identity;
        createMatrix(2, 2, &identity);
        ELMT(identity, 0, 0) = 1;
        ELMT(identity, 0, 1) = 0;
        ELMT(identity, 1, 0) = 0;
        ELMT(identity, 1, 1) = 1;
        return identity;
    } else if (pangkat == 1) {
        return m;
    } else {
        Matrix m2 = PangkatMatrix(m, pangkat / 2);
        Matrix mulMatrix = multiplyMatrixWithMod(m2, m2, 2003);

        if (pangkat % 2 == 1) {
            mulMatrix = multiplyMatrixWithMod(mulMatrix, m, 2003);
        }
        return mulMatrix;
    }
}

int main() {
    unsigned long long K;
    scanf("%llu", &K);

    if (K == 1 || K == 2) {
        printf("1\n");
    } else {
        Matrix baseMatrix;
        createMatrix(2, 2, &baseMatrix);
        ELMT(baseMatrix, 0, 0) = 1;
        ELMT(baseMatrix, 0, 1) = 1;
        ELMT(baseMatrix, 1, 0) = 1;
        ELMT(baseMatrix, 1, 1) = 0;

        Matrix resultMatrix = PangkatMatrix(baseMatrix, K - 1);
        printf("%d\n", ELMT(resultMatrix, 0, 0) % 2003);
    }

    return 0;
}

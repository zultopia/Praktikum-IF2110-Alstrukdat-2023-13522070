/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "matrix.h"
#include <stdio.h>

void createMatrix(int nRows, int nCols, Matrix *m) {
    int i, j;
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    for (i = 0; i < nRows; i++) {
        for (j = 0; j < nCols; j++) {
            ELMT(*m, i, j) = 0; // Inisialisasi semua elemen dengan 0
        }
    }
}

boolean isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m) {
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    if (isIdxEff(m, i, i)) {
        return ELMT(m, i, i);
    } else {
        return 0; // Diagonal di luar batas matriks
    }
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    int i, j;
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    for (i = 0; i < ROW_EFF(mIn); i++) {
        for (j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printf("%d", ELMT(m, i, j));
            if (j < COL_EFF(m) - 1) {
                printf(" ");
            }
        }
        if (i < ROW_EFF(m) - 1) {
            printf("\n");
        }
    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &result);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(result, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &result);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(result, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &result);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            ElType sum = 0;
            for (k = 0; k < COL_EFF(m1); k++) {
                sum += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(result, i, j) = sum;
        }
    }
    return result;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod) {
    Matrix result;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &result);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            ElType sum = 0;
            for (k = 0; k < COL_EFF(m1); k++) {
                sum += (ELMT(m1, i, k) * ELMT(m2, k, j)) % mod;
                sum %= mod;
            }
            ELMT(result, i, j) = sum;
        }
    }
    return result;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(result, i, j) = ELMT(m, i, j) * x;
        }
    }
    return result;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                return false;
            }
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m) {
    return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m) {
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (i == j && ELMT(m, i, j) != 1) {
                return false;
            } else if (i != j && ELMT(m, i, j) != 0) {
                return false;
            }
        }
    }
    return true;
}

boolean isSparse(Matrix m) {
    int countNonZero = 0;
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                countNonZero++;
            }
        }
    }
    int totalElements = ROW_EFF(m) * COL_EFF(m);
    return (countNonZero <= 0.05 * totalElements);
}

Matrix negation(Matrix m) {
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(result, i, j) = -ELMT(m, i, j);
        }
    }
    return result;
}

void pNegation(Matrix *m) {
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = -ELMT(*m, i, j);
        }
    }
}

float determinant(Matrix m) {
    if (!isSquare(m)) {
        return 0.0;
    }
    if (ROW_EFF(m) == 1) {
        return (float)ELMT(m, 0, 0);
    }
    if (ROW_EFF(m) == 2) {
        return (float)(ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0));
    }
    float det = 0.0;
    int i, j;
    for (j = 0; j < COL_EFF(m); j++) {
        Matrix subMatrix;
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &subMatrix);
        for (i = 1; i < ROW_EFF(m); i++) {
            int subCol = 0;
            for (int k = 0; k < COL_EFF(m); k++) {
                if (k != j) {
                    ELMT(subMatrix, i - 1, subCol) = ELMT(m, i, k);
                    subCol++;
                }
            }
        }
        det += (float)(ELMT(m, 0, j) * determinant(subMatrix));
    }
    return det;
}

Matrix transpose(Matrix m) {
    Matrix result;
    createMatrix(COL_EFF(m), ROW_EFF(m), &result);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(result, j, i) = ELMT(m, i, j);
        }
    }
    return result;
}

void pTranspose(Matrix *m) {
    Matrix result = transpose(*m);
    copyMatrix(result, m);
}

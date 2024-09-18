/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "matrix.h"

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    Matrix matrix;
    createMatrix(N, M, &matrix);

    // Membaca matriks
    readMatrix(&matrix, N, M);

    int maxSum = 0;

    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < M; j1++) {
            for (int i2 = i1; i2 < N; i2++) {
                for (int j2 = j1; j2 < M; j2++) {
                    // Menghitung luas segi empat
                    int area = (i2 - i1 + 1) * (j2 - j1 + 1);

                    // Menghitung total elemen di dalam segi empat
                    int sum = 0;
                    for (int i = i1; i <= i2; i++) {
                        for (int j = j1; j <= j2; j++) {
                            sum += ELMT(matrix, i, j);
                        }
                    }

                    // Memeriksa apakah luas sesuai dengan K dan lebih besar dari maxSum
                    if (area == K && sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    printf("%d\n", maxSum);

    return 0;
}

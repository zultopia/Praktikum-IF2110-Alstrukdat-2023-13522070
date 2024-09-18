/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "matrix.h"

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Matrix puzzle;
    createMatrix(N, M, &puzzle);

    readMatrix(&puzzle, N, M);

    int K;
    scanf("%d", &K);

    int solvable = 1; 

    for (int k = 0; k < K; k++) {
        int A, B;
        scanf("%d %d", &A, &B);

        Matrix piece;
        createMatrix(A, B, &piece);

        readMatrix(&piece, A, B);

        int found = 0;
        for (int i = 0; i <= N - A && !found; i++) {
            for (int j = 0; j <= M - B && !found; j++) {
                int match = 1;
                for (int p = 0; p < A && match; p++) {
                    for (int q = 0; q < B && match; q++) {
                        if (ELMT(piece, p, q) != ELMT(puzzle, i + p, j + q)) {
                            match = 0;
                        }
                    }
                }
                if (match) {
                    found = 1;
                }
            }
        }

        if (!found) {
            solvable = 0;
        }
    }

    if (solvable) {
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    return 0;
}

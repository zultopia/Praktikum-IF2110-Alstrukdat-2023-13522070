/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix board;
    int i, j;
    createMatrix(8, 8, &board);

    readMatrix(&board, 8, 8);

    int blackCount = 0;
    int whiteCount = 0;

    // Menghitung jumlah bidak pada sel hitam dan putih
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) { // Sel hitam
                blackCount += ELMT(board, i, j);
            } else { // Sel putih
                whiteCount += ELMT(board, i, j);
            }
        }
    }

    // Menampilkan hasil
    printf("%d %d\n", blackCount, whiteCount);

    return 0;
}

/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "listdin.h"

int main() {
    int C, Q;
    scanf("%d", &C);  // Kapasitas array A
    scanf("%d", &Q);  // Jumlah query

    ListDin A;
    CreateListDin(&A, 100000);  // Inisialisasi array A

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int X;
            scanf("%d", &X);

            // Hapus nilai-nilai yang lebih kecil dari X
            while (!isEmpty(A) && ELMT(A, NEFF(A) - 1) < X) {
                int val;
                deleteLast(&A, &val);
            }

            // Masukkan nilai X ke dalam array A
            insertLast(&A, X);
        } else if (type == 2) {
            // Tampilkan banyaknya elemen array A dan isi array A
            printf("%d\n", NEFF(A));
            printList(A);
            printf("\n");
        }
    }
}

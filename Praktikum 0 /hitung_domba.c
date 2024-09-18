#include <stdio.h>

int main() {
    int M, N;
    int i = 1;
    
    // Meminta pengguna memasukkan jumlah domba (M) dan angka kesayangan (N)
    scanf("%d", &M);
    scanf("%d", &N);

    // Melakukan perulangan dari 1 hingga M
    for (i = 1; i <= M; i++) {
        // Cek apakah i adalah kelipatan dari N
        if (i % N == 0) {
            printf("happy\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}

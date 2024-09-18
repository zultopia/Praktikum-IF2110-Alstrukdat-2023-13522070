#include <stdio.h>

int main() {
    int num, sum = 0;

    // Meminta pengguna memasukkan integer
    printf("");
    scanf("%d", &num);

    // Menghitung jumlah digit
    while (num != 0) {
        sum += num % 10;  // Menambahkan digit terakhir ke sum
        num /= 10;       // Menghapus digit terakhir dari integer
    }

    // Menampilkan hasil
    printf("%d\n", sum);

    return 0;
}

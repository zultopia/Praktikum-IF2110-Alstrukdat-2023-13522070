#include <stdio.h>

int isKembar(int num) {
    int lastDigit = num % 10;
    while (num > 0) {
        int digit = num % 10;
        if (digit != lastDigit) {
            return 0;  // Bukan bilangan kembar
        }
        num /= 10;
    }
    return 1;  // Bilangan kembar
}

int main() {
    int a, b;
    int count = 0;
    int i = a;

    // Meminta pengguna memasukkan dua bilangan a dan b
    scanf("%d", &a);
    scanf("%d", &b);

    // Mencari dan menghitung bilangan kembar di antara a dan b inklusif
    for (i = a; i <= b; i++) {
        if (isKembar(i)) {
            count++;
        }
    }

    // Menampilkan jumlah bilangan kembar
    printf("%d\n",count);

    return 0;
}

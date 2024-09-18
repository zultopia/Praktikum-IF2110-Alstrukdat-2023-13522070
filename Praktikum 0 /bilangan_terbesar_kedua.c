#include <stdio.h>

int main() {
    int n;
    
    // Meminta pengguna memasukkan jumlah bilangan
    scanf("%d", &n);

    int largest = -2147483647;  // Inisialisasi dengan bilangan terkecil yang mungkin
    int secondLargest = -2147483647; // Inisialisasi dengan bilangan terkecil yang mungkin
    int i = 0;

    // Menerima n buah bilangan dan mencari bilangan terbesar dan terbesar kedua
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num != largest) {
            secondLargest = num;
        }
    }

    // Menampilkan bilangan terbesar kedua
    if (secondLargest != -2147483647) {
        printf("%d\n", secondLargest);
    } else {
        printf("Tidak ada bilangan terbesar kedua.\n");
    }

    return 0;
}

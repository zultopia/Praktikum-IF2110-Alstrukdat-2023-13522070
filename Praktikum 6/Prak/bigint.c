/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "stack.h"

#define MARK '.'

Word listWords[100];
int countWord = 0;

int main() {
    START();
    while (currentChar != MARK) {
        ADVWORD();
        listWords[countWord] = currentWord;
        countWord++;
    }

    // Inisialisasi stack untuk menyimpan digit-digit bigint
    Stack s1, s2, result;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&result);

    // Mengisi stack s1 dengan digit-digit dari listWords[0]
    for (int i = 0; i < listWords[0].Length; i++) {
        Push(&s1, listWords[0].TabWord[i] - '0');
    }

    // Mengisi stack s2 dengan digit-digit dari listWords[1]
    for (int i = 0; i < listWords[1].Length; i++) {
        Push(&s2, listWords[1].TabWord[i] - '0');
    }

    int carry = 0;

    // Melakukan perhitungan selisih
    while (!IsEmpty(s1) || !IsEmpty(s2)) {
        int digit1 = 0;
        int digit2 = 0;
        if (!IsEmpty(s1)) {
            Pop(&s1, &digit1);
        }
        if (!IsEmpty(s2)) {
            Pop(&s2, &digit2);
        }

        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        Push(&result, diff);
    }

    // Menampilkan hasil selisih
    boolean leadingZero = true;
    while (!IsEmpty(result)) {
        int digit;
        Pop(&result, &digit);
        if (digit != 0) {
            leadingZero = false;
        }
        if (!leadingZero) {
            printf("%d", digit);
        }
    }
    if (leadingZero) {
        printf("0");
    }

    printf("\n");

    return 0;
}
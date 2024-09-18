/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "wordmachine.h"

// Fungsi untuk menghitung anagram
int countAnagrams(char *word1, char *word2) {
    int charCount[26] = {0};

    // Menghitung jumlah kemunculan setiap huruf dalam word1
    for (int i = 0; word1[i] != '\0'; i++) {
        charCount[word1[i] - 'a']++;
    }

    // Mengurangi jumlah kemunculan setiap huruf dalam word2
    for (int i = 0; word2[i] != '\0'; i++) {
        charCount[word2[i] - 'a']--;
    }

    // Memeriksa apakah kedua kata adalah anagram
    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return 0; // Bukan anagram
        }
    }

    return 1; // Anagram
}

int main() {
    STARTWORD(); 

    char kata[100][100]; // Maksimal 100 kata dengan masing-masing panjang maksimal 20
    int jumlahKata = 0;

    while (!EndWord) {
        if (jumlahKata < 100) {
            for (int i = 0; i < currentWord.Length; i++) {
                kata[jumlahKata][i] = currentWord.TabWord[i];
            }
            kata[jumlahKata][currentWord.Length] = '\0';
            jumlahKata++;
        }
        ADVWORD(); 
    }

    int jumlahAnagram = 0;

    for (int i = 0; i < jumlahKata; i++) {
        for (int j = i + 1; j < jumlahKata; j++) {
            if (countAnagrams(kata[i], kata[j])) {
                jumlahAnagram++;
            }
        }
    }
    printf("%d\n", jumlahAnagram);

    return 0;
}
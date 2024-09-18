/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>

int stringLength(char *s) {
    int result = 0;
    int i = 0;
    while (s[i] != '\0') {
        ++result;
        ++i;
    }
    return result;
}

int main() {
    char command[20]; 
    int N;

    scanf("%d %s.", &N, command);

    int commandLength = stringLength(command);

    if (commandLength == 7) {
        if (command[0] == 'M' && command[1] == 'O' && command[2] == 'V' && command[3] == 'E' && command[4] == 'U' && command[5] == 'P') {
            printf("Moving %d square upwards\n", N);
        }
    } else if (commandLength == 9) {
        if (command[0] == 'M' && command[1] == 'O' && command[2] == 'V' && command[3] == 'E' && command[4] == 'D' && command[5] == 'O' && command[6] == 'W' && command[7] == 'N') {
            printf("Moving %d square downwards\n", N);
        }
        else if (command[0] == 'M' && command[1] == 'O' && command[2] == 'V' && command[3] == 'E' && command[4] == 'L' && command[5] == 'E' && command[6] == 'F' && command[7] == 'T') {
            printf("Moving %d square leftwards\n", N);
        } 
    } else if (command[0] == 'M' && command[1] == 'O' && command[2] == 'V' && command[3] == 'E' && command[4] == 'R' && command[5] == 'I' && command[6] == 'G' && command[7] == 'H' && command[8] == 'T') {
            printf("Moving %d square rightwards\n", N);
        }
    return 0;
}

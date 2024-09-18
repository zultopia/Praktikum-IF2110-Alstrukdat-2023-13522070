/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <math.h>
#include "garis.h"
#include "point.h"

int main() {
    int b;
    scanf("%d", &b);

    POINT P1, P2;
    scanf("%f %f\n", &P1.X, &P1.Y);
    scanf("%f %f\n", &P2.X, &P2.Y);

    int n;
    scanf("%d\n", &n);

    GARIS garisSerigala;
    garisSerigala.PAw = P1;
    garisSerigala.PAkh = P2;

    int jumlahSelamat = 0;
    int i;
    for (i = 0; i < n; i++) {
        POINT biriBiri;
        scanf("%f %f\n", &biriBiri.X, &biriBiri.Y);

        float d = JarakGARIS(garisSerigala, biriBiri);
        if (d <= b) {
            jumlahSelamat++;
        }
    }

    printf("%d\n", jumlahSelamat);

    return 0;
}
/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <math.h>
#include "datetime.h"

int GetMaxDay(int M, int Y) {
    int maxDay;

    if (M == 2) {
        if ((Y % 400 == 0) || ((Y % 100 != 0) && (Y % 4 == 0))) {
            maxDay = 29; // Tahun kabisat, Februari memiliki 29 hari.
        } else {
            maxDay = 28; // Bukan tahun kabisat, Februari memiliki 28 hari.
        }
    } else if (M == 4 || M == 6 || M == 9 || M == 11) {
        maxDay = 30; // April, Juni, September, November memiliki 30 hari.
    } else {
        maxDay = 31; // Januari, Maret, Mei, Juli, Agustus, Oktober, Desember memiliki 31 hari.
    }

    return maxDay;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    if (M < 1 || M > 12 || h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
        return false;
    }

    int maxDay = GetMaxDay(M, Y);
    if (D < 1 || D > maxDay) {
        return false;
    }

    return true;
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    if (IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
        Day(*D) = DD;
        Month(*D) = MM;
        Year(*D) = YYYY;
        CreateTime(&Time(*D), hh, mm, ss);
    }
}

void BacaDATETIME(DATETIME *D) {
    int DD, MM, YYYY, hh, mm, ss;
    boolean valid = false;

    while (!valid) {
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
        valid = IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss);
        if (!valid) {
            printf("DATETIME tidak valid\n");
        }
    }

    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2) {
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) &&
            Hour(Time(D1)) == Hour(Time(D2)) && Minute(Time(D1)) == Minute(Time(D2)) &&
            Second(Time(D1)) == Second(Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2) {
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2) {
    if (Year(D1) < Year(D2)) {
        return true;
    } else if (Year(D1) > Year(D2)) {
        return false;
    } else if (Month(D1) < Month(D2)) {
        return true;
    } else if (Month(D1) > Month(D2)) {
        return false;
    } else if (Day(D1) < Day(D2)) {
        return true;
    } else if (Day(D1) > Day(D2)) {
        return false;
    } else if (Hour(Time(D1)) < Hour(Time(D2))) {
        return true;
    } else if (Hour(Time(D1)) > Hour(Time(D2))) {
        return false;
    } else if (Minute(Time(D1)) < Minute(Time(D2))) {
        return true;
    } else if (Minute(Time(D1)) > Minute(Time(D2))) {
        return false;
    } else if (Second(Time(D1)) < Second(Time(D2))) {
        return true;
    } else {
        return false;
    }
}

boolean DGT(DATETIME D1, DATETIME D2) {
    return !DLT(D1, D2) && DNEQ(D1, D2);
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    int second, days;
    second = TIMEToDetik(Time(D)) + N;
    days = second / 86400 + Day(D);

    while (days > GetMaxDay(Month(D), Year(D))) {
        days -= GetMaxDay(Month(D), Year(D));
        Month(D) += 1;

        if (Month(D) > 12) {
            Month(D) = Month(D) % 12;
            Year(D) += 1;
        }
    }
    Day(D) = days;
    Time(D) = DetikToTIME(second % 86400);

    return D;
}
/* Mengirim salinan D dengan detik ditambah N */

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    int second, days;
    second = TIMEToDetik(Time(D)) - N;

    if (second < 0) {
        days = second / 86400 + Day(D) - 1;
        while (days < 1) {
            Month(D) -= 1;

            if (Month(D) < 1) {
                Month(D) = 12;
                Year(D) -= 1;
            }

            days += GetMaxDay(Month(D), Year(D));
        }
        Time(D) = DetikToTIME(86400 + (second % 86400));
        Day(D) = days;
    } else {
        Time(D) = DetikToTIME(second);
    }

    return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
    long int durasi = 0;
    long int hariAw = Day(DAw);
    long int bulanAw = Month(DAw);
    long int tahunAw = Year(DAw);
    long int jamAw = Hour(Time(DAw));
    long int menitAw = Minute(Time(DAw));
    long int detikAw = Second(Time(DAw));
    long int hariAk = Day(DAkh);
    long int bulanAk = Month(DAkh);
    long int tahunAk = Year(DAkh);
    long int jamAk = Hour(Time(DAkh));
    long int menitAk = Minute(Time(DAkh));
    long int detikAk = Second(Time(DAkh));
    long int hariMax;

    while (tahunAw < tahunAk || bulanAw < bulanAk || hariAw < hariAk ||
           jamAw < jamAk || menitAw < menitAk || detikAw < detikAk) {
        hariMax = GetMaxDay(bulanAw, tahunAw);
        durasi++;
        detikAw++;
        if (detikAw == 60) {
            detikAw = 0;
            menitAw++;
            if (menitAw == 60) {
                menitAw = 0;
                jamAw++;
                if (jamAw == 24) {
                    jamAw = 0;
                    hariAw++;
                    if (hariAw > hariMax) {
                        hariAw = 1;
                        bulanAw++;
                        if (bulanAw > 12) {
                            bulanAw = 1;
                            tahunAw++;
                        }
                    }
                }
            }
        }
    }

    return durasi;
}
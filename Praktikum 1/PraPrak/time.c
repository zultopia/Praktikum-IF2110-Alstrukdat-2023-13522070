/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "time.h"

boolean IsTIMEValid(int H, int M, int S) {
    return (H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59);
}

void CreateTime(TIME *T, int HH, int MM, int SS) {
    if (IsTIMEValid(HH, MM, SS)) {
        T->HH = HH;
        T->MM = MM;
        T->SS = SS;
    }
}

void BacaTIME(TIME *T) {
    int HH, MM, SS;
    do {
        scanf("%d %d %d", &HH, &MM, &SS);
        if (!IsTIMEValid(HH, MM, SS)) {
            printf("Jam tidak valid\n");
        }
    } while (!IsTIMEValid(HH, MM, SS));
    CreateTime(T, HH, MM, SS);
}

void TulisTIME(TIME T) {
    printf("%02d:%02d:%02d", T.HH, T.MM, T.SS);
}

long TIMEToDetik(TIME T) {
    return (3600 * T.HH + 60 * T.MM + T.SS);
}

TIME DetikToTIME(long N) {
    N %= 86400;
    int HH = N / 3600;
    int MM = (N % 3600) / 60;
    int SS = N % 60;
    TIME T;
    CreateTime(&T, HH, MM, SS);
    return T;
}

boolean TEQ(TIME T1, TIME T2) {
    return (T1.HH == T2.HH && T1.MM == T2.MM && T1.SS == T2.SS);
}

boolean TNEQ(TIME T1, TIME T2) {
    return !TEQ(T1, T2);
}

boolean TLT(TIME T1, TIME T2) {
    if (T1.HH < T2.HH) return true;
    if (T1.HH > T2.HH) return false;
    if (T1.MM < T2.MM) return true;
    if (T1.MM > T2.MM) return false;
    return T1.SS < T2.SS;
}

boolean TGT(TIME T1, TIME T2) {
    return !TLT(T1, T2) && !TEQ(T1, T2);
}

TIME NextDetik(TIME T) {
    long detik = TIMEToDetik(T);
    detik++;
    if (detik >= 86400) {
        detik -= 86400;
    }
    return DetikToTIME(detik);
}

TIME NextNDetik(TIME T, int N) {
    long detik = TIMEToDetik(T);
    detik += N;
    detik %= 86400;
    return DetikToTIME(detik);
}

TIME PrevDetik(TIME T) {
    long detik = TIMEToDetik(T);
    if (detik == 0) {
        detik = 86400;
    }
    detik--;
    return DetikToTIME(detik);
}

TIME PrevNDetik(TIME T, int N) {
    long detik = TIMEToDetik(T);
    detik -= N;
    if (detik < 0) {
        detik += 86400;
    }
    return DetikToTIME(detik);
}

long Durasi(TIME TAw, TIME TAkh) {
    long detikAwal = TIMEToDetik(TAw);
    long detikAkhir = TIMEToDetik(TAkh);
    if (detikAkhir < detikAwal) {
        detikAkhir += 86400; // Menambah 1 hari dalam detik
    }
    return detikAkhir - detikAwal;
}
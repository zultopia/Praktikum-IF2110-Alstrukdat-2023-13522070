/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include <math.h>
#include "point.h"

void CreatePoint (POINT * P, float X, float Y){
  Absis(*P) = X;
  Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2) {
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ(POINT P1, POINT P2) {
    return (!EQ(P1, P2));
}

boolean IsOrigin(POINT P) {
    return (EQ(P, (POINT){0, 0}));
}

boolean IsOnSbX(POINT P) {
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P) {
    return Absis(P) == 0;
}

int Kuadran(POINT P) {
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    } else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    } else if (Absis(P) > 0 && Ordinat(P) < 0) {
        return 4;
    }
    return -1; // P ada di salah satu sumbu atau titik origin
}

POINT NextX(POINT P) {
    POINT NewP;
    CreatePoint(&NewP, Absis(P) + 1, Ordinat(P));
    return NewP;
}

POINT NextY(POINT P) {
    POINT NewP;
    CreatePoint(&NewP, Absis(P), Ordinat(P) + 1);
    return NewP;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
    POINT NewP;
    CreatePoint(&NewP, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return NewP;
}

POINT MirrorOf(POINT P, boolean SbX) {
    if (SbX) {
        return (POINT){Absis(P), -Ordinat(P)};
    } else {
        return (POINT){-Absis(P), Ordinat(P)};
    }
}

float Jarak0(POINT P) {
    return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang(POINT P1, POINT P2) {
    float deltaX = Absis(P2) - Absis(P1);
    float deltaY = Ordinat(P2) - Ordinat(P1);
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

void Geser(POINT *P, float deltaX, float deltaY) {
    *P = PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX(POINT *P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P) {
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX) {
    *P = MirrorOf(*P, SbX);
}

void Putar(POINT *P, float Sudut) {
    Sudut *= -1;
    float radian = Sudut * (M_PI / 180);
    float newX = Absis(*P) * cos(radian) - Ordinat(*P) * sin(radian);
    float newY = Absis(*P) * sin(radian) + Ordinat(*P) * cos(radian);
    CreatePoint(P, newX, newY);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2) {
    float a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    float b = Ordinat(P1) - a * Absis(P1);
    int a_integer = (int)a;
    int b_integer = (int)b;
    
    printf("(%d,%d)", a_integer, b_integer);
}

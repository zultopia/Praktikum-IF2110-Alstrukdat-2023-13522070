/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include <stdio.h>
#include "garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2) {
  PAwal(*L) = P1;
  PAkhir(*L) = P2;
}
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L) {
  POINT a, b;
  BacaPOINT(&a);
  BacaPOINT(&b);
  while(EQ(a, b)){
    printf("Garis tidak valid\n");
    BacaPOINT(&a);
    BacaPOINT(&b);
  }
  CreateGaris(L, a, b);
}
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
void TulisGARIS (GARIS L){
  printf("(");
  TulisPOINT(PAwal(L));
  printf(",");
  TulisPOINT(PAkhir(L));
  printf(")");
}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
  //rumus panjang garis sqrt(pow((Absis(P1) - Absis(P2)), 2) + pow((Ordinat(P1) - Ordinat(P2)), 2));
  return Panjang(PAwal(L), PAkhir(L));
} 
/* Menghitung panjang garis L : berikan rumusnya */
float Gradien (GARIS L){
  float x1 = Absis(PAwal(L));
  float x2 = Absis(PAkhir(L));
  float y1 = Ordinat(PAwal(L));
  float y2 = Ordinat(PAkhir(L));
  float hasil = (y2-y1)/(x2-x1);
  return hasil;
} 
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
void GeserGARIS (GARIS * L, float deltaX, float deltaY){
  Geser(&PAwal(*L), deltaX, deltaY);
  Geser(&PAkhir(*L), deltaX, deltaY);
}
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
  return (Gradien(L1) * Gradien(L2) == -1);
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
boolean IsSejajar (GARIS L1, GARIS L2){
  return (Gradien(L1) == Gradien(L2));
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */

/* *** Kelompok operasi garis dan point *** */
float JarakGARIS(GARIS L, POINT P) {
    float a, b, c, d;
    a = Gradien(L);
    b = -1;
    c = (a * -Absis(PAwal(L))) + (b * -Ordinat(PAwal(L)));
    d = fabs((a * Absis(P)) + (b * Ordinat(P)) + c);

    return (d / sqrt((a * a) + (b * b)));
}
/* Menghasilkan jarak terdekat antara titik P dan garis L */
/* Bentuklah persamaan dari garis L menjadi ax + by + c = 0 */
/* Jarak terdekat dari titik P ke garis L dapat didefinisikan sebagai d = |a * x + b * y + c| / akar kuadrat dari a * a + b * b */

boolean IsPointMemenuhiGaris(GARIS L, POINT P) {
    return (JarakGARIS(L, P) == 0);
}
/* Menghasilkan true jika  titik P terletak di garis L */
/* Bentuklah persamaan dari garis L menjadi ax + by + c = 0 */
/* Titik P terletak di garis L jika dan hanya jika P memenuhi persamaan garis L, yaitu ax + by + c = 0 */
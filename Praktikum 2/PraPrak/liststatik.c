/*
Nama    : Marzuli Suhada M
NIM     : 13522070
*/

#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
void CreateListStatik(ListStatik *l) {
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
int listLength(ListStatik l) {
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    int count = 0;
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        if (ELMT(l, i) != MARK) {
            count++;
        }
    }
    return count;
}

IdxType getFirstIdx(ListStatik l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l) {
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    int i = CAPACITY - 1;
    while (i >= IDX_MIN && ELMT(l, i) == MARK) {
        i--;
    }
    return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= IDX_MIN) && (i < CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    return (i >= IDX_MIN) && (i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListStatik l) {
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l) {
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void readList(ListStatik *l) {
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    CreateListStatik(l);
    int n;
    scanf("%d", &n);
    while(n < 0 || n > CAPACITY){
        scanf("%d", &n);
        }
    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        ELMT(*l, i) = x;
    }
}

void printList(ListStatik l) {
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    
    if(isEmpty(l)){
        printf("[]");
    }else{
        printf("[");
        for(int i = 0; i < listLength(l); i++){
            printf("%d", ELMT(l, i));
            if(i != listLength(l) - 1){
                printf(",");
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    ListStatik l;
    CreateListStatik(&l);
    if(plus){
        for(int i = 0; i < listLength(l1); i++){
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }else{
        for(int i = 0; i < listLength(l1); i++){
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
       elemennya sama */
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    
    IdxType i;
    for (i = IDX_MIN; i <= getLastIdx(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }
    
    return true;
}

/* ********** SEARCHING ********** */
int indexOf(ListStatik l, ElType val) {
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
    /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    /* Skema Searching yang digunakan bebas */
    IdxType i;
    for (i = IDX_MIN; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
    /* I.S. List l tidak kosong */
    /* F.S. Max berisi nilai terbesar dalam l;
            Min berisi nilai terkecil dalam l */
    *max = ELMT(l, getFirstIdx(l));
    *min = ELMT(l, getFirstIdx(l));
    
    IdxType i;
    for (i = getFirstIdx(l) + 1; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* Menambahkan elemen terakhir */
void insertFirst(ListStatik *l, ElType val) {
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    if (!isFull(*l)) {
        IdxType i;
        for (i = getLastIdx(*l); i >= getFirstIdx(*l); i--) {
            ELMT(*l, i + 1) = ELMT(*l, i);
        }
        ELMT(*l, getFirstIdx(*l)) = val;
    }
}

/* Menambahkan elemen pada index tertentu */
void insertAt(ListStatik *l, ElType val, IdxType idx) {
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    if (!isFull(*l) && isIdxValid(*l, idx)) {
        IdxType i;
        for (i = getLastIdx(*l); i >= idx; i--) {
            ELMT(*l, i + 1) = ELMT(*l, i);
        }
        ELMT(*l, idx) = val;
    }
}

/* Menambahkan elemen terakhir */
void insertLast(ListStatik *l, ElType val) {
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    if (!isFull(*l)) {
        ELMT(*l, getLastIdx(*l) + 1) = val;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* Menghapus elemen pertama */
void deleteFirst(ListStatik *l, ElType *val) {
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan,
            Banyaknya elemen List berkurang satu,
            List l mungkin menjadi kosong */
    if (!isEmpty(*l)) {
        *val = ELMT(*l, getFirstIdx(*l));
        IdxType i;
        for (i = getFirstIdx(*l) + 1; i <= getLastIdx(*l); i++) {
            ELMT(*l, i - 1) = ELMT(*l, i);
        }
        ELMT(*l, getLastIdx(*l)) = MARK;
    }
}

/* Menghapus elemen pada index tertentu */
void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan,
            Banyaknya elemen List berkurang satu,
            List l mungkin menjadi kosong */
    if (!isEmpty(*l) && isIdxEff(*l, idx)) {
        *val = ELMT(*l, idx);
        IdxType i;
        for (i = idx + 1; i <= getLastIdx(*l); i++) {
            ELMT(*l, i - 1) = ELMT(*l, i);
        }
        ELMT(*l, getLastIdx(*l)) = MARK;
    }
}

/* Menghapus elemen terakhir */
void deleteLast(ListStatik *l, ElType *val) {
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan,
            Banyaknya elemen List berkurang satu,
            List l mungkin menjadi kosong */
    if (!isEmpty(*l)) {
        *val = ELMT(*l, getLastIdx(*l));
        ELMT(*l, getLastIdx(*l)) = MARK;
    }
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    IdxType i, j;
    ElType temp;
    int n = listLength(*l);
    
    for (i = getFirstIdx(*l); i < getLastIdx(*l); i++) {
        for (j = getFirstIdx(*l); j < getLastIdx(*l); j++) {
            if ((asc && ELMT(*l, j) > ELMT(*l, j + 1)) || (!asc && ELMT(*l, j) < ELMT(*l, j + 1))) {
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j + 1);
                ELMT(*l, j + 1) = temp;
            }
        }
    }
}

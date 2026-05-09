#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

// Deklarasi struktur simpul
struct Node {
    int INFO;
    struct Node *LINK;
};
typedef struct Node Simpul;

Simpul *P, *FIRST, *LAST, *Q;
int X;

// Fungsi membuat sebuah simpul baru
void BUAT_SIMPUL(int X) {
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P != NULL) {
        P->INFO = X;
    } else {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        cin.get();
        exit(1);
    }
}

// Fungsi membuat simpul awal
void AWAL() {
    FIRST = P;
    LAST  = P;
    P->LINK = NULL;
}

// Fungsi menginsert simpul di sebelah kanan
void INSERTKANAN() {
    LAST->LINK = P;
    LAST       = P;
    P->LINK    = NULL;
}

// Fungsi mencetak isi seluruh simpul
void CETAK() {
    Q = FIRST;
    while(Q != NULL) {
        cout << Q->INFO << " ";
        Q = Q->LINK;
    }
}

int main() {
    int n, i;

    cout << "Masukkan jumlah data : ";
    cin >> n;

    // Input data pertama -> buat simpul awal
    cout << "Masukkan data ke-1   : ";
    cin >> X;
    BUAT_SIMPUL(X);
    AWAL();

    // Input data ke-2 dst -> insert kanan
    for(i = 2; i <= n; i++) {
        cout << "Masukkan data ke-" << i << "   : ";
        cin >> X;
        BUAT_SIMPUL(X);
        INSERTKANAN();
    }

    // Tampilkan sebelum insert kanan tambahan
    cout << "\nNilai Sebelum Dilakukan Insert Kanan :  ";
    CETAK();
    cout << endl;

    // Input 1 data tambahan lalu insert kanan
    cout << "\nMasukkan data baru (Insert Kanan)    : ";
    cin >> X;
    BUAT_SIMPUL(X);
    INSERTKANAN();

    // Tampilkan setelah insert kanan
    cout << "Nilai Setelah Dilakukan Insert Kanan :  ";
    CETAK();
    cout << endl;

    cin.get();
}
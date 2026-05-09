#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

// ============================================================
// DEKLARASI STRUKTUR DATA
// ============================================================

// 1. Deklarasi struktur data (node)
struct Node {
    string nama;
    int    umur;
    Node  *LINK;
};

// Pointer global
Node *FIRST = NULL;
Node *LAST  = NULL;
Node *P     = NULL;

// ============================================================
// DEKLARASI FUNGSI / PROSEDUR
// ============================================================

// Membuat simpul baru
void BUAT_SIMPUL(string nama, int umur) {
    P = new Node;
    if (P != NULL) {
        P->nama = nama;
        P->umur = umur;
        P->LINK = NULL;
    } else {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        exit(1);
    }
}

// Membuat simpul pertama (awal)
void AWAL() {
    FIRST = P;
    LAST  = P;
    P->LINK = NULL;
}

// Insert simpul di sebelah kanan (akhir list)
void INSERTKANAN() {
    LAST->LINK = P;
    LAST       = P;
    P->LINK    = NULL;
}

// ============================================================
// CETAK : menampilkan semua simpul dalam format satu baris
// Format: Nama : Fanny --10   Tiara --63   dst
// ============================================================
void CETAK_HORIZONTAL() {
    Node *Q = FIRST;
    cout << "Nama  :  ";
    while (Q != NULL) {
        // Pad nama agar rata
        cout << Q->nama << " --" << Q->umur;
        if (Q->LINK != NULL) cout << "   ";
        Q = Q->LINK;
    }
    cout << endl;
}

// ============================================================
// CETAK vertikal: Nama & Umur : xxx - yy
// ============================================================
void CETAK_VERTIKAL() {
    Node *Q = FIRST;
    while (Q != NULL) {
        cout << "Nama & Umur : " << Q->nama << " - " << Q->umur << endl;
        Q = Q->LINK;
    }
}

// ============================================================
// HAPUS NODE berdasarkan nama dan umur
// ============================================================
void HAPUS_NODE(string nama, int umur) {
    if (FIRST == NULL) {
        cout << "List Kosong!" << endl;
        return;
    }

    Node *hapus = NULL;
    Node *prev  = NULL;
    Node *curr  = FIRST;

    // Cari node yang akan dihapus
    while (curr != NULL) {
        if (curr->nama == nama && curr->umur == umur) {
            hapus = curr;
            break;
        }
        prev = curr;
        curr = curr->LINK;
    }

    if (hapus == NULL) {
        cout << "Data " << nama << " -- " << umur << " tidak ditemukan!" << endl;
        return;
    }

    // Hapus node
    if (prev == NULL) {
        // Node yang dihapus adalah FIRST
        FIRST = hapus->LINK;
    } else {
        prev->LINK = hapus->LINK;
    }

    // Update LAST jika node yang dihapus adalah node terakhir
    if (hapus == LAST) {
        LAST = prev;
    }

    delete hapus;
}

// ============================================================
// GARIS PEMISAH
// ============================================================
void GARIS() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// ============================================================
// MAIN PROGRAM
// ============================================================
int main() {

    // Data: Fanny-10, Tiara-63, Ilham-28, Cinthya-66, Candra-22
    string arrNama[] = {"Fanny", "Tiara", "Ilham", "Cinthya", "Candra"};
    int    arrUmur[] = {10, 63, 28, 66, 22};
    int    n         = 5;

    // Bangun Linked List
    BUAT_SIMPUL(arrNama[0], arrUmur[0]);
    AWAL();
    for (int i = 1; i < n; i++) {
        BUAT_SIMPUL(arrNama[i], arrUmur[i]);
        INSERTKANAN();
    }

    // ---- TAMPILKAN DATA SEBELUM PENGHAPUSAN ----
    CETAK_VERTIKAL();
    cout << endl;
    GARIS();
    CETAK_HORIZONTAL();
    GARIS();
    cout << endl;

    // ---- HAPUS NODE Tiara -- 63 ----
    HAPUS_NODE("Tiara", 63);

    // ---- TAMPILKAN DATA SETELAH PENGHAPUSAN ----
    GARIS();
    // Tampilkan dalam satu baris tanpa label "Nama :"
    Node *Q = FIRST;
    while (Q != NULL) {
        cout << Q->nama << " --" << Q->umur;
        if (Q->LINK != NULL) cout << "   ";
        Q = Q->LINK;
    }
    cout << endl;

    cin.get();
}
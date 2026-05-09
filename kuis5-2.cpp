#include <iostream>
#include <string>
using namespace std;

// 1. Deklarasi struktur data barang
typedef struct {
    string kode_barang;
    string nama_barang;
    int jumlah_stok;
} DataBarang;

// 2. Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    DataBarang Kontainer;
    alamatelm next;
} elemen;

// 3. Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} Queue;

// 4. Fungsi membuat queue kosong
void buatQUkosong(Queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// 5. Fungsi mengecek apakah queue kosong
int isKosong(Queue Q) {
    bool hasil = false;
    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

// 6. Fungsi menghitung jumlah elemen queue
int jmlElemen(Queue Q) {
    int hasil = 0;
    if (Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;
        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

// 7. Fungsi memasukkan elemen ke dalam queue
void add(string kode_barang, string nama_barang, int jumlah_stok, Queue *Q) {
    elemen *info;
    info = new elemen;
    info->Kontainer.kode_barang = kode_barang;
    info->Kontainer.nama_barang = nama_barang;
    info->Kontainer.jumlah_stok = jumlah_stok;
    info->next = NULL;
    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
    info = NULL;
}

// 8. Fungsi mengeluarkan elemen dari queue (distribusi barang terdepan)
void del(Queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;
        cout << ">> Mendistribusikan barang: ["
             << hapus->Kontainer.kode_barang << "] "
             << hapus->Kontainer.nama_barang
             << " - Stok: " << hapus->Kontainer.jumlah_stok << endl;
        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        } else {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        delete hapus;
    }
}

// 9. Fungsi menampilkan isi queue
void CetakQueue(Queue Q) {
    if (Q.first != NULL) {
        cout << "======= DAFTAR ANTRIAN STOK BARANG DI GUDANG =======" << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL) {
            cout << "-----------------------------------------------------" << endl;
            cout << "Elemen ke     : " << i << endl;
            cout << "Kode Barang   : " << bantu->Kontainer.kode_barang << endl;
            cout << "Nama Barang   : " << bantu->Kontainer.nama_barang << endl;
            cout << "Jumlah Stok   : " << bantu->Kontainer.jumlah_stok << endl;
            bantu = bantu->next;
            i = i + 1;
        }
        cout << "=====================================================" << endl;
        cout << "Total Barang dalam Antrian: " << jmlElemen(Q) << endl;
    } else {
        cout << ">> Queue Kosong (Tidak ada barang dalam antrian)" << endl;
    }
}

int main() {
    Queue Q;

    // Inisialisasi antrian
    buatQUkosong(&Q);

    // Cetak antrian saat masih kosong
    cout << "========== KONDISI AWAL ANTRIAN ==========" << endl;
    CetakQueue(Q);
    cout << endl;

    // Tambahkan 5 data barang ke dalam antrian
    cout << "========== MENAMBAHKAN 5 DATA BARANG ==========" << endl;
    add("BRG001", "Beras Premium", 150, &Q);
    add("BRG002", "Minyak Goreng",  200, &Q);
    add("BRG003", "Gula Pasir",     100, &Q);
    add("BRG004", "Tepung Terigu",  75, &Q);
    add("BRG005", "Garam Dapur",    300, &Q);
    cout << ">> 5 data barang berhasil ditambahkan!" << endl;
    cout << endl;

    // Tampilkan seluruh daftar barang yang mengantre
    CetakQueue(Q);
    cout << endl;

    // Lakukan 2 kali penghapusan (del) untuk mendistribusikan barang terdepan
    cout << "========== DISTRIBUSI BARANG (2x DEL) ==========" << endl;
    del(&Q);
    cout << endl;

    // Tampilkan kondisi akhir antrian barang di gudang
    cout << "========== KONDISI AKHIR ANTRIAN BARANG DI GUDANG ==========" << endl;
    CetakQueue(Q);

    return 0;
}
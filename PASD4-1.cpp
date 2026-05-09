#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

// Deklarasi queue menggunakan array
typedef struct {
    int first;
    int last;
    NilaiMK Dat[10];
} Queue;

// Deklarasi fungsi membuat queue kosong
void buatQUkosong(Queue *Q) {
    (*Q).first = -1;
    (*Q).last  = -1;
}

// Fungsi TRUE apabila queue Kosong
bool isKosong(Queue Q) {
    bool hasil = false;
    if (Q.first == -1) {
        hasil = true;
    }
    return hasil;
}

// Fungsi TRUE apabila queue Penuh
bool isPenuh(Queue Q) {
    bool hasil = false;
    if (Q.last == 9) {
        hasil = true;
    }
    return hasil;
}

// Prosedur ADD (Enqueue) - memasukkan elemen
void ADD(string npm, string nama_mhs, double nilai, Queue *Q) {
    if (isKosong(*Q) == 1) {
        // Jika Queue Kosong
        (*Q).first = 0;
        (*Q).last  = 0;
        (*Q).Dat[0].npm       = npm;
        (*Q).Dat[0].nama_mhs  = nama_mhs;
        (*Q).Dat[0].nilai     = nilai;
    } else {
        if (isPenuh(*Q) != 1) {
            // Jika Queue Tidak Kosong dan Tidak Penuh
            (*Q).last = (*Q).last + 1;
            (*Q).Dat[(*Q).last].npm      = npm;
            (*Q).Dat[(*Q).last].nama_mhs = nama_mhs;
            (*Q).Dat[(*Q).last].nilai    = nilai;
        } else {
            // Jika Queue PENUH
            cout << "QUEUE PENUH" << endl;
        }
    }
}

// Prosedur DEL (Dequeue) - mengeluarkan elemen terdepan
void DEL(Queue *Q) {
    if ((*Q).last == 0) {
        (*Q).first = -1;
        (*Q).last  = -1;
    } else {
        // Menggeser Elemen Ke Depan
        int i;
        for (i = ((*Q).first + 1); i <= (*Q).last; i++) {
            (*Q).Dat[i-1].npm      = (*Q).Dat[i].npm;
            (*Q).Dat[i-1].nama_mhs = (*Q).Dat[i].nama_mhs;
            (*Q).Dat[i-1].nilai    = (*Q).Dat[i].nilai;
        }
        (*Q).last = (*Q).last - 1;
    }
}

// Prosedur menampilkan isi queue
void CetakQueue(Queue Q) {
    if (Q.first != -1) {
        cout << " MENAMPILKAN QUEUE " << endl;
        cout << " ~~~~~~~~~~~~~~~~~ " << endl;
        int i;
        for (i = Q.last; i >= Q.first; i--) {
            cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
            cout << " Elemen ke          : " << i << endl;
            cout << " Nomor Pokok Mhs    : " << Q.Dat[i].npm      << endl;
            cout << " Nama Mahasiswa     : " << Q.Dat[i].nama_mhs << endl;
            cout << " Nilai Mahasiswa    : " << Q.Dat[i].nilai     << endl;
            cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
        }
    } else {
        cout << "Queue Kosong " << endl;
    }
}

// Fungsi input data mahasiswa dari keyboard
NilaiMK inputData() {
    NilaiMK data;
    cout << "\n--- Input Data Mahasiswa ---" << endl;
    cout << "Masukkan NPM       : ";
    cin  >> data.npm;
    cout << "Masukkan Nama      : ";
    cin.ignore();
    getline(cin, data.nama_mhs);
    cout << "Masukkan Nilai     : ";
    cin  >> data.nilai;
    return data;
}

int main() {
    Queue Q;
    buatQUkosong(&Q);

    char pilih;
    cout << "======================================" << endl;
    cout << "   PROGRAM QUEUE NILAI MAHASISWA      " << endl;
    cout << "======================================" << endl;

    do {
        cout << "\n========== MENU PILIHAN ==========" << endl;
        cout << " 1. Tambah Data (Enqueue)           " << endl;
        cout << " 2. Hapus Data Terdepan (Dequeue)   " << endl;
        cout << " 3. Tampilkan Queue                 " << endl;
        cout << " 4. Keluar                          " << endl;
        cout << "=================================== " << endl;
        cout << "Pilih 1 sd 4 : ";
        cin  >> pilih;

        switch (pilih) {
            case '1': {
                NilaiMK mhs = inputData();
                ADD(mhs.npm, mhs.nama_mhs, mhs.nilai, &Q);
                cout << "\nData berhasil ditambahkan ke queue!" << endl;
                break;
            }
            case '2': {
                if (isKosong(Q)) {
                    cout << "\nQueue Kosong, tidak ada data yang dihapus!" << endl;
                } else {
                    cout << "\nData terdepan dihapus dari queue." << endl;
                    DEL(&Q);
                }
                break;
            }
            case '3': {
                CetakQueue(Q);
                break;
            }
            case '4': {
                cout << "\nProgram selesai. Terima kasih!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid! Pilih 1 sd 4." << endl;
                break;
            }
        }
        cout << endl;
    } while (pilih != '4');

    cin.get();
}
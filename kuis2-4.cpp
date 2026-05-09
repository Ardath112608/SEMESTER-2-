#include <iostream>
using namespace std;

//Deklarasi struktur data pelanggan
typedef struct {
    int id_pelanggan;
    string nama_pelanggan;
    double total_belanja;
} Pelanggan;

//Deklarasi queue menggunakan array
typedef struct {
    int first;
    int last;
    Pelanggan Dat[10];
} Queue;

//Deklarasi fungsi membuat queue kosong
void buatQUkosong(Queue *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

//Deklarasi fungsi nilai TRUE apabila queue Kosong
bool isKosong(Queue Q) {
    bool hasil = false;
    if(Q.first == -1) {
        hasil = true;
    }
    return hasil;
}

//Deklarasi fungsi nilai TRUE apabila queue Penuh
bool isPenuh(Queue Q) {
    bool hasil = false;
    if(Q.last == 9) {
        hasil = true;
    }
    return hasil;
}

//Deklarasi fungsi memasukkan elemen ke dalam queue (enqueue)
void enqueue(int id_pelanggan, string nama_pelanggan, double total_belanja, Queue *Q) {
    if(isKosong(*Q) == 1) {
        //Jika Queue Kosong
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).Dat[0].id_pelanggan = id_pelanggan;
        (*Q).Dat[0].nama_pelanggan = nama_pelanggan;
        (*Q).Dat[0].total_belanja = total_belanja;
    }
    else {
        if(isPenuh(*Q) != 1) {
            //Jika Queue Tidak Kosong
            (*Q).last = (*Q).last + 1;
            (*Q).Dat[(*Q).last].id_pelanggan = id_pelanggan;
            (*Q).Dat[(*Q).last].nama_pelanggan = nama_pelanggan;
            (*Q).Dat[(*Q).last].total_belanja = total_belanja;
        }
        else {
            //Jika Queue PENUH
            cout << "QUEUE PENUH" << endl;
        }
    }
}

//Deklarasi fungsi mengeluarkan/menghapuskan elemen keluar queue (dequeue)
void dequeue(Queue *Q) {
    if(isKosong(*Q) == 1) {
        cout << "QUEUE KOSONG" << endl;
    }
    else {
        if((*Q).last == 0) {
            (*Q).first = -1;
            (*Q).last = -1;
        }
        else {
            //Menggeser Elemen Ke Depan
            int i;
            for(i=((*Q).first + 1); i <= (*Q).last; i++) {
                (*Q).Dat[i-1].id_pelanggan = (*Q).Dat[i].id_pelanggan;
                (*Q).Dat[i-1].nama_pelanggan = (*Q).Dat[i].nama_pelanggan;
                (*Q).Dat[i-1].total_belanja = (*Q).Dat[i].total_belanja;
            }
            (*Q).last = (*Q).last - 1;
        }
    }
}

//Deklarasi fungsi menampilkan isi queue
void CetakQueue(Queue Q) {
    if(Q.first != -1) {
        cout << " MENAMPILKAN QUEUE " << endl;
        cout << " ~~~~~~~~~~~~~~~~ " << endl;
        int i;
        for(i=Q.last; i>=Q.first; i--) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke             : " << i << endl;
            cout << "ID Pelanggan          : " << Q.Dat[i].id_pelanggan << endl;
            cout << "Nama Pelanggan        : " << Q.Dat[i].nama_pelanggan << endl;
            cout << "Total Belanja         : " << Q.Dat[i].total_belanja << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    else {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    Queue Q;
    buatQUkosong(&Q);

    int pilihan;
    do {
        cout << endl;
        cout << "======================================" << endl;
        cout << "         MENU QUEUE PELANGGAN         " << endl;
        cout << "======================================" << endl;
        cout << "1. Tambah Data Pelanggan" << endl;
        cout << "2. Hapus Data Pelanggan" << endl;
        cout << "3. Tampilkan Queue" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "======================================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                int id;
                string nama;
                double total;
                cout << "Masukkan ID Pelanggan   : ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Nama Pelanggan : ";
                getline(cin, nama);
                cout << "Masukkan Total Belanja  : ";
                cin >> total;
                enqueue(id, nama, total, &Q);
                cout << "Data berhasil ditambahkan!" << endl;
                break;
            }
            case 2: {
                dequeue(&Q);
                cout << "Data terdepan berhasil dihapus!" << endl;
                break;
            }
            case 3: {
                CetakQueue(Q);
                break;
            }
            case 4: {
                cout << "Terima kasih! Program selesai." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
            }
        }
    } while(pilihan != 4);

    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MataKuliah {
    string Nama;
    int sks_ira;
    string huruf;
    float angka;
};

struct Ira {               
    string nama;
    string nim;
    int jumlahmatakuliah;
    MataKuliah *mk;
};

int main() {
    int jumlah, ira, iru;
    cout << endl;
    cout << "Jumlah Mahasiswa : "; cin >> jumlah;

    Ira *mhs = new Ira[jumlah];   
    // Input Data
    for (ira = 0; ira < jumlah; ira++) {
        cout << endl;
        cout << "Pengisian Data Mahasiswa Ke-" << ira+1 << endl;
        cout << "Nama Mahasiswa     : "; cin >> mhs[ira].nama;
        cout << "Nomor Induk (NIM)  : "; cin >> mhs[ira].nim;
        cout << "Jumlah Mata Kuliah : "; cin >> mhs[ira].jumlahmatakuliah;
        mhs[ira].mk = new MataKuliah[mhs[ira].jumlahmatakuliah];

        for (iru = 0; iru < mhs[ira].jumlahmatakuliah; iru++) {
            cout << "  Mata Kuliah ke-" << iru+1 << endl;
            cout << "  Nama MK      : "; cin >> mhs[ira].mk[iru].Nama;
            cout << "  SKS          : "; cin >> mhs[ira].mk[iru].sks_ira;
            cout << "  Nilai Huruf  : "; cin >> mhs[ira].mk[iru].huruf;
            cout << "  Nilai Angka  : "; cin >> mhs[ira].mk[iru].angka;
        }
    }

    // Tampilkan Data
    for (ira = 0; ira < jumlah; ira++) {
        float totalAngka = 0;
        int totalSKS = 0;
        float IPK = 0;

        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "           KARTU HASIL STUDI[KHS]                " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Nama Mahasiswa        : " << mhs[ira].nama << endl;
        cout << "Nomor Induk Mahasiswa : " << mhs[ira].nim  << endl;
        cout << endl;
        cout << "Mata Kuliah Yang Ditempuh :" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << setw(5)  << "No"
             << setw(15) << "Mata Kuliah"
             << setw(5)  << "SKS"
             << setw(12) << "Nilai Huruf"
             << setw(12) << "Nilai Angka" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        for (iru = 0; iru < mhs[ira].jumlahmatakuliah; iru++) {
            cout << setw(5)  << iru+1
                 << setw(15) << (mhs[ira].mk + iru)->Nama
                 << setw(5)  << (mhs[ira].mk + iru)->sks_ira
                 << setw(12) << (mhs[ira].mk + iru)->huruf
                 << setw(12) << (mhs[ira].mk + iru)->angka << endl;
            totalSKS   += (mhs[ira].mk + iru)->sks_ira;
            totalAngka += (mhs[ira].mk + iru)->angka;
        }

        IPK = totalAngka / mhs[ira].jumlahmatakuliah;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Jumlah Mata Kuliah Yang Diambil = " << mhs[ira].jumlahmatakuliah << endl;
        cout << "Jumlah SKS                      = " << totalSKS                  << endl;
        cout << "Indeks Prestasi Komulatif [IPK] = " << IPK << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    cin.get();
}
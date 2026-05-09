#include <iostream>
#include <string>
using namespace std;

// Pendeklarasian tipe data baru menggunakan struct
struct Hari_aca {
    int nomorHari_aca;
    string namaHari_aca;
};

int main() {
    // Deklarasia
    Hari_aca aca;

    cout << "Masukkan Nomor Hari (0-6): ";
    cin >> aca.nomorHari_aca;

    if (aca.nomorHari_aca == 0) {
        aca.namaHari_aca = "Minggu";
    } else if (aca.nomorHari_aca == 1) {
        aca.namaHari_aca = "Senin";
    } else if (aca.nomorHari_aca == 2) {
        aca.namaHari_aca = "Selasa";
    } else if (aca.nomorHari_aca == 3) {
        aca.namaHari_aca = "Rabu";
    } else if (aca.nomorHari_aca == 4) {
        aca.namaHari_aca = "Kamis";
    } else if (aca.nomorHari_aca == 5) {
        aca.namaHari_aca = "Jum'at";
    } else if (aca.nomorHari_aca == 6) {
        aca.namaHari_aca = "Sabtu";
    } else {
        aca.namaHari_aca = "Hari tidak valid";
    }

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     HARI YANG ANDA PILIH       " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    // Agar pemilihan kode tidak keluar dari 0-6
    if (aca.nomorHari_aca >= 0 && aca.nomorHari_aca <= 6) {
        cout << "Nomor " << aca.nomorHari_aca << " = \"" << aca.namaHari_aca << "\"" << endl;
    } else {
        cout << aca.namaHari_aca << endl;
    }

    cin.get();    
}
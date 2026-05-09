#include <iostream>
#include <string>
using namespace std;

// Pendeklarasian tipe data baru class Penilaian
class Penilaian {
    public:
        char nilaiHuruf;
        string predikat;
};

int main() {
    // Buat variabel n bertipe data Penilaian
    Penilaian n;

    // Meminta input dari user
    cout << "Masukkan Nilai Huruf (A/B/C/D/E): ";
    cin >> n.nilaiHuruf;

    // Proses penentuan predikat berdasarkan input
    if (n.nilaiHuruf == 'A' || n.nilaiHuruf == 'a') {
        n.predikat = "Sangat baik ";
    } else if (n.nilaiHuruf == 'B' || n.nilaiHuruf == 'b') {
        n.predikat = "Baik";
    } else if (n.nilaiHuruf == 'C' || n.nilaiHuruf == 'c') {
        n.predikat = "cukup";
    } else if (n.nilaiHuruf == 'D' || n.nilaiHuruf == 'd') {
        n.predikat = "Kurang";
    } else if (n.nilaiHuruf == 'E' || n.nilaiHuruf == 'e') {
        n.predikat = "Gagal";
    } else {
        n.predikat = "Input tidak valid";
    }

    // Menampilkan output dengan format rapi
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     Hasil Konversi     " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Nilai " << n.nilaiHuruf << " = \"" << n.predikat << "\"" << endl;

    cin.ignore(); // Membersihkan buffer
    cin.get();    // Menahan layar agar tidak langsung tertutup

}
#include <iostream>
#include <string>
using namespace std;

// Deklarasi STRUKTUR
struct ira {
    string nik;
    string nama;
    string alamat;
    int tahunlahir;
    string jeniskelamin;
    string agama;
    string statusperkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string masaberlakuktp;
};

// Fungsi untuk input data KTP
void inputData(ira &data) {
    cout << "========================================" << endl;
    cout << "         INPUT DATA KTP                 " << endl;
    cout << "========================================" << endl;

    cout << "NIK                : ";
    cin.ignore();
    getline(cin, data.nik);

    cout << "Nama               : ";
    getline(cin, data.nama);

    cout << "Alamat             : ";
    getline(cin, data.alamat);

    cout << "Tahun Lahir        : ";
    cin >> data.tahunlahir;
    cin.ignore();

    cout << "Jenis Kelamin      : ";
    getline(cin, data.jeniskelamin);

    cout << "Agama              : ";
    getline(cin, data.agama);

    cout << "Status Perkawinan  : ";
    getline(cin, data.statusperkawinan);

    cout << "Pekerjaan          : ";
    getline(cin, data.pekerjaan);

    cout << "Kewarganegaraan    : ";
    getline(cin, data.kewarganegaraan);

    cout << "Masa Berlaku KTP   : ";
    getline(cin, data.masaberlakuktp);
}

// Fungsi untuk menampilkan data KTP
void tampilData(ira data) {
    cout << endl;
    cout << "========================================" << endl;
    cout << "        KARTU TANDA PENDUDUK            " << endl;
    cout << "========================================" << endl;
    cout << "NIK                : " << data.nik              << endl;
    cout << "Nama               : " << data.nama             << endl;
    cout << "Alamat             : " << data.alamat           << endl;
    cout << "Tahun Lahir        : " << data.tahunlahir       << endl;
    cout << "Jenis Kelamin      : " << data.jeniskelamin     << endl;
    cout << "Agama              : " << data.agama            << endl;
    cout << "Status Perkawinan  : " << data.statusperkawinan << endl;
    cout << "Pekerjaan          : " << data.pekerjaan        << endl;
    cout << "Kewarganegaraan    : " << data.kewarganegaraan  << endl;
    cout << "Masa Berlaku KTP   : " << data.masaberlakuktp   << endl;
    cout << "========================================" << endl;
}

int main() {
    // definisi STRUKTUR
    ira Data_ira;
	
	// untuk memanggil fungsi tampil
    inputData(Data_ira);
    tampilData(Data_ira);

    cin.get();
}
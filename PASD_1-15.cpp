#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string kode, nama;
    float harga, jumlah;
    int qty;
};

struct Pelanggan {
    string nama, alamat, telp;
    int jmlBarang, totalQty;
    float totalBayar;
    struct Barang *barang; 
};

int main() {
    int n;
    cout << "Jumlah Pelanggan : "; cin >> n;
    Pelanggan *p = new Pelanggan[n];

    for (int i = 0; i < n; i++) {
        cout << "Nama Pelanggan   : "; cin.ignore(); getline(cin, p[i].nama);
        cout << "Alamat Pelanggan : "; getline(cin, p[i].alamat);
        cout << "Jumlah Barang    : "; cin >> p[i].jmlBarang;

        p[i].barang = new Barang[p[i].jmlBarang];
        p[i].totalBayar = 0; p[i].totalQty = 0;

        for (int j = 0; j < p[i].jmlBarang; j++) {
            cout << "- Kode Barang  : "; cin >> p[i].barang[j].kode;
            cout << "- Nama Barang  : "; cin.ignore(); getline(cin, p[i].barang[j].nama);
            cout << "- Harga Barang : "; cin >> p[i].barang[j].harga;
            cout << "- Qty Barang   : "; cin >> p[i].barang[j].qty;

            p[i].barang[j].jumlah = p[i].barang[j].harga * p[i].barang[j].qty;
            p[i].totalQty += p[i].barang[j].qty;
            p[i].totalBayar += p[i].barang[j].jumlah;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << endl << "PENJUALAN TOKO BAGUS" << endl;
        cout << "Nama     : " << p[i].nama << endl;
        cout << "Alamat   : " << p[i].alamat << endl;
        cout << "No | Kode | Nama | Harga | Qty | Jumlah" << endl;

        for (int j = 0; j < p[i].jmlBarang; j++) {
            cout << (j+1) << " | " << p[i].barang[j].kode << " | " << p[i].barang[j].nama << " | " 
                 << p[i].barang[j].harga << " | " << p[i].barang[j].qty << " | " << p[i].barang[j].jumlah << endl;
        }
        cout << "Total Qty   : " << p[i].totalQty << endl;
        cout << "Total Bayar : " << p[i].totalBayar << endl;
    }

    cin.get();
}
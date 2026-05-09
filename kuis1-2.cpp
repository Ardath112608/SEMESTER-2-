#include <iostream>
#include <string>
using namespace std;

//Pendeklarasian tipe data baru class Mahasiswa
class BARANG{
        public:
        string kodebarang;
        char namabarang[30];
        int harga;
    };
int main(){
    //Buat variabel mhs bertipe data Mahasiswa
    BARANG aca;
    cout << "kode barang anda       = "; cin >> aca.kodebarang;
    cout << "Nama barang anda              = "; cin >> aca.namabarang;
    cout << "harga barang anda  = "; cin >> aca.harga;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "                         Data Anda" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "kode barang       = " << aca.kodebarang << endl;
    cout << "Nama barang              = " << aca.namabarang << endl;
    cout << "harga barang anda = " << aca.harga <<endl;
    cin.get();
}
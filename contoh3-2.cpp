#include <iostream>
using namespace std;

//Pendeklarasian tipe data baru class Mahasiswa
class Mahasiswa{
        public:
        char NPM[9];
        char nama[30];
        float ipk;
    };
int main(){
    //Buat variabel mhs bertipe data Mahasiswa
    Mahasiswa mhs;
    cout << "Nomor Pokok Mahasiswa       = "; cin >> mhs.NPM;
    cout << "Nama Mahasiswa              = "; cin >> mhs.nama;
    cout << "Indek Prestasi Komulatif = "; cin >> mhs.ipk;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "                         Data Anda" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "Nomor Pokok Mahasiswa       = " << mhs.NPM << endl;
    cout << "Nama Mahasiswa              = " << mhs.nama << endl;
    cout << "Indek Prestasi Komulatif = " << mhs.ipk <<endl;
    cin.get();
}
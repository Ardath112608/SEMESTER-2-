#include <iostream>
#include <string>
using namespace std;

//Deklarasi STRUKTUR
struct Koordinat {
   int X;
   int Y;    };
//Prototipe
void Tampil_Posisi(Koordinat Posisi);

int main() {
//Pendefinisian variabel STRUKTUR
Koordinat Posisi;
//Pengaksesan anggota struktur
Posisi.X = 56;
Posisi.Y = 53;
cout<<endl;
Tampil_Posisi(Posisi);
cin.get(); }

//Definisi fungsi TAMPIL_POSISI
void Tampil_Posisi(Koordinat Posisi) {
    cout << "Posisi Ordinat X adalah " << Posisi.X << endl;
    cout << "Posisi Ordinat Y adalah " << Posisi.Y << endl; }
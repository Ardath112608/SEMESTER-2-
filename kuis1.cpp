#include <iostream>
#include <string>
using namespace std;

int main()    {
//Deklarasi STRUKTUR
struct BUKUPERPUS  {
   string judulbuku;
   string pengarang;
   int tahunterbit;
   int harga ; } ;
//Pendefinisian STRUKTUR
BUKUPERPUS Data_perpus;
//Pengaksesan anggota struktur
Data_perpus.judulbuku = "HUJAN DI BULAN JANUARI";
Data_perpus.pengarang = "SAPARDIU DJOKO DAMONO";
Data_perpus.tahunterbit = 1999;
Data_perpus.harga = 150000;
cout<<endl;
cout<<endl;
cout<< "judul buku  = " << Data_perpus.judulbuku << endl;
cout<< "pengarang  = " << Data_perpus.pengarang << endl;
cout<< "tahun terbit        = " << Data_perpus.tahunterbit << endl;
cout<< "harga      = "<<Data_perpus.harga << endl;
cin.get();  }

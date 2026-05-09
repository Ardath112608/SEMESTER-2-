#include <iostream>
#include <string>
using namespace std;

int main()    {
//Deklarasi STRUKTUR
struct aca  {
   string nik;
   string nama;
   string alamat;
   int tahunlahir ;
   string jeniskelamin;
   string agama ;
   string statusperkawinan ;
   string pekerjaan;
   string kewarganegaraan;
   string masaberlakuktp ; } ;
//Pendefinisian STRUKTUR
aca Data_aca;
//Pengaksesan anggota struktur
Data_aca.nik = " 12345678910111213141516 " ;
Data_aca.nama = "Aca Ganteng Banget" ;
Data_aca.alamat = "jl. aja dulu" ;
Data_aca.tahunlahir = 1999 ;
Data_aca.jeniskelamin= " laki-laki ";
Data_aca.agama= "islam" ;
Data_aca.statusperkawinan= "belum menikah" ;
Data_aca.pekerjaan= "belum bekerja" ;
Data_aca.kewarganegaraan= "INDONESIA" ;
Data_aca.masaberlakuktp= "seumur hidup:" ;
cout<<endl;
cout<<endl;
cout<< "judul buku  = " << Data_aca.nik << endl;
cout<< "pengarang  = " << Data_aca.nama << endl;
cout<< "tahun terbit = " << Data_aca.alamat << endl;
cout<< "harga      = "<<Data_aca.tahunlahir << endl;
cout<< "harga      = "<<Data_aca.jeniskelamin << endl;
cout<< "harga      = "<<Data_aca.agama << endl;
cout<< "harga      = "<<Data_aca.statusperkawinan << endl;
cout<< "harga      = "<<Data_aca.pekerjaan << endl;
cout<< "harga      = "<<Data_aca.kewarganegaraan << endl;
cout<< "harga      = "<<Data_aca.masaberlakuktp << endl;
cin.get();  }

#include <iostream>
using namespace std;

struct Node      {
        int NilaiUTS, aca;
        int NilaiUAS;
        int N1, N2;     };
Node *P, *Q;

int main()  {
      P = new Node;
      P -> N1 = 100;
      Q = new Node;
      Q -> N2 = 50;

//Menampilkan isi variabel
cout<<endl;
cout<<"Isi Variabel P =  "<< P -> N1 << endl;
cout<<"Isi Variabel Q =  "<< Q -> N2 << endl;
cout<<endl;
cin.get();   }
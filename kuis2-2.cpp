#include <iostream>
#include <string>
using namespace std;

string myStack[5];  //untuk maks 5 array nya
int top = -1;       // posisi atas stack

int main() {
    int pilihan;
    string judul;

    do {
        cout << "=== MENU PERPUSTAKAAN ===" << endl;
        cout << "1. PUSH (Tambah Buku)" << endl;
        cout << "2. POP (Ambil Buku)" << endl;
        cout << "3. DISPLAY (Tampilkan Isi Stack)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // PUSH
            if (top == 4) {
                cout << "Stack penuh! Tidak bisa menambah buku." << endl;
            } else {
                cout << "Judul buku (tanpa spasi): ";
                cin >> judul;
                
                top++;
                myStack[top] = judul;
                cout << "Buku berhasil ditambahkan!" << endl;
            }
        } 
        else if (pilihan == 2) {
            // POP
            if (top == -1) {
                cout << "Stack kosong! Tidak ada buku yang bisa diambil." << endl;
            } else {
                cout << "Buku yang keluar: " << myStack[top] << endl;
                top--;
            }
        } 
        else if (pilihan == 3) {
            // DISPLAY
            if (top == -1) {
                cout << "Stack kosong!" << endl;
            } else {
                cout << "\nIsi stack dari atas ke bawah:" << endl;
                for(int i = top; i >= 0; i--){
                    cout << "- " << myStack[i] << endl;
                }
            }
        }

    } while (pilihan != 0);

    cin.get();
}
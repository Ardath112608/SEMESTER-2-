#include <iostream>
using namespace std;

// Mendefinisikan Stack menggunakan Struct untuk membungkus array
struct Stack_aca {
    int atas_aca;
    char array_tumpukan_aca[10]; 
};

// Fungsi untuk tumpukan kosong di awal 
void inisialisasi_aca(Stack_aca &s_aca) {
    s_aca.atas_aca = -1;
}

// Fungsi untuk memasukkan data ke tumpukan (Push)
void push_aca(Stack_aca &s_aca, char nilai_aca) {
    if (s_aca.atas_aca < 9) {
        s_aca.atas_aca++;
        s_aca.array_tumpukan_aca[s_aca.atas_aca] = nilai_aca;
    }
}

// Fungsi untuk mengeluarkan data dari tumpukan (Pop)
void pop_aca(Stack_aca &s_aca) {
    if (s_aca.atas_aca >= 0) {
        s_aca.atas_aca--;
    }
}

// Fungsi untuk mencetak isi tumpukan array
void cetak_aca(Stack_aca s_aca) {
    for (int i_aca = s_aca.atas_aca; i_aca >= 0; i_aca--) {
        cout << s_aca.array_tumpukan_aca[i_aca] << endl;
    }
    cout << "---" << endl;
}

// Fungsi bantuan untuk mengembalikan posisi awal tumpukan ke A, B, C
void reset_tumpukan_aca(Stack_aca &s_aca) {
    inisialisasi_aca(s_aca);
    push_aca(s_aca, 'A');
    push_aca(s_aca, 'B');
    push_aca(s_aca, 'C');
}

int main() {
    // di definisikan structnya
    Stack_aca tumpukan_aca;
    
    cout << "A. Memasukkan D setelah A (A, D, B, C):" << endl;
    reset_tumpukan_aca(tumpukan_aca);
    pop_aca(tumpukan_aca); 
    pop_aca(tumpukan_aca); 
    push_aca(tumpukan_aca, 'D'); 
    push_aca(tumpukan_aca, 'B'); 
    push_aca(tumpukan_aca, 'C'); 
    cetak_aca(tumpukan_aca);

    cout << "B. Memasukkan E setelah B (A, B, E, C):" << endl;
    reset_tumpukan_aca(tumpukan_aca);
    pop_aca(tumpukan_aca); 
    push_aca(tumpukan_aca, 'E'); 
    push_aca(tumpukan_aca, 'C'); 
    cetak_aca(tumpukan_aca);

    cout << "C. Memasukkan F paling bawah, A, B, C hilang (F):" << endl;
    reset_tumpukan_aca(tumpukan_aca);
    pop_aca(tumpukan_aca); 
    pop_aca(tumpukan_aca); 
    pop_aca(tumpukan_aca); 
    push_aca(tumpukan_aca, 'F'); 
    cetak_aca(tumpukan_aca);

    cout << "D. Memasukkan F paling bawah, A, B, C masih ada (F, A, B, C):" << endl;
    reset_tumpukan_aca(tumpukan_aca);
    pop_aca(tumpukan_aca); 
    pop_aca(tumpukan_aca); 
    pop_aca(tumpukan_aca); 
    push_aca(tumpukan_aca, 'F'); 
    push_aca(tumpukan_aca, 'A'); 
    push_aca(tumpukan_aca, 'B'); 
    push_aca(tumpukan_aca, 'C'); 
    cetak_aca(tumpukan_aca);
cin.get();
}
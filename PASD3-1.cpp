#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

// Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

// Deklarasi struktur stack
typedef struct {
    elemen* top;
} Stack;

void buatSTkosong(Stack *S) {
    (*S).top = NULL;
}

int isKosong(Stack S) {
    bool hasil = false;
    if(S.top == NULL) hasil = true;
    return hasil;
}

int jmlElemen(Stack S) {
    int hasil = 0;
    if(S.top != NULL) {
        elemen *bantu = S.top;
        while(bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(string npm, string nama_mhs, double nilai, Stack *S) {
    elemen *info;
    info = new elemen;
    info->Kontainer.npm      = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai    = nilai;

    if((*S).top == NULL) info->next = NULL;
    else                 info->next = (*S).top;

    (*S).top = info;
    info = NULL;
}

void Pop(Stack *S) {
    if((*S).top != NULL) {
        elemen *hapus = (*S).top;
        if(jmlElemen(*S) == 1) (*S).top = NULL;
        else                   (*S).top = (*S).top->next;
        hapus->next = NULL;
        delete hapus;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void CetakStack(Stack S) {
    if(S.top != NULL) {
        cout << " MENAMPILKAN STACK " << endl;
        elemen *bantu = S.top;
        int i = 1;
        while(bantu != NULL) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke             : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << bantu->Kontainer.npm      << endl;
            cout << "Nama Mahasiswa        : " << bantu->Kontainer.nama_mhs << endl;
            cout << "Nilai Mahasiswa       : " << bantu->Kontainer.nilai     << endl;
            bantu = bantu->next;
            i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    } else {
        cout << "Stack Kosong " << endl;
    }
}

int main() {
    Stack S;
    buatSTkosong(&S);
    CetakStack(S);
    cout << endl;

    int n;
    cout << "Masukkan jumlah data mahasiswa : ";
    cin >> n;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // Input data dari user lalu push ke stack
    for(int i = 1; i <= n; i++) {
        string npm, nama;
        double nilai;
        cout << "\n--- Data Mahasiswa ke-" << i << " ---" << endl;
        cout << "NPM           : "; cin >> npm;
        cout << "Nama          : "; cin >> nama;
        cout << "Nilai         : "; cin >> nilai;
        push(npm, nama, nilai, &S);
    }

    // Tampilkan stack setelah semua data diinput
    cout << endl;
    CetakStack(S);
    cout << "=====================" << endl;
    cout << endl;

    // POP pertama
    cout << ">> POP data teratas..." << endl << endl;
    Pop(&S);
    CetakStack(S);
    cout << endl;

    // POP kedua
    cout << ">> POP data teratas..." << endl << endl;
    Pop(&S);
    CetakStack(S);
    cout << "=====================" << endl;

    cin.get();
}
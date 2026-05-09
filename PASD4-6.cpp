#include <iostream>
#include <string>
#define MAX 10
using namespace std;

typedef struct {
    string nama_os;
} DataOS;

typedef struct {
    int first;
    int last;
    DataOS Dat[MAX];
} Queue;

void buatQUkosong(Queue *Q) {
    Q->first = -1;
    Q->last  = -1;
}

bool isKosong(Queue Q) {
    return (Q.first == -1);
}

bool isPenuh(Queue Q) {
    return (Q.last == MAX - 1);
}

void ADD(string nama_os, Queue *Q) {
    if (isKosong(*Q)) {
        Q->first = 0;
        Q->last  = 0;
        Q->Dat[0].nama_os = nama_os;
    } else if (!isPenuh(*Q)) {
        Q->last++;
        Q->Dat[Q->last].nama_os = nama_os;
    } else {
        cout << "QUEUE PENUH!" << endl;
    }
}

void DEL(Queue *Q) {
    if (isKosong(*Q)) {
        cout << "Queue Kosong!" << endl;
        return;
    }
    if (Q->last == 0) {
        Q->first = -1;
        Q->last  = -1;
    } else {
        for (int i = Q->first + 1; i <= Q->last; i++) {
            Q->Dat[i-1].nama_os = Q->Dat[i].nama_os;
        }
        Q->last--;
    }
}

bool hapusOS(string nama_os, Queue *Q) {
    if (isKosong(*Q)) {
        cout << "Queue Kosong!" << endl;
        return false;
    }
    int pos = -1;
    for (int i = Q->first; i <= Q->last; i++) {
        if (Q->Dat[i].nama_os == nama_os) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "OS \"" << nama_os << "\" tidak ditemukan!" << endl;
        return false;
    }
    for (int i = pos; i < Q->last; i++) {
        Q->Dat[i].nama_os = Q->Dat[i+1].nama_os;
    }
    Q->last--;
    if (Q->last < Q->first) {
        Q->first = -1;
        Q->last  = -1;
    }
    return true;
}

bool sisipSetelah(string target, string nama_baru, Queue *Q) {
    if (isPenuh(*Q)) {
        cout << "Queue Penuh!" << endl;
        return false;
    }
    int pos = -1;
    for (int i = Q->first; i <= Q->last; i++) {
        if (Q->Dat[i].nama_os == target) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "OS \"" << target << "\" tidak ditemukan!" << endl;
        return false;
    }
    Q->last++;
    for (int i = Q->last; i > pos + 1; i--) {
        Q->Dat[i].nama_os = Q->Dat[i-1].nama_os;
    }
    Q->Dat[pos+1].nama_os = nama_baru;
    return true;
}

void cetakQueue(Queue Q) {
    if (isKosong(Q)) {
        cout << "[ Queue Kosong ]" << endl;
        return;
    }
    cout << "\nIsi Queue OS:" << endl;
    cout << "+-----+----------------------+" << endl;
    cout << "| No  | Nama OS              |" << endl;
    cout << "+-----+----------------------+" << endl;
    for (int i = Q.first; i <= Q.last; i++) {
        string nm = Q.Dat[i].nama_os;
        cout << "| " << i << "   | " << nm;
        int pad = 20 - (int)nm.length();
        for (int p = 0; p < pad; p++) cout << " ";
        cout << " |" << endl;
    }
    cout << "+-----+----------------------+" << endl;
}

void initAntrian(Queue *Q) {
    buatQUkosong(Q);
    ADD("Maemo",   Q);
    ADD("Symbian", Q);
    ADD("Mac",     Q);
    ADD("Windows", Q);
    ADD("Iphone",  Q);
}

int main() {
    Queue Q;

    cout << "=============================================" << endl;
    cout << "  PASD4-6 : QUEUE OS - ANTRIAN DENGAN ARRAY " << endl;
    cout << "=============================================" << endl;

    // SOAL 6a: Tambah "Maemo 4" paling bawah, hapus "Mac"
    cout << "\n[6a] Tambah 'Maemo 4' paling bawah, hapus 'Mac'" << endl;
    initAntrian(&Q);
    cout << "[SEBELUM]"; cetakQueue(Q);
    hapusOS("Mac", &Q);
    ADD("Maemo 4", &Q);
    cout << "[SESUDAH]"; cetakQueue(Q);

    // SOAL 6b: Tambah "Windows Mobile" setelah "Windows", hapus "Iphone"
    cout << "\n[6b] Tambah 'Windows Mobile' setelah 'Windows', hapus 'Iphone'" << endl;
    initAntrian(&Q);
    cout << "[SEBELUM]"; cetakQueue(Q);
    hapusOS("Iphone", &Q);
    sisipSetelah("Windows", "Windows Mobile", &Q);
    cout << "[SESUDAH]"; cetakQueue(Q);

    // SOAL 6c: Tambah "Java Midlet" setelah "Symbian", hapus "Maemo"
    cout << "\n[6c] Tambah 'Java Midlet' setelah 'Symbian', hapus 'Maemo'" << endl;
    initAntrian(&Q);
    cout << "[SEBELUM]"; cetakQueue(Q);
    hapusOS("Maemo", &Q);
    sisipSetelah("Symbian", "Java Midlet", &Q);
    cout << "[SESUDAH]"; cetakQueue(Q);

    // SOAL 6d: Tambah "Lion OS X" setelah "Mac", hapus "Maemo"
    cout << "\n[6d] Tambah 'Lion OS X' setelah 'Mac', hapus 'Maemo'" << endl;
    initAntrian(&Q);
    cout << "[SEBELUM]"; cetakQueue(Q);
    hapusOS("Maemo", &Q);
    sisipSetelah("Mac", "Lion OS X", &Q);
    cout << "[SESUDAH]"; cetakQueue(Q);

    // SOAL 6e: Tambah "Android" setelah "Iphone", hapus "Maemo"
    cout << "\n[6e] Tambah 'Android' setelah 'Iphone', hapus 'Maemo'" << endl;
    initAntrian(&Q);
    cout << "[SEBELUM]"; cetakQueue(Q);
    hapusOS("Maemo", &Q);
    sisipSetelah("Iphone", "Android", &Q);
    cout << "[SESUDAH]"; cetakQueue(Q);

    cout << "\n==============================================" << endl;
    cout << " Program Selesai." << endl;
    cout << "==============================================" << endl;

    cin.get();
}
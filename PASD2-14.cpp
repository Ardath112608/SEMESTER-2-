#include <iostream>
#include <string>
#define MAXSTACK 20
using namespace std;

typedef struct { string namaOS; } DataOS;

typedef struct {
    int top;
    DataOS Dat[MAXSTACK];
} Stack;

void buatSTkosong(Stack *S) { (*S).top = -1; }
bool isKosong(Stack S)      { return (S.top == -1); }
bool isPenuh(Stack S)       { return (S.top == MAXSTACK - 1); }

void push(string namaOS, Stack *S) {
    if (isPenuh(*S)) {
        cout << "Stack Penuh!" << endl;
    } else if (isKosong(*S)) {
        (*S).top = 0;
        (*S).Dat[0].namaOS = namaOS;
    } else {
        (*S).top = (*S).top + 1;
        (*S).Dat[(*S).top].namaOS = namaOS;
    }
}

void pop(Stack *S) {
    if ((*S).top == 0)       (*S).top = -1;
    else if ((*S).top != -1) (*S).top = (*S).top - 1;
}

void cetakStack(Stack S) {
    if (S.top != -1) {
        cout << "  +--------------------+" << endl;
        for (int i = S.top; i >= 0; i--) {
            int spasi = 16 - (int)S.Dat[i].namaOS.length();
            cout << "  |  " << S.Dat[i].namaOS;
            for (int j = 0; j < spasi; j++) cout << " ";
            cout << "|" << endl;
            cout << "  +--------------------+" << endl;
        }
    } else {
        cout << "  [Stack Kosong]" << endl;
    }
}

void sisipDiAtas(Stack *S, string target, string newOS) {
    Stack bantu;
    buatSTkosong(&bantu);

    while (!isKosong(*S) && (*S).Dat[(*S).top].namaOS != target) {
        push((*S).Dat[(*S).top].namaOS, &bantu);
        pop(S);
    }
    push(newOS, S);
    while (!isKosong(bantu)) {
        push(bantu.Dat[bantu.top].namaOS, S);
        pop(&bantu);
    }
}

void sisipPalingBawah(Stack *S, string newOS) {
    Stack bantu;
    buatSTkosong(&bantu);

    while (!isKosong(*S)) {
        push((*S).Dat[(*S).top].namaOS, &bantu);
        pop(S);
    }
    push(newOS, S);
    while (!isKosong(bantu)) {
        push(bantu.Dat[bantu.top].namaOS, S);
        pop(&bantu);
    }
}

int main() {
    Stack S;
    buatSTkosong(&S);

    // Tumpukan awal: Iphone (bawah) -> Windows -> Mac -> Symbian -> Maemo (atas)
    push("Iphone",  &S);
    push("Windows", &S);
    push("Mac",     &S);
    push("Symbian", &S);
    push("Maemo",   &S);

    cout << "==============================" << endl;
    cout << "  STACK OS - PASD2-14        " << endl;
    cout << "==============================" << endl;
    cout << "[Tumpukan Awal]" << endl;
    cetakStack(S);

    // a. Memasukkan "Iphone 5" di atas "Iphone"
    cout << "------------------------------" << endl;
    cout << "a. Iphone 5 di atas Iphone" << endl;
    Stack Sa = S;
    sisipDiAtas(&Sa, "Iphone", "Iphone 5");
    cetakStack(Sa);

    // b. Menambahkan "Windows Phone" di atas "Windows"
    cout << "------------------------------" << endl;
    cout << "b. Windows Phone di atas Windows" << endl;
    Stack Sb = S;
    sisipDiAtas(&Sb, "Windows", "Windows Phone");
    cetakStack(Sb);

    // c. Menambahkan "SnowLeopard" di atas "Mac"
    cout << "------------------------------" << endl;
    cout << "c. SnowLeopard setelah Mac" << endl;
    Stack Sc = S;
    sisipDiAtas(&Sc, "Mac", "SnowLeopard");
    cetakStack(Sc);

    // d. Menambahkan "Symbian Belle" di atas "Symbian"
    cout << "------------------------------" << endl;
    cout << "d. Symbian Belle setelah Symbian" << endl;
    Stack Sd = S;
    sisipDiAtas(&Sd, "Symbian", "Symbian Belle");
    cetakStack(Sd);

    // e. Menambahkan "Maemo 4" paling bawah tanpa menghilangkan semua
    cout << "------------------------------" << endl;
    cout << "e. Maemo 4 paling bawah" << endl;
    Stack Se = S;
    sisipPalingBawah(&Se, "Maemo 4");
    cetakStack(Se);

    cout << "==============================" << endl;

    cin.get();
}
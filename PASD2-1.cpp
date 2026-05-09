#include <iostream>
using namespace std;

typedef int Tahun;
bool isKabisat(Tahun t) {
    if ((t % 4 == 0 && t % 100 != 0) || (t % 400 == 0)) {
        return true;
    }
    return false;
}

// ============================================================
// FUNGSI cetakHasil
// ============================================================
void cetakHasil(Tahun t) {
    cout << "Tahun " << t;
    if (isKabisat(t)) {
        cout << " adalah TAHUN KABISAT" << endl;
    } else {
        cout << " BUKAN tahun kabisat" << endl;
    }
}

int main() {
    cout << "======================================" << endl;
    cout << "  CEK TAHUN KABISAT MENGGUNAKAN ADT  " << endl;
    cout << "======================================" << endl;
    cout << endl;

    // Deklarasi variabel bertipe ADT Tahun
    Tahun t1 = 2000;
    Tahun t2 = 1900;
    Tahun t3 = 2024;
    Tahun t4 = 2023;
    Tahun t5 = 1600;
    Tahun t6 = 100;

    // Menampilkan hasil untuk setiap tahun
    cetakHasil(t1);
    cetakHasil(t2);
    cetakHasil(t3);
    cetakHasil(t4);
    cetakHasil(t5);
    cetakHasil(t6);

    cout << endl;
    cout << "======================================" << endl;

    cin.get();
}
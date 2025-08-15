#include <iostream>
#include <string>

using namespace std;

string faktorialString(int n) {
    if (n == 1) {
        return "1";
    }
    else {
        return faktorialString(n - 1) + " x " + to_string(n);
    }
}

long long faktorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * faktorial(n - 1);
    }
}

string penjumlahanString(int n) {
    if (n == 1) {
        return "1";
    }
    else {
        return penjumlahanString(n - 1) + " + " + to_string(n);
    }
}

int penjumlahan(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n + penjumlahan(n - 1);
    }
}

int main() {
    int n;
    char pilihan;
    char ulangi;

    do {
        cout << "========================================" << endl;
        cout << "         PROGRAM HITUNG REKURSIF        " << endl;
        cout << "========================================" << endl;
        cout << "Pilih operasi yang ingin dihitung:" << endl;
        cout << "1. Faktorial Rekursif" << endl;
        cout << "2. Penjumlahan Rekursif" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cout << "----------------------------------------" << endl;

        switch (pilihan) {
        case '1': {
            cout << "Masukkan bilangan bulat n: ";
            cin >> n;

            if (n < 0) {
                cout << "Masukkan bilangan bulat positif." << endl;
            }
            else if (n == 0) {
                cout << n << "! = 1" << endl;
            }
            else {
                cout << n << "! = " << faktorialString(n) << " = " << faktorial(n) << endl;
            }
            break;
        }
        case '2': {
            cout << "Masukkan bilangan bulat n: ";
            cin >> n;

            if (n < 0) {
                cout << "Masukkan bilangan bulat positif." << endl;
            }
            else if (n == 0) {
                cout << "Jumlah dari 0 = 0" << endl;
            }
            else {
                cout << "Jumlah dari " << n << " = " << penjumlahanString(n) << " = " << penjumlahan(n) << endl;
            }
            break;
        }
        case '3': {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            return 0;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

        cout << endl;
        cout << "Apakah Anda ingin menghitung lagi (Y/T)? ";
        cin >> ulangi;
        cout << endl;

    } while (ulangi == 'Y' || ulangi == 'y');

 akhir:
    return 0;
}
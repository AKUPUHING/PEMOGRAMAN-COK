#include <iostream>
#include <cmath>

using namespace std;

void hitungLuasLayang(double d1, double d2) {
    double luas = 0.5 * d1 * d2;
    cout << "Luas layang-layang adalah: " << luas << endl;
}

void hitungKelilingLayang(double a, double b) {
    double keliling = 2 * (a + b);
    cout << "Keliling layang-layang adalah: " << keliling << endl;
}

void hitungVolumeTabung(double r, double t) {
    const double PI = 3.14;
    double volume = PI * r * r * t;
    cout << "Volume tabung adalah: " << volume << endl;
}

int main() {
    char pilihan_menu;
    char ulangi;

    do {
        cout << "========================================" << endl;
        cout << " PROGRAM PENGHITUNG BANGUN DATAR & RUANG" << endl;
        cout << "========================================" << endl;
        cout << "Pilih Bangun yang ingin dihitung:" << endl;
        cout << "1. Layang-layang" << endl;
        cout << "2. Tabung" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan_menu;
        cout << "----------------------------------------" << endl;

        switch (pilihan_menu) {
        case '1': {
            double d1, d2, sisi_a, sisi_b;
            cout << "--- Menghitung Layang-layang ---" << endl;
            cout << "Masukkan panjang diagonal 1: ";
            cin >> d1;
            cout << "Masukkan panjang diagonal 2: ";
            cin >> d2;
            hitungLuasLayang(d1, d2);
            cout << "----------------------------------------" << endl;
            cout << "Masukkan panjang sisi a: ";
            cin >> sisi_a;
            cout << "Masukkan panjang sisi b: ";
            cin >> sisi_b;
            hitungKelilingLayang(sisi_a, sisi_b);
            break;
        }
        case '2': {
            double r, t;
            cout << "--- Menghitung Volume Tabung ---" << endl;
            cout << "Masukkan jari-jari alas (r): ";
            cin >> r;
            cout << "Masukkan tinggi tabung (t): ";
            cin >> t;
            hitungVolumeTabung(r, t);
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

    } while (ulangi == 'Y' || ulangi == 'y');


    return 0;
}
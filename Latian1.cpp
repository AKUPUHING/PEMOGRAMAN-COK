#include <iostream>
#include <cmath>

using namespace std;

const double G = 10.0;
const double PI = 3.14;


double hitungJarakMaksimum(double v0, double sudut_rad) {
    double radian = sudut_rad * 3.14 / 180.0;
    return (v0 * v0 * sin(2 * radian)) / 10;
} 

double hitungKetinggianMaksimum(double v0, double sudut_rad) {
    double radian = sudut_rad * 3.14 / 180.0;
    return (v0 * v0 * sin(radian)* sin(radian)) / (2 * 10);
}

int main() {
    char ulangi;
    int pilihan;

    awal:
    cout << "\n\n------------------------------------------------------------" << endl;

    cout << "===== Perhitungan Jarak dan Ketinggian Maksimum Peluru =====" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "Pilih Perhitungan:" << endl;
    cout << "A. Hitung Jarak Maksimum (Xmax)" << endl;
    cout << "B. Hitung Ketinggian Maksimum (Hmax)" << endl;
    cout << "C. keluar" << endl;
    cout << "Pilihan Anda: ";
    cin >> ulangi;
    cout << "------------------------------------------------------------" << endl;


    if (ulangi == 'A' || ulangi == 'a') {
        double v0, sudut_rad;

        cout << "Masukkan kecepatan awal (v0) dalam m/s: ";
        cin >> v0;
        cout << "Masukkan sudut elevasi (A) dalam derajat: ";
        cin >> sudut_rad;
        cout << "Hasil Perhitungan Jarak Maksimum (Xmax) = "
            << hitungJarakMaksimum(v0, sudut_rad) << endl;
        goto awal;
    }
    if (ulangi == 'B' || ulangi == 'b') {
        double v0, sudut_rad;

        cout << "Masukkan kecepatan awal (v0) dalam m/s: ";
        cin >> v0;
        cout << "Masukkan sudut elevasi (A) dalam derajat: ";
        cin >> sudut_rad;
        cout << "Hasil Perhitungan Ketinggian Maksimum (Hmax) = "
            << hitungKetinggianMaksimum(v0, sudut_rad) << endl;
        goto awal;
    }
    if (ulangi == 'C' || ulangi == 'c') {
    
        cout << endl;
        cout << "Masukkan data lagi (Y/T)? ";
        cin >> ulangi;
    if (ulangi == 'Y' || ulangi == 'y') {
            goto awal;
        }
    if (ulangi == 'T' || ulangi == 't') {
            goto akhir;
        }

    akhir:

        return 0;
    }
}
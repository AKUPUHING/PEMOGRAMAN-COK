#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <ios>

using namespace std;

struct Barang {
    string nama;
    string kode;
    int stok;
};

bool urutStok(const Barang& a, const Barang& b) {
    return a.stok < b.stok;
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int tampilkanMenu() {
    int pilihan;
    cout << "\n===== MENU INVENTARIS =====" << endl;
    cout << "1. Tambah Barang Baru" << endl;
    cout << "2. Tampilkan Daftar Barang (Urut Stok)" << endl;
    cout << "3. Cari Barang" << endl;
    cout << "4. Hapus Barang" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih Menu (1-5): ";

    while (!(cin >> pilihan) || pilihan < 1 || pilihan > 5) {
        cout << "Pilihan tidak valid. Masukkan angka 1-5: ";
        cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer();
    return pilihan;
}

void tambahBarang(vector<Barang>& daftarBarang) {
    Barang barang;
    cout << "\n--- Tambah Barang ---" << endl;
    cout << "Nama : ";
    getline(cin, barang.nama);
    cout << "Kode : ";
    getline(cin, barang.kode);

    cout << "Stok : ";
    while (!(cin >> barang.stok) || barang.stok < 0) {
        cout << "Stok tidak valid. Masukkan angka positif: ";
        cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer();

    daftarBarang.push_back(barang);
    cout << "Barang berhasil ditambahkan!" << endl;
}

void tampilkanDaftarBarang(vector<Barang>& daftarBarang) {
    if (daftarBarang.empty()) {
        cout << "\nInventaris kosong. Silakan tambahkan barang terlebih dahulu." << endl;
        return;
    }
    sort(daftarBarang.begin(), daftarBarang.end(), urutStok);

    cout << "\n===== Daftar Barang Sesuai Stok =====" << endl;
    for (size_t i = 0; i < daftarBarang.size(); i++) {
        cout << "-------------------------------" << endl;
        cout << "Barang ke-" << i + 1 << endl;
        cout << "Nama : " << daftarBarang[i].nama << endl;
        cout << "Kode : " << daftarBarang[i].kode << endl;
        cout << "Stok : " << daftarBarang[i].stok << endl;
    }
    cout << "-------------------------------" << endl;
}

void cariBarang(const vector<Barang>& daftarBarang) {
    string namaBarang;
    cout << "\n--- Cari Barang ---" << endl;
    cout << "Masukkan Nama Barang: ";
    getline(cin, namaBarang);

    bool ditemukan = false;
    for (const Barang& barang : daftarBarang) {
        if (barang.nama.find(namaBarang) != string::npos) {
            cout << "\nBarang Ditemukan!" << endl;
            cout << "Nama : " << barang.nama << endl;
            cout << "Kode : " << barang.kode << endl;
            cout << "Stok : " << barang.stok << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Barang Tidak Ditemukan!" << endl;
    }
}

void hapusBarang(vector<Barang>& daftarBarang) {
    string kodeHapus;
    cout << "\n--- Hapus Barang ---" << endl;
    cout << "Masukkan Kode Barang yang akan dihapus: ";
    getline(cin, kodeHapus);

    for (size_t i = 0; i < daftarBarang.size(); ++i) {
        if (daftarBarang[i].kode == kodeHapus) {
            daftarBarang.erase(daftarBarang.begin() + i);
            cout << "Barang dengan kode " << kodeHapus << " berhasil dihapus." << endl;
            return;
        }
    }

    cout << "Barang dengan kode " << kodeHapus << " tidak ditemukan." << endl;
}

int main() {
    vector<Barang> daftarBarang;
    int pilihan;

    do {
        pilihan = tampilkanMenu();

        switch (pilihan) {
        case 1:
            tambahBarang(daftarBarang);
            break;
        case 2:
            tampilkanDaftarBarang(daftarBarang);
            break;
        case 3:
            cariBarang(daftarBarang);
            break;
        case 4:
            hapusBarang(daftarBarang);
            break;
        case 5:
            cout << "Terima kasih telah menggunakan layanan inventaris." << endl;
            break;
        default:
            break;
        }
    } while (pilihan != 5);

    return 0;
}
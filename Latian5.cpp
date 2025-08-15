#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Mahasiswa {
    string nim, nama, jurusan, jenjang, prodiKode;
};

void clearInputBuffer() {
    cin.ignore(256, '\n');
}

void parseNim(Mahasiswa& mhs) {
    if (mhs.nim.length() >= 5) {
        char jenjangChar = mhs.nim[4];
        char prodiChar = mhs.nim[4];

        if (jenjangChar >= '1' && jenjangChar <= '3') mhs.jenjang = "D3";
        else if (jenjangChar >= '4' && jenjangChar <= '6') mhs.jenjang = "D4";
        else mhs.jenjang = "Tidak Diketahui";

        switch (prodiChar) {
        case '1': mhs.jurusan = "Teknik Mesin Indonesia"; mhs.prodiKode = "TMI"; break;
        case '2': mhs.jurusan = "Teknik mekatronika"; mhs.prodiKode = "TMK"; break;
        case '3': mhs.jurusan = "Teknik Perancangan Industri"; mhs.prodiKode = "TPM"; break;
        case '4': mhs.jurusan = "Rekayasa Teknik Mesin"; mhs.prodiKode = "RTM"; break;
        case '5': mhs.jurusan = "Perancangan Manufaktur"; mhs.prodiKode = "PM"; break;
        case '6': mhs.jurusan = "Teknologi Rekayasa Mekatronika"; mhs.prodiKode = "TRMK"; break;
        default: mhs.jurusan = "Tidak Diketahui"; mhs.prodiKode = "UNKNOWN"; break;
        }
    }
    else {
        mhs.jenjang = mhs.jurusan = "NIM Tidak Valid";
        mhs.prodiKode = "INVALID";
    }
}

bool compareByNim(const Mahasiswa& a, const Mahasiswa& b) {
    return a.nim < b.nim;
}

bool compareByProdi(const Mahasiswa& a, const Mahasiswa& b) {
    static const map<string, int> prodiOrder = {
        {"TMI", 1}, {"TMK", 2}, {"TPM", 3}, {"RTM", 4}, {"PM", 5}, {"TRMK", 6}
    };
    int orderA = prodiOrder.count(a.prodiKode) ? prodiOrder.at(a.prodiKode) : 99;
    int orderB = prodiOrder.count(b.prodiKode) ? prodiOrder.at(b.prodiKode) : 99;
    if (orderA != orderB) return orderA < orderB;
    return a.nim < b.nim;
}

void displayMahasiswa(const vector<Mahasiswa>& data, const string& title) {
    cout << "\n--- " << title << " ---" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "| NIM           | Nama            | Jenjang | Jurusan/Prodi                     |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (const auto& mhs : data) {
        printf("| %-13s | %-20s | %-7s | %-28s |\n", mhs.nim.c_str(), mhs.nama.c_str(), mhs.jenjang.c_str(), mhs.jurusan.c_str());
    }
    cout << "--------------------------------------------------------------------------------" << endl;
}

int main() {
    vector<Mahasiswa> daftarMahasiswa;
    char pilihan;

    do {
        cout << "\n===================================== " << endl;
        cout << "===== MENU UTAMA POLITEKNIK ATMI=====" << endl;
        cout << "===================================== " << endl;
        cout << "Pilihan : " << endl;
        cout << "1. input Data Mahasiswa" << endl;
        cout << "2. Keluar";
        cin >> pilihan;
        clearInputBuffer();

        if (pilihan == '1') {
            daftarMahasiswa.clear();
            cout << "\n--- Input Data ---" << endl;
            for (int i = 0; i < 3; ++i) {
                Mahasiswa mhs;
                cout << "Mahasiswa ke-" << i + 1 << endl;
                cout << "NIM: "; cin >> mhs.nim; clearInputBuffer();
                cout << "Nama: "; getline(cin, mhs.nama);
                parseNim(mhs);
                daftarMahasiswa.push_back(mhs);
            }

            vector<Mahasiswa> sortedByNim = daftarMahasiswa;
            sort(sortedByNim.begin(), sortedByNim.end(), compareByNim);
            displayMahasiswa(sortedByNim, "Data Diurutkan Berdasarkan NIM");

            vector<Mahasiswa> sortedByProdi = daftarMahasiswa;
            sort(sortedByProdi.begin(), sortedByProdi.end(), compareByProdi);
            displayMahasiswa(sortedByProdi, "Data Diurutkan Berdasarkan Prodi");

        }
        else if (pilihan != '2') {
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != '2');

    return 0;
}
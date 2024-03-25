#include <iostream>
#include <string>
using namespace std;

const int MAX_ALAT = 100; // Maksimum jumlah alat hadroh

struct Alat {
    int id;
    string nama;
    int jumlah;
};

Alat alat[MAX_ALAT];
int jumlahAlat = 0; // Jumlah alat hadroh saat ini

void tambahAlat() {
    if (jumlahAlat < MAX_ALAT) {
        cout << "Masukkan ID alat: ";
        cin >> alat[jumlahAlat].id;
        cout << "Masukkan nama alat: ";
        cin >> alat[jumlahAlat].nama;
        cout << "Masukkan jumlah alat: ";
        cin >> alat[jumlahAlat].jumlah;
        jumlahAlat++;
    } else {
        cout << "Kapasitas penyimpanan alat hadroh sudah penuh." << endl;
    }
}

void tampilkanAlat() {
    for (int i = 0; i < jumlahAlat; i++) {
        cout << "ID: " << alat[i].id << ", Nama: " << alat[i].nama << ", Jumlah: " << alat[i].jumlah << endl;
    }
}

void ubahAlat() {
    int cariID;
    cout << "Masukkan ID alat yang ingin diubah: ";
    cin >> cariID;
    for (int i = 0; i < jumlahAlat; i++) {
        if (alat[i].id == cariID) {
            cout << "Masukkan nama alat baru: ";
            cin >> alat[i].nama;
            cout << "Masukkan jumlah alat baru: ";
            cin >> alat[i].jumlah;
            return;
        }
    }
    cout << "Alat dengan ID tersebut tidak ditemukan." << endl;
}

void hapusAlat() {
    int cariID;
    cout << "Masukkan ID alat yang ingin dihapus: ";
    cin >> cariID;
    for (int i = 0; i < jumlahAlat; i++) {
        if (alat[i].id == cariID) {
            for (int j = i; j < jumlahAlat - 1; j++) {
                alat[j] = alat[j + 1];
            }
            jumlahAlat--;
            return;
        }
    }
    cout << "Alat dengan ID tersebut tidak ditemukan." << endl;
}

bool lanjutkan() {
    char pilihan;
    cout << "Apakah Anda ingin melanjutkan? (y/n): ";
    cin >> pilihan;
    return (pilihan == 'y' || pilihan == 'Y');
}

int menu() {
    char pilihan;

    cout << "Menu:" << endl;
    cout << "[1] Tambah Alat" << endl;
    cout << "[2] Tampilkan Alat" << endl;
    cout << "[3] Ubah Alat" << endl;
    cout << "[4] Hapus Alat" << endl;
    cout << "[5] Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case '1':
            tambahAlat();
            break;
        case '2':
            tampilkanAlat();
            break;
        case '3':
            ubahAlat();
            break;
        case '4':
            hapusAlat();
            break;
        case '5':
            cout << "Terimakasih Telah Menggunakan Program Kami" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    if (lanjutkan()) {
        menu(); // Panggil menu secara rekursif
    }

    return 0;
}

bool login() {
    string username;
    string nim;
    for (int i = 0; i < 3; i++) {
        cout << "Masukkan username: ";
        getline(cin, username);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (username == "Muhammad Ariando Ferdian" && nim == "2309106086") {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            cout << "Username atau NIM salah. Silakan coba lagi.\n" << endl;
        }
    }
    cout << "Anda telah mencoba login sebanyak 3 kali. Login gagal." << endl;
    return false;
}

int main() {
    if (login()) {
        menu();
    } else {
        cout << "Login gagal.\n";
    }
    return 0;
}

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

void tambahAlat(Alat* p_alat) {
    if (jumlahAlat < MAX_ALAT) {
        // Increment ID alat secara otomatis
        p_alat[jumlahAlat].id = jumlahAlat + 1;

        cout << "Masukkan nama alat: ";
        cin >> p_alat[jumlahAlat].nama;
        cout << "Masukkan jumlah alat: ";
        cin >> p_alat[jumlahAlat].jumlah;
        jumlahAlat++;
    } else {
        cout << "Kapasitas penyimpanan alat hadroh sudah penuh." << endl;
    }
}

void tampilkanAlat(Alat* p_alat) {
    for (int i = 0; i < jumlahAlat; i++) {
        cout << "ID: " << (p_alat + i)->id << ", Nama: " << (p_alat + i)->nama << ", Jumlah: " << (p_alat + i)->jumlah << endl;
    }
}

void ubahAlat(Alat* p_alat) {
    int cariID;
    cout << "Masukkan ID alat yang ingin diubah: ";
    cin >> cariID;
    for (int i = 0; i < jumlahAlat; i++) {
        if ((p_alat + i)->id == cariID) {
            cout << "Masukkan nama alat baru: ";
            cin >> (p_alat + i)->nama;
            cout << "Masukkan jumlah alat baru: ";
            cin >> (p_alat + i)->jumlah;
            return;
        }
    }
    cout << "Alat dengan ID tersebut tidak ditemukan." << endl;
}

void hapusAlat(Alat* p_alat) {
    int cariID;
    cout << "Masukkan ID alat yang ingin dihapus: ";
    cin >> cariID;
    for (int i = 0; i < jumlahAlat; i++) {
        if ((p_alat + i)->id == cariID) {
            for (int j = i; j < jumlahAlat - 1; j++) {
                *(p_alat + j) = *(p_alat + j + 1);
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
    cin.ignore(); // Membersihkan newline character dari input buffer
    return (pilihan == 'y' || pilihan == 'Y');
}

void bubbleSortHurufAsc(Alat* p_alat) {
    for (int i = 0; i < jumlahAlat - 1; i++) {
        for (int j = 0; j < jumlahAlat - i - 1; j++) {
            if ((p_alat + j)->nama > (p_alat + j + 1)->nama) {
                // Tukar posisi
                Alat temp = *(p_alat + j);
                *(p_alat + j) = *(p_alat + j + 1);
                *(p_alat + j + 1) = temp;
            }
        }
    }
}

void insertionSortAngkaDesc(Alat* p_alat) {
    for (int i = 1; i < jumlahAlat; i++) {
        Alat key = *(p_alat + i);
        int j = i - 1;
        while (j >= 0 && (p_alat + j)->jumlah < key.jumlah) {
            *(p_alat + j + 1) = *(p_alat + j);
            j = j - 1;
        }
        *(p_alat + j + 1) = key;
    }
}

int partition(Alat* p_alat, int low, int high) {
    Alat pivot = *(p_alat + high);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if ((p_alat + j)->id < pivot.id) {
            i++;
            Alat temp = *(p_alat + i);
            *(p_alat + i) = *(p_alat + j);
            *(p_alat + j) = temp;
        }
    }
    Alat temp = *(p_alat + i + 1);
    *(p_alat + i + 1) = *(p_alat + high);
    *(p_alat + high) = temp;
    return (i + 1);
}

void quickSort(Alat* p_alat, int low, int high) {
    if (low < high) {
        int pi = partition(p_alat, low, high);
        quickSort(p_alat, low, pi - 1);
        quickSort(p_alat, pi + 1, high);
    }
}

void quickSortAlat(Alat* p_alat) {
    quickSort(p_alat, 0, jumlahAlat - 1);
}

int binarySearchAsc(Alat* p_alat, int left, int right, int cariID) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((p_alat + mid)->id == cariID)
            return mid;
        if ((p_alat + mid)->id < cariID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchDesc(Alat* p_alat, int left, int right, int cariID) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((p_alat + mid)->id == cariID)
            return mid;
        if ((p_alat + mid)->id > cariID)
            left = mid - 1;
        else
            right = mid + 1;
    }
    return -1;
}

int menu(Alat* p_alat) {
    char pilihan;

    cout << "Menu:" << endl;
    cout << "[1] Tambah Alat" << endl;
    cout << "[2] Tampilkan Alat" << endl;
    cout << "[3] Ubah Alat" << endl;
    cout << "[4] Hapus Alat" << endl;
    cout << "[5] Bubble Sort (Huruf, Ascending)" << endl;
    cout << "[6] Insertion Sort (Angka, Descending)" << endl;
    cout << "[7] Quick Sort" << endl;
    cout << "[8] Binary Search Ascending" << endl;
    cout << "[9] Binary Search Descending" << endl;
    cout << "[0] Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;
    cin.ignore(); // Membersihkan newline character dari input buffer

    switch (pilihan) {
        case '1':
            tambahAlat(p_alat);
            break;
        case '2':
            tampilkanAlat(p_alat);
            break;
        case '3':
            ubahAlat(p_alat);
            break;
        case '4':
            hapusAlat(p_alat);
            break;
        case '5':
            bubbleSortHurufAsc(p_alat);
            cout << "Hasil Bubble Sort (Huruf, Ascending):" << endl;
            tampilkanAlat(p_alat); //
            break;
        case '6':
            insertionSortAngkaDesc(p_alat);
            cout << "Hasil Insertion Sort (Angka, Descending):" << endl;
            tampilkanAlat(p_alat);
            break;
        case '7':
            quickSortAlat(p_alat);
            cout << "Hasil Quick Sort:" << endl;
            tampilkanAlat(p_alat);
            break;
        case '8':
            int cariID_asc;
            cout << "Masukkan ID alat yang ingin dicari: ";
            cin >> cariID_asc;
            {
                int hasil = binarySearchAsc(p_alat, 0, jumlahAlat - 1, cariID_asc);
                if (hasil != -1) {
                cout << "Alat dengan ID " << cariID_asc << " ditemukan pada indeks: " << hasil << endl;
                } else {
                cout << "Alat dengan ID " << cariID_asc << " tidak ditemukan." << endl;
                }
            }
            break;
        case '9':
            int cariID_desc;
            cout << "Masukkan ID alat yang ingin dicari: ";
            cin >> cariID_desc;
            {
                int hasil = binarySearchDesc(p_alat, 0, jumlahAlat - 1, cariID_desc);
                if (hasil != -1) {
                cout << "Alat dengan ID " << cariID_desc << " ditemukan pada indeks: " << hasil << endl;
                } else {
                cout << "Alat dengan ID " << cariID_desc << " tidak ditemukan." << endl;
                }
            }
            break;
        case '0':
            cout << "Terimakasih Telah Menggunakan Program Kami" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    if (lanjutkan()) {
        menu(p_alat); // Panggil menu secara rekursif
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
        menu(alat);
    } else {
        cout << "Login gagal.\n";
    }
    return 0;
}


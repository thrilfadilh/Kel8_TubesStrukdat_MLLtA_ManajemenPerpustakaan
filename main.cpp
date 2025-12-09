#include <iostream>
#include <string>
using namespace std;

#include "list_buku.h"
#include "list_anggota.h"
#include "list_peminjaman.h"

void tambahRelasiBuku(Buku*, Peminjaman*);
void tambahRelasiAnggota(Anggota*, Peminjaman*);

int main() {
    ListBuku LB;
    ListAnggota LA;
    ListPeminjaman LP;

    createList(LB);
    createList(LA);
    createList(LP);

    int menu;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tambah Anggota\n";
        cout << "3. Tambah Peminjaman\n";
        cout << "4. Relasi Buku → Peminjaman\n";
        cout << "5. Relasi Anggota → Peminjaman\n";
        cout << "6. Tampilkan Semua\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            string id, judul, penulis;
            cout << "ID Buku: "; cin >> id;
            cout << "Judul: "; cin >> judul;
            cout << "Penulis: "; cin >> penulis;

            insertLast(LB, alokasiBuku(id, judul, penulis));
        }

        else if (menu == 2) {
            string id, nama;
            cout << "ID Anggota: "; cin >> id;
            cout << "Nama: "; cin >> nama;

            insertLast(LA, alokasiAnggota(id, nama));
        }

        else if (menu == 3) {
            string id, tanggal;
            cout << "ID Peminjaman: "; cin >> id;
            cout << "Tanggal: "; cin >> tanggal;

            insertLast(LP, alokasiPeminjaman(id, tanggal));
        }

        else if (menu == 4) {
            string idB, idP;
            cout << "ID Buku: "; cin >> idB;
            cout << "ID Peminjaman: "; cin >> idP;

            Buku *b = findBuku(LB, idB);
            Peminjaman *p = findPeminjaman(LP, idP);

            if (b && p) tambahRelasiBuku(b, p);
            else cout << "Data tidak ditemukan.\n";
        }

        else if (menu == 5) {
            string idA, idP;
            cout << "ID Anggota: "; cin >> idA;
            cout << "ID Peminjaman: "; cin >> idP;

            Anggota *a = findAnggota(LA, idA);
            Peminjaman *p = findPeminjaman(LP, idP);

            if (a && p) tambahRelasiAnggota(a, p);
            else cout << "Data tidak ditemukan.\n";
        }

        else if (menu == 6) {
            printInfo(LB);
            printInfo(LA);
            printInfo(LP);
        }

    } while (menu != 0);

    return 0;
}

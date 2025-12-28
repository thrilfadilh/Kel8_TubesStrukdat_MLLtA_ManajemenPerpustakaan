#include <iostream>
#include <string>

#include "list_buku.h"
#include "list_anggota.h"
#include "list_peminjaman.h"

using namespace std;

void pause() {
    cout << "\nTekan ENTER untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

int main() {
    ListBuku LB;
    ListAnggota LA;
    ListPeminjaman LP;

    createList(LB);
    createList(LA);
    createList(LP);

    int menu = -1;

    while (menu != 0) {
        cout << "\n========================================\n";
        cout << "      SISTEM MANAJEMEN PERPUSTAKAAN\n";
        cout << "========================================\n";
        cout << "1.  Tambah Buku\n";
        cout << "2.  Tambah Anggota\n";
        cout << "3.  Tambah Peminjaman\n";
        cout << "4.  Hapus Buku\n";
        cout << "5.  Hapus Anggota\n";
        cout << "6.  Hapus Peminjaman\n";
        cout << "7.  Cari Buku\n";
        cout << "8.  Cari Anggota\n";
        cout << "9.  Cari Peminjaman\n";
        cout << "10. Hubungkan Buku ke Peminjaman\n";
        cout << "11. Hubungkan Anggota ke Peminjaman\n";
        cout << "12. Hapus Relasi Buku-Peminjaman\n";
        cout << "13. Hapus Relasi Anggota-Peminjaman\n";
        cout << "14. Tampilkan Semua Buku\n";
        cout << "15. Tampilkan Semua Anggota\n";
        cout << "16. Tampilkan Semua Peminjaman\n";
        cout << "17. Tampilkan Peminjaman dari Buku\n";
        cout << "18. Tampilkan Peminjaman dari Anggota\n";
        cout << "19. Hitung Peminjaman per Buku\n";
        cout << "20. Hitung Peminjaman per Anggota\n";
        cout << "21. Edit Relasi Buku (ganti buku)\n";
        cout << "22. Edit Relasi Anggota (ganti anggota)\n";
        cout << "23. Cek Relasi Buku-Peminjaman\n";
        cout << "24. Cek Relasi Anggota-Peminjaman\n";
        cout << "25. Hitung Peminjaman Tanpa Relasi\n";
        cout << "0.  Keluar\n";
        cout << "----------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            string id, j, p;
            cout << "ID Buku: "; cin >> id;
            cout << "Judul: "; cin >> j;
            cout << "Penulis: "; cin >> p;
            insertLast(LB, alokasiBuku(id, j, p));
            cout << "Buku berhasil ditambahkan\n";
            pause();
        }

        else if (menu == 2) {
            string id, n;
            cout << "ID Anggota: "; cin >> id;
            cout << "Nama: "; cin >> n;
            insertLast(LA, alokasiAnggota(id, n));
            cout << "Anggota berhasil ditambahkan\n";
            pause();
        }

        else if (menu == 3) {
            string id, tp, tk;
            float d;
            cout << "ID Peminjaman: "; cin >> id;
            cout << "Tanggal Pinjam: "; cin >> tp;
            cout << "Tanggal Kembali: "; cin >> tk;
            cout << "Denda: "; cin >> d;
            insertLastPeminjaman(LP, alokasiPeminjaman(id, tp, tk, d));
            cout << "Peminjaman berhasil ditambahkan\n";
            pause();
        }

        else if (menu == 4) {
            string id;
            cout << "ID Buku: "; cin >> id;
            deleteBuku(LB, id);
            cout << "Proses hapus buku selesai\n";
            pause();
        }

        else if (menu == 5) {
            string id;
            cout << "ID Anggota: "; cin >> id;
            deleteAnggota(LA, id);
            cout << "Proses hapus anggota selesai\n";
            pause();
        }

        else if (menu == 6) {
            string id;
            cout << "ID Peminjaman: "; cin >> id;
            deletePeminjaman(LP, id);
            cout << "Proses hapus peminjaman selesai\n";
            pause();
        }

        else if (menu == 7) {
            string id;
            cout << "ID Buku: "; cin >> id;
            Buku *b = findBuku(LB, id);
            if (b) cout << "Buku ditemukan: " << b->judul << endl;
            else cout << "Buku tidak ditemukan\n";
            pause();
        }

        else if (menu == 8) {
            string id;
            cout << "ID Anggota: "; cin >> id;
            Anggota *a = findAnggota(LA, id);
            if (a) cout << "Anggota ditemukan: " << a->nama << endl;
            else cout << "Anggota tidak ditemukan\n";
            pause();
        }

        else if (menu == 9) {
            string id;
            cout << "ID Peminjaman: "; cin >> id;
            adrPeminjaman p = findPeminjaman(LP, id);
            if (p) cout << "Peminjaman ditemukan\n";
            else cout << "Peminjaman tidak ditemukan\n";
            pause();
        }

        else if (menu == 10) {
            string ib, ip;
            cout << "ID Buku: "; cin >> ib;
            cout << "ID Peminjaman: "; cin >> ip;
            tambahRelasiBuku(findBuku(LB, ib), findPeminjaman(LP, ip));
            cout << "Relasi buku berhasil dibuat\n";
            pause();
        }

        else if (menu == 11) {
            string ia, ip;
            cout << "ID Anggota: "; cin >> ia;
            cout << "ID Peminjaman: "; cin >> ip;
            tambahRelasiAnggota(findAnggota(LA, ia), findPeminjaman(LP, ip));
            cout << "Relasi anggota berhasil dibuat\n";
            pause();
        }

        else if (menu == 12) {
            string ib, ip;
            cout << "ID Buku: "; cin >> ib;
            cout << "ID Peminjaman: "; cin >> ip;
            hapusRelasiBuku(findBuku(LB, ib), findPeminjaman(LP, ip));
            cout << "Relasi buku dihapus\n";
            pause();
        }

        else if (menu == 13) {
            string ia, ip;
            cout << "ID Anggota: "; cin >> ia;
            cout << "ID Peminjaman: "; cin >> ip;
            hapusRelasiAnggota(findAnggota(LA, ia), findPeminjaman(LP, ip));
            cout << "Relasi anggota dihapus\n";
            pause();
        }

        else if (menu == 14) {
            printInfo(LB);
            pause();
        }

        else if (menu == 15) {
            printInfo(LA);
            pause();
        }

        else if (menu == 16) {
            printInfo(LP);
            pause();
        }

        else if (menu == 17) {
            string ib;
            cout << "ID Buku: "; cin >> ib;
            showRelasiBuku(findBuku(LB, ib));
            pause();
        }

        else if (menu == 18) {
            string ia;
            cout << "ID Anggota: "; cin >> ia;
            showRelasiAnggota(findAnggota(LA, ia));
            pause();
        }

        else if (menu == 19) {
            string ib;
            cout << "ID Buku: "; cin >> ib;
            cout << "Jumlah Peminjaman: " << countRelasiBuku(findBuku(LB, ib)) << endl;
            pause();
        }

        else if (menu == 20) {
            string ia;
            cout << "ID Anggota: "; cin >> ia;
            cout << "Jumlah Peminjaman: " << countRelasiAnggota(findAnggota(LA, ia)) << endl;
            pause();
        }

        else if (menu == 21) {
            string ib1, ib2, ip;
            cout << "ID Buku Lama: "; cin >> ib1;
            cout << "ID Buku Baru: "; cin >> ib2;
            cout << "ID Peminjaman: "; cin >> ip;
            hapusRelasiBuku(findBuku(LB, ib1), findPeminjaman(LP, ip));
            tambahRelasiBuku(findBuku(LB, ib2), findPeminjaman(LP, ip));
            cout << "Relasi buku berhasil diubah\n";
            pause();
        }

        else if (menu == 22) {
            string ia1, ia2, ip;
            cout << "ID Anggota Lama: "; cin >> ia1;
            cout << "ID Anggota Baru: "; cin >> ia2;
            cout << "ID Peminjaman: "; cin >> ip;
            hapusRelasiAnggota(findAnggota(LA, ia1), findPeminjaman(LP, ip));
            tambahRelasiAnggota(findAnggota(LA, ia2), findPeminjaman(LP, ip));
            cout << "Relasi anggota berhasil diubah\n";
            pause();
        }

        else if (menu == 23) {
            string ib, ip;
            cout << "ID Buku: "; cin >> ib;
            cout << "ID Peminjaman: "; cin >> ip;
            Buku *b = findBuku(LB, ib);
            adrPeminjaman p = findPeminjaman(LP, ip);
            bool found = false;
            RelasiBuku *r = b ? b->relasi : NULL;
            while (r) {
                if (r->child == p) found = true;
                r = r->next;
            }
            if (found) cout << "Relasi ditemukan\n";
            else cout << "Relasi tidak ditemukan\n";
            pause();
        }

        else if (menu == 24) {
            string ia, ip;
            cout << "ID Anggota: "; cin >> ia;
            cout << "ID Peminjaman: "; cin >> ip;
            Anggota *a = findAnggota(LA, ia);
            adrPeminjaman p = findPeminjaman(LP, ip);
            bool found = false;
            RelasiAnggota *r = a ? a->relasi : NULL;
            while (r) {
                if (r->child == p) found = true;
                r = r->next;
            }
            if (found) cout << "Relasi ditemukan\n";
            else cout << "Relasi tidak ditemukan\n";
            pause();
        }

        else if (menu == 25) {
            int count = 0;
            adrPeminjaman p = LP.first;
            while (p) {
                bool ada = false;
                Buku *b = LB.first;
                if (b) {
                    do {
                        RelasiBuku *r = b->relasi;
                        while (r) {
                            if (r->child == p) ada = true;
                            r = r->next;
                        }
                        b = b->next;
                    } while (b != LB.first);
                }
                if (!ada) count++;
                p = p->next;
            }
            cout << "Jumlah peminjaman tanpa relasi buku: " << count << endl;
            pause();
        }
    }

    cout << "\nTerima kasih telah menggunakan sistem\n";
    return 0;
}

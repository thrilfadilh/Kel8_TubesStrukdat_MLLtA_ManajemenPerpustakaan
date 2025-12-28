#ifndef LIST_PEMINJAMAN_H
#define LIST_PEMINJAMAN_H

#include <string>
using namespace std;

struct elmPeminjaman {
    string idPeminjaman;
    string tanggalPinjam;
    string tanggalKembali;
    float denda;
    elmPeminjaman *next;
};

typedef elmPeminjaman* adrPeminjaman;

struct ListPeminjaman {
    adrPeminjaman first;
};

void createList(ListPeminjaman &L);
adrPeminjaman alokasiPeminjaman(string id, string pinjam, string kembali, float denda);
void insertLastPeminjaman(ListPeminjaman &L, adrPeminjaman p);
adrPeminjaman findPeminjaman(ListPeminjaman L, string id);
void deletePeminjaman(ListPeminjaman &L, string id);
void printInfo(ListPeminjaman L);

#endif

#ifndef LIST_PEMINJAMAN_H
#define LIST_PEMINJAMAN_H

#include <iostream>
#include <string>
using namespace std;

struct Peminjaman {
    string idPeminjaman;
    string tanggalPinjam;
    string tanggalKembali;
    float denda;
};

struct elmPeminjaman {
    Peminjaman info;
    elmPeminjaman *next;
};

typedef elmPeminjaman* adrPeminjaman;

struct ListPeminjaman {
    adrPeminjaman first;
};

struct Buku;
struct Anggota;

void createList(ListPeminjaman &L);
adrPeminjaman alokasiPinjam(Peminjaman x);
void insertLastPeminjaman(ListPeminjaman &L, adrPeminjaman p);
void deletePeminjaman(ListPeminjaman &LP, adrPeminjaman p);
adrPeminjaman findPinjam(ListPeminjaman L, string idPeminjaman);
void showAllPeminjaman(ListPeminjaman L);

void showChildByAnggota(ListPeminjaman L, Anggota* parent);
void showChildByBuku(ListPeminjaman L, Buku* parent);
void showAllAnggotaWithChild(ListPeminjaman L, ListAnggota LA);
void showAllBukuWithChild(ListPeminjaman L, ListBuku LB);
void showChildWithParents(ListPeminjaman L);
void showParentsOfChild(ListPeminjaman L, string idPeminjaman);

void tambahRelasiBuku(Buku *parent, adrPeminjaman child);
void tambahRelasiAnggota(Anggota *parent, adrPeminjaman child);

#endif

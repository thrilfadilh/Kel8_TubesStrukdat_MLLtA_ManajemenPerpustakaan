#ifndef LIST_ANGGOTA_H
#define LIST_ANGGOTA_H

#include <iostream>
#include <string>
using namespace std;

struct elmPeminjaman;
typedef elmPeminjaman* adrPeminjaman;

struct RelasiAnggota {
    adrPeminjaman child;
    RelasiAnggota *next;
};

struct Anggota {
    string idAnggota;
    string nama;

    RelasiAnggota *relasi;
    Anggota *next;
    Anggota *prev;
};

struct ListAnggota {
    Anggota *first;
    Anggota *last;
};

void createList(ListAnggota &L);
Anggota* alokasiAnggota(string id, string nama);

void insertLast(ListAnggota &L, Anggota *p);
Anggota* findAnggota(ListAnggota L, string id);
void deleteAnggota(ListAnggota &L, string id);

void printInfo(ListAnggota L);

void tambahRelasiAnggota(Anggota *parent, adrPeminjaman child);
void hapusRelasiAnggota(Anggota *parent, adrPeminjaman child);

void showRelasiAnggota(Anggota *parent);
int countRelasiAnggota(Anggota *parent);

#endif

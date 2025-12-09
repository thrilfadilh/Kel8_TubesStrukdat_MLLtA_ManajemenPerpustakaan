#ifndef LIST_ANGGOTA_H
#define LIST_ANGGOTA_H

#include <iostream>
#include <string>
using namespace std;

struct Peminjaman;

struct RelasiAnggota {
    Peminjaman *child;
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
void insertLast(ListAnggota &L, Anggota* p);
Anggota* findAnggota(ListAnggota L, string id);
void printInfo(ListAnggota L);

#endif

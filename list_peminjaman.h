#ifndef LIST_PEMINJAMAN_H
#define LIST_PEMINJAMAN_H

#include <iostream>
#include <string>
using namespace std;

struct Peminjaman {
    string idPeminjaman;
    string tanggal;
    Peminjaman *next;
};

struct ListPeminjaman {
    Peminjaman *first;
};

void createList(ListPeminjaman &L);
Peminjaman* alokasiPeminjaman(string id, string tanggal);
void insertLast(ListPeminjaman &L, Peminjaman* p);
Peminjaman* findPeminjaman(ListPeminjaman L, string id);
void printInfo(ListPeminjaman L);

#endif

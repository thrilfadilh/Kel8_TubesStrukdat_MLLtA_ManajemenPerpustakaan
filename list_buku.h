#ifndef LIST_BUKU_H
#define LIST_BUKU_H

#include <iostream>
#include <string>
using namespace std;

struct Peminjaman;

struct RelasiBuku {
    Peminjaman *child;
    RelasiBuku *next;
};

struct Buku {
    string idBuku;
    string judul;
    string penulis;

    RelasiBuku *relasi; // Relasi Tipe A
    Buku *next;         // CSLL
};

struct ListBuku {
    Buku *first;
};

void createList(ListBuku &L);
Buku* alokasiBuku(string id, string judul, string penulis);
void insertLast(ListBuku &L, Buku* p);
Buku* findBuku(ListBuku L, string id);
void printInfo(ListBuku L);

#endif

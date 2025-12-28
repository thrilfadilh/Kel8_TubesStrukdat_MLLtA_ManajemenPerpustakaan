#ifndef LIST_BUKU_H
#define LIST_BUKU_H

#include <iostream>
#include <string>
using namespace std;

struct elmPeminjaman;
typedef elmPeminjaman* adrPeminjaman;

struct RelasiBuku {
    adrPeminjaman child;
    RelasiBuku *next;
};

struct Buku {
    string idBuku;
    string judul;
    string penulis;

    RelasiBuku *relasi;
    Buku *next;
};

struct ListBuku {
    Buku *first;
};

void createList(ListBuku &L);
Buku* alokasiBuku(string id, string judul, string penulis);
void insertLast(ListBuku &L, Buku *p);
Buku* findBuku(ListBuku L, string id);
void deleteBuku(ListBuku &L, string id);
void printInfo(ListBuku L);

void showRelasiBuku(Buku *parent);
int countRelasiBuku(Buku *parent);

void tambahRelasiBuku(Buku *parent, adrPeminjaman child);
void hapusRelasiBuku(Buku *parent, adrPeminjaman child);

#endif

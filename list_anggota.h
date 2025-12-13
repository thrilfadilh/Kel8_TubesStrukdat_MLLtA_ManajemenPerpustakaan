#ifndef LIST_ANGGOTA_H
#define LIST_ANGGOTA_H

#include <iostream>
#include <string>
using namespace std;

/* Forward declaration */
struct Peminjaman;

/* ===== RELASI (TIDAK DIGUNAKAN DI TIPE A, DISIMPAN NULL) ===== */
struct RelasiAnggota {
    Peminjaman *child;
    RelasiAnggota *next;
};

/* ===================== NODE ANGGOTA ===================== */
struct Anggota {
    string idAnggota;
    string nama;

    RelasiAnggota *relasi; // tidak digunakan (MLL Tipe A)
    Anggota *next;
    Anggota *prev;
};

/* ===================== LIST ANGGOTA (DLL) ===================== */
struct ListAnggota {
    Anggota *first;
    Anggota *last;
};

/* ===================== PRIMITIF LIST ===================== */
void createList(ListAnggota &L);
Anggota* alokasiAnggota(string id, string nama);

/* ===================== INSERT ===================== */
void insertFirst(ListAnggota &L, Anggota* p);
void insertLast(ListAnggota &L, Anggota* p);

/* ===================== DELETE ===================== */
void deleteFirst(ListAnggota &L);
void deleteLast(ListAnggota &L);
void deleteByID(ListAnggota &L, string id);

/* ===================== FIND ===================== */
Anggota* findAnggota(ListAnggota L, string id);

/* ===================== PRINT ===================== */
void printInfo(ListAnggota L);
void printReverse(ListAnggota L);

#endif

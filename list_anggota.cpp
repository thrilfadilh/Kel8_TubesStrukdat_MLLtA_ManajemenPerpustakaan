#include <iostream>
#include "list_anggota.h"
#include "list_peminjaman.h"

using namespace std;

void createList(ListAnggota &L) {
    L.first = NULL;
    L.last = NULL;
}

Anggota* alokasiAnggota(string id, string nama) {
    Anggota *p = new Anggota;
    p->idAnggota = id;
    p->nama = nama;
    p->relasi = NULL;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertLast(ListAnggota &L, Anggota *p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

Anggota* findAnggota(ListAnggota L, string id) {
    Anggota *p = L.first;
    while (p != NULL) {
        if (p->idAnggota == id) return p;
        p = p->next;
    }
    return NULL;
}

void deleteAnggota(ListAnggota &L, string id) {
    Anggota *p = findAnggota(L, id);
    if (p == NULL) return;

    if (p == L.first && p == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else if (p == L.first) {
        L.first = p->next;
        L.first->prev = NULL;
    } else if (p == L.last) {
        L.last = p->prev;
        L.last->next = NULL;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    RelasiAnggota *r = p->relasi;
    while (r != NULL) {
        RelasiAnggota *del = r;
        r = r->next;
        delete del;
    }

    delete p;
}

void printInfo(ListAnggota L) {
    cout << "\n=== DATA ANGGOTA ===\n";
    Anggota *p = L.first;
    if (p == NULL) {
        cout << "Kosong\n";
        return;
    }
    while (p != NULL) {
        cout << "ID   : " << p->idAnggota << endl;
        cout << "Nama : " << p->nama << endl;
        cout << "---------------------\n";
        p = p->next;
    }
}

int countRelasiAnggota(Anggota *parent) {
    int count = 0;
    RelasiAnggota *r = parent->relasi;
    while (r != NULL) {
        count++;
        r = r->next;
    }
    return count;
}

void showRelasiAnggota(Anggota *parent) {
    cout << "\nPeminjaman oleh " << parent->nama << endl;
    RelasiAnggota *r = parent->relasi;

    if (r == NULL) {
        cout << "Belum ada peminjaman\n";
        return;
    }

    while (r != NULL) {
        cout << "- ID Peminjaman: " << r->child->idPeminjaman << endl;
        r = r->next;
    }
}

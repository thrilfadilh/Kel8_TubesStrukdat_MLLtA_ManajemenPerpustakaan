#include <iostream>
#include "list_buku.h"
#include "list_peminjaman.h"

using namespace std;

void createList(ListBuku &L) {
    L.first = NULL;
}

Buku* alokasiBuku(string id, string judul, string penulis) {
    Buku *p = new Buku;
    p->idBuku = id;
    p->judul = judul;
    p->penulis = penulis;
    p->relasi = NULL;
    p->next = NULL;
    return p;
}

void insertLast(ListBuku &L, Buku *p) {
    if (L.first == NULL) {
        L.first = p;
        p->next = p;
    } else {
        Buku *q = L.first;
        while (q->next != L.first) q = q->next;
        q->next = p;
        p->next = L.first;
    }
}

Buku* findBuku(ListBuku L, string id) {
    if (L.first == NULL) return NULL;

    Buku *p = L.first;
    do {
        if (p->idBuku == id) return p;
        p = p->next;
    } while (p != L.first);

    return NULL;
}

void deleteBuku(ListBuku &L, string id) {
    if (L.first == NULL) return;

    Buku *p = L.first;
    Buku *prev = NULL;

    do {
        if (p->idBuku == id) break;
        prev = p;
        p = p->next;
    } while (p != L.first);

    if (p->idBuku != id) return;

    if (p == L.first && p->next == L.first) {
        L.first = NULL;
    } else {
        if (p == L.first) {
            Buku *last = L.first;
            while (last->next != L.first) last = last->next;
            L.first = p->next;
            last->next = L.first;
        } else {
            prev->next = p->next;
        }
    }

    RelasiBuku *r = p->relasi;
    while (r != NULL) {
        RelasiBuku *del = r;
        r = r->next;
        delete del;
    }

    delete p;
}

void printInfo(ListBuku L) {
    cout << "\n=== DATA BUKU ===\n";
    if (L.first == NULL) {
        cout << "Kosong\n";
        return;
    }

    Buku *p = L.first;
    do {
        cout << "ID      : " << p->idBuku << endl;
        cout << "Judul   : " << p->judul << endl;
        cout << "Penulis : " << p->penulis << endl;
        cout << "---------------------\n";
        p = p->next;
    } while (p != L.first);
}

void showRelasiBuku(Buku *parent) {
    cout << "\nRiwayat Peminjaman Buku: " << parent->judul << endl;
    RelasiBuku *r = parent->relasi;

    if (r == NULL) {
        cout << "Belum pernah dipinjam\n";
        return;
    }

    while (r != NULL) {
        cout << "- ID Peminjaman: " << r->child->idPeminjaman << endl;
        r = r->next;
    }
}

int countRelasiBuku(Buku *parent) {
    int count = 0;
    RelasiBuku *r = parent->relasi;
    while (r != NULL) {
        count++;
        r = r->next;
    }
    return count;
}

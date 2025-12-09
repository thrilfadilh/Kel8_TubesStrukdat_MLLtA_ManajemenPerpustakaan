#include "list_peminjaman.h"

void createList(ListPeminjaman &L) {
    L.first = NULL;
}

Peminjaman* alokasiPeminjaman(string id, string tanggal) {
    Peminjaman *p = new Peminjaman;
    p->idPeminjaman = id;
    p->tanggal = tanggal;
    p->next = NULL;
    return p;
}

void insertLast(ListPeminjaman &L, Peminjaman* p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        Peminjaman *q = L.first;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

Peminjaman* findPeminjaman(ListPeminjaman L, string id) {
    Peminjaman *p = L.first;
    while (p != NULL) {
        if (p->idPeminjaman == id) return p;
        p = p->next;
    }
    return NULL;
}

void printInfo(ListPeminjaman L) {
    cout << "\n=== LIST PEMINJAMAN (CHILD) ===\n";
    if (L.first == NULL) {
        cout << "Kosong\n";
        return;
    }

    Peminjaman *p = L.first;
    while (p != NULL) {
        cout << "- ID: " << p->idPeminjaman
             << " | Tanggal: " << p->tanggal << endl;
        p = p->next;
    }
}

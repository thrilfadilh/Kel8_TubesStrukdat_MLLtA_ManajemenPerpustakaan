#include "list_buku.h"

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

void insertLast(ListBuku &L, Buku* p) {
    if (L.first == NULL) {
        L.first = p;
        p->next = p; // circular
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

void printInfo(ListBuku L) {
    cout << "\n=== LIST BUKU (PARENT 1) ===\n";
    if (L.first == NULL) {
        cout << "Kosong\n";
        return;
    }

    Buku *p = L.first;
    do {
        cout << "- ID: " << p->idBuku
             << " | Judul: " << p->judul
             << " | Penulis: " << p->penulis << endl;
        p = p->next;
    } while (p != L.first);
}

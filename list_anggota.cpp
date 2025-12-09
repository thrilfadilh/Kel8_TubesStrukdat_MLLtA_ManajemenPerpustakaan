#include "list_anggota.h"

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

void insertLast(ListAnggota &L, Anggota* p) {
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

void printInfo(ListAnggota L) {
    cout << "\n=== LIST ANGGOTA (PARENT 2) ===\n";
    if (L.first == NULL) {
        cout << "Kosong\n";
        return;
    }

    Anggota *p = L.first;
    while (p != NULL) {
        cout << "- ID: " << p->idAnggota
             << " | Nama: " << p->nama << endl;
        p = p->next;
    }
}

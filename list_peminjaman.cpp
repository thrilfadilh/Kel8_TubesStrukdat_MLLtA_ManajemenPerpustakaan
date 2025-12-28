#include <iostream>
#include "list_peminjaman.h"

using namespace std;

void createList(ListPeminjaman &L) {
    L.first = NULL;
}

adrPeminjaman alokasiPeminjaman(string id, string pinjam, string kembali, float denda) {
    adrPeminjaman p = new elmPeminjaman;
    p->idPeminjaman = id;
    p->tanggalPinjam = pinjam;
    p->tanggalKembali = kembali;
    p->denda = denda;
    p->next = NULL;
    return p;
}

void insertLastPeminjaman(ListPeminjaman &L, adrPeminjaman p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        adrPeminjaman q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

adrPeminjaman findPeminjaman(ListPeminjaman L, string id) {
    adrPeminjaman p = L.first;
    while (p != NULL) {
        if (p->idPeminjaman == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deletePeminjaman(ListPeminjaman &L, string id) {
    if (L.first == NULL) return;

    adrPeminjaman p = L.first;

    if (p->idPeminjaman == id) {
        L.first = p->next;
        delete p;
        return;
    }

    while (p->next != NULL && p->next->idPeminjaman != id) {
        p = p->next;
    }

    if (p->next != NULL) {
        adrPeminjaman del = p->next;
        p->next = del->next;
        delete del;
    }
}

void printInfo(ListPeminjaman L) {
    cout << "\nDATA PEMINJAMAN\n";
    cout << "----------------------------\n";

    if (L.first == NULL) {
        cout << "Belum ada data peminjaman\n";
        return;
    }

    adrPeminjaman p = L.first;
    while (p != NULL) {
        cout << "ID            : " << p->idPeminjaman << endl;
        cout << "Tanggal Pinjam: " << p->tanggalPinjam << endl;
        cout << "Tanggal Kembali: " << p->tanggalKembali << endl;
        cout << "Denda         : " << p->denda << endl;
        cout << "----------------------------\n";
        p = p->next;
    }
}

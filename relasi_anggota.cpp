#include "list_anggota.h"

void tambahRelasiAnggota(Anggota *parent, adrPeminjaman child) {
    if (parent == NULL || child == NULL) return;

    RelasiAnggota *r = new RelasiAnggota;
    r->child = child;
    r->next = parent->relasi;
    parent->relasi = r;
}

void hapusRelasiAnggota(Anggota *parent, adrPeminjaman child) {
    if (parent == NULL || parent->relasi == NULL) return;

    RelasiAnggota *r = parent->relasi;

    if (r->child == child) {
        parent->relasi = r->next;
        delete r;
        return;
    }

    while (r->next != NULL && r->next->child != child) {
        r = r->next;
    }

    if (r->next != NULL) {
        RelasiAnggota *del = r->next;
        r->next = del->next;
        delete del;
    }
}

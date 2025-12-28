#include "list_buku.h"

void tambahRelasiBuku(Buku *parent, adrPeminjaman child) {
    if (parent == NULL || child == NULL) return;

    RelasiBuku *r = new RelasiBuku;
    r->child = child;
    r->next = parent->relasi;
    parent->relasi = r;
}

void hapusRelasiBuku(Buku *parent, adrPeminjaman child) {
    if (parent == NULL || parent->relasi == NULL) return;

    RelasiBuku *r = parent->relasi;

    if (r->child == child) {
        parent->relasi = r->next;
        delete r;
        return;
    }

    while (r->next != NULL && r->next->child != child) {
        r = r->next;
    }

    if (r->next != NULL) {
        RelasiBuku *del = r->next;
        r->next = del->next;
        delete del;
    }
}

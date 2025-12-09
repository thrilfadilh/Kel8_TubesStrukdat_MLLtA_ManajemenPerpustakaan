#include "list_buku.h"
#include "list_peminjaman.h"

void tambahRelasiBuku(Buku *parent, Peminjaman *child) {
    RelasiBuku *r = new RelasiBuku;
    r->child = child;
    r->next = parent->relasi;
    parent->relasi = r;
}

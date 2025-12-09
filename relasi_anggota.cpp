#include "list_anggota.h"
#include "list_peminjaman.h"

void tambahRelasiAnggota(Anggota *parent, Peminjaman *child) {
    RelasiAnggota *r = new RelasiAnggota;
    r->child = child;
    r->next = parent->relasi;
    parent->relasi = r;
}

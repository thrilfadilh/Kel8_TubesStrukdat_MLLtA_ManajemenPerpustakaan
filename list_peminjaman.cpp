#include "list_peminjaman.h"

void createList(ListPeminjaman &L) {
    L.first = NULL;
}

adrPeminjaman alokasiPeminjaman(string id, string tPinjam, string tKembali, float denda) {
    adrPeminjaman P = new elmPeminjaman;
    P->info.idPeminjaman = id;
    P->info.tanggalPinjam = tPinjam;
    P->info.tanggalKembali = tKembali;
    P->info.denda = denda;
    P->next = NULL;
    return P;
}

void insertLastPeminjaman(ListPeminjaman &L, adrPeminjaman P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrPeminjaman Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrPeminjaman findPeminjaman(ListPeminjaman L, string id) {
    adrPeminjaman P = L.first;
    while (P != NULL) {
        if (P->info.idPeminjaman == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deletePeminjaman(ListPeminjaman &LP, adrPeminjaman p) {
    if (LP.first == NULL || p == NULL) return;
    if (LP.first == p) {
        LP.first = LP.first->next;
        delete p;
        return;
    }
    adrPeminjaman prev = LP.first;
    while (prev->next != NULL && prev->next != p) prev = prev->next;
    if (prev->next == p) {
        prev->next = p->next;
        delete p;
    }
}

void showAllPeminjaman(ListPeminjaman L) {
    if (L.first == NULL) {
        cout << "List Peminjaman kosong.\n";
        return;
    }

    adrPeminjaman p = L.first;
    while (p != NULL) {
        cout << "- ID: " << p->info.idPeminjaman
             << ", Tanggal Pinjam: " << p->info.tanggalPinjam
             << ", Tanggal Kembali: " << p->info.tanggalKembali
             << ", Denda: " << p->info.denda << endl;
        p = p->next;
    }
}

void showChildDariParentBuku(Buku *b) {
    cout << "Data peminjaman untuk Buku: " << b->judul << endl;

    RelasiBuku *r = b->relasi;
    if (r == NULL) {
        cout << "(Tidak ada peminjaman)\n";
        return;
    }
    while (r != NULL) {
        cout << "- ID Peminjaman: " << r->child->info.idPeminjaman << endl;
        r = r->next;
    }
}

void showChildDariParentAnggota(Anggota *a) {
    cout << "Data peminjaman untuk Anggota: " << a->nama << endl;

    RelasiAnggota *r = a->relasi;
    if (r == NULL) {
        cout << "(Tidak ada peminjaman)\n";
        return;
    }
    while (r != NULL) {
        cout << "- ID Peminjaman: " << r->child->info.idPeminjaman << endl;
        r = r->next;
    }
}

void showParentBukuDariChild(ListBuku LB, adrPeminjaman c) {
    Buku *b = LB.first;
    if (b == NULL) return;

    bool found = false;
    do {
        RelasiBuku *r = b->relasi;
        while (r != NULL) {
            if (r->child == c) {
                cout << "- Buku: " << b->judul << endl;
                found = true;
            }
            r = r->next;
        }
        b = b->next;
    } while (b != LB.first);

    if (!found) {
        cout << "Child tidak berelasi dengan buku manapun.\n";
    }
}

void showParentAnggotaDariChild(ListAnggota LA, adrPeminjaman c) {
    Anggota *a = LA.first;
    if (a == NULL) return;

    bool found = false;
    while (a != NULL) {
        RelasiAnggota *r = a->relasi;
        while (r != NULL) {
            if (r->child == c) {
                cout << "- Anggota: " << a->nama << endl;
                found = true;
            }
            r = r->next;
        }
        a = a->next;
    }
    if (!found) {
        cout << "Child tidak berelasi dengan anggota manapun.\n";
    }
}

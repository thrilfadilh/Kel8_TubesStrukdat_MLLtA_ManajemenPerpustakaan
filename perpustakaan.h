#ifndef PERPUSTAKAAN_H_INCLUDED
#define PERPUSTAKAAN_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int ID_Buku;
    string Judul;
    int Tahun_Terbit;
    int Stok;
    string Penulis;
    float Harga;
};

struct Anggota {
    int ID_Anggota;
    string Nama;
    int Umur;
    string Alamat;
    string Jenis_Member;
    float Potongan_Denda;
};

struct Peminjaman {
    Anggota peminjam;
    string Tanggal_Pinjam;
    string Tanggal_Kembali;
    float Denda;
};

#endif

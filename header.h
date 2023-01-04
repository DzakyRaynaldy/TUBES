#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;

struct Paslon{
    int nomorUrut;
    string nama_ketua;
    string nama_wakil;
};

typedef struct elmPaslon *paslon_adr;

struct elmPaslon{
    Paslon info;
    paslon_adr next;
};

struct Pemilih {
    string nama;
    int umur;
    string daerah;
};

typedef struct elmPemilih *pemilih_adr;

struct elmPemilih{
    Pemilih info;
    paslon_adr pilihan;
    pemilih_adr next,prev;
};

//pemilih DLL
struct list_pemilih{
    pemilih_adr first,last;
};

//paslon SLL
struct list_paslon{
    paslon_adr first;
};

void createListPaslon(list_paslon &L);
void createListPemilih(list_pemilih &L);

paslon_adr createPaslon(int nomor_urut,string nama_ketua,string nama_wakil);
pemilih_adr createPemilih(string nama,int umur,string daerah);

void insertFirstPaslon(list_paslon &L, paslon_adr &p);
void insertLastPaslon(list_paslon &L,paslon_adr p);
void insertAfterPaslon(paslon_adr &p, paslon_adr &q);

paslon_adr deleteFirstPaslon(list_paslon &L);
paslon_adr deleteLastPaslon(list_paslon &L);
paslon_adr deleteAfterPaslon(paslon_adr &p);

paslon_adr searchPaslon(list_paslon L, string nama);

void insertFirstPemilih(list_pemilih &L, pemilih_adr &p);
void insertLastPemilih(list_pemilih &L,pemilih_adr &p);
void insertAfterPemilih(pemilih_adr &p, pemilih_adr &q);

pemilih_adr deleteFirstPemilih(list_pemilih &L);
pemilih_adr deleteLastPemilih(list_pemilih &L);
pemilih_adr deleteAfterPemilih(pemilih_adr &p);

pemilih_adr searchPemilih(list_pemilih L, string nama);
void pilihCalon(pemilih_adr &p, paslon_adr q);
void hapusPilihan(pemilih_adr &p);

#endif // HEADER_H_INCLUDED

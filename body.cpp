#include "header.h"

void createListPaslon(list_paslon &L){
    L.first = NULL;
}
void createListPemilih(list_pemilih &L){
    L.first=NULL;
    L.last=NULL;
}

paslon_adr createPaslon(int nomor_urut,string nama_ketua,string nama_wakil){
    paslon_adr p;
    p = new elmPaslon;
    p->info.nomorUrut = nomor_urut;
    p->info.nama_ketua = nama_ketua;
    p->info.nama_wakil = nama_wakil;
    p->next=NULL;
    return p;
}
pemilih_adr createPemilih(string nama,int umur,string daerah){
    pemilih_adr p = new elmPemilih;
    p->info.nama = nama;
    p->info.umur = umur;
    p->info.daerah = daerah;
    p->pilihan = NULL;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertFirstPaslon(list_paslon &L, paslon_adr &p){
    p->next = L.first;
    L.first = p;
}
void insertLastPaslon(list_paslon &L,paslon_adr p){
    paslon_adr q;
    q = L.first;
    if(q != NULL){
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }else{
        L.first = p;
    }
}
void insertAfterPaslon(paslon_adr &p, paslon_adr &q){
    q->next = p->next;
    p->next = q;
}

paslon_adr deleteFirstPaslon(list_paslon &L){
    paslon_adr p;
    p = L.first;
    L.first = L.first->next;
    p->next=NULL;
    return p;
}
paslon_adr deleteLastPaslon(list_paslon &L){
    paslon_adr p,q;
    p = L.first;
    if(p->next == NULL){
        L.first = NULL;
        return p;
    }
    while(p->next != NULL){
        q=p;
        p=p->next;
    }
    q->next = NULL;
    return p;
}
paslon_adr deleteAfterPaslon(paslon_adr &p){

    if(p!=NULL){
        paslon_adr q = p->next;
        p->next = q->next;
        q->next = NULL;
        return q;
    }
    return NULL;
}

paslon_adr searchPaslon(list_paslon L, string nama){
    paslon_adr p = L.first;
    while(p!=NULL && p->info.nama_ketua != nama){
        p=p->next;
    }
    return p;
}

void insertFirstPemilih(list_pemilih &L, pemilih_adr &p){
    p->next=L.first;

    if(L.last == NULL){
        L.last = p;
    }else{
        L.first->prev=p;
    }
    L.first = p;
}
void insertLastPemilih(list_pemilih &L,pemilih_adr &p){
    p->prev=L.last;

    if(L.first == NULL){
        L.first = p;
    }else{
        L.last->next=p;
    }
    L.last = p;
}
void insertAfterPemilih(pemilih_adr &p, pemilih_adr &q){
    if(p!=NULL){
        p->next = q->next;
        p->next->prev = p;
        q->next = NULL;
        q->prev = NULL;
    }
}

pemilih_adr deleteFirstPemilih(list_pemilih &L){
    pemilih_adr p;
    p = L.first;
    L.first=L.first->next;
    if(L.first==NULL){
        L.last = NULL;
    }else{
        L.first->prev = NULL;
    }
    p->next = NULL;
    return p;
}
pemilih_adr deleteLastPemilih(list_pemilih &L){
    pemilih_adr p;
    p = L.last;
    L.last=L.last->prev;
    if(L.last==NULL){
        L.first = NULL;
    }else{
        L.last->next = NULL;
    }
    p->prev = NULL;
    return p;
}
pemilih_adr deleteAfterPemilih(pemilih_adr &p){
    p->next->prev = p->prev;
    p->prev->next = p->next;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

pemilih_adr searchPemilih(list_pemilih L, string nama){
    pemilih_adr p = L.first;
    while(p!=NULL && p->info.nama != nama){
        p=p->next;
    }
    return p;
}

void pilihCalon(pemilih_adr &p, paslon_adr q){
    p->pilihan = q;
}
void hapuspilihan(pemilih_adr &p){
    p->pilihan = NULL;
}

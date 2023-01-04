#include "Pemilu.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    list_paslon LPas;
    list_pemilih LPem;
    int pilihan, one, two, three, coblos;
    string nama_ketua,nama_wakil, nama_pemilih, daerah;
    int nomorUrut, umur;
    paslon_adr P;
    pemilih_adr Q;
    infotypepaslon X;
    infotypepemilih Y;
    one = 0;
    two = 0;
    three = 0;
    createListPaslon(LPas);
    createListPemilih(LPem);
    do
    {
        cout << "1. Tambah paslon" << endl;
        cout << "2. Hapus paslon" << endl;
        cout << "3. Tambah pemilih" << endl;
        cout << "4. Hapus pemilih" << endl;
        cout << "5. Pilih paslon" << endl;
        cout << "6. Pemilu selesai" << endl;
        cout << "Pilih:";
        cin >> pilihan;

        switch (pilihan){
            case 1 :
                cout << "Masukkan Nama Ketua: ";
                cin >> X.nama_ketua;
                cout << "Masukkan Nama Wakil Ketua: ";
                cin >> X.nama_wakil;
                cout << "Masukkan Nomor Urut: ";
                cin >> X.nomorUrut;
                P = createPaslon(X);
                insertLastPaslon(LPas, P);
                break;
            case 2 :
                deleteFirstPaslon(LPas);
                break;
            case 3 :
                cout << "Masukkan Nama: ";
                cin >> Y.nama;
                cout << "Masukkan Umur: ";
                cin >> Y.umur;
                cout << "Masukkan Daerah: ";
                cin >> Y.daerah;
                Q = createPemilih(Y);
                insertLastPemilih(LPem, Q);
                break;
            case 4 :
                deleteFirstPemilih(LPem);
                break;
            case 5 :
                cout << "Pilih Nomor Urut: ";
                cin >> coblos;
                if (coblos == 1){
                    one = one + 1;
                }
                else if (coblos == 2){
                    two = two + 1;
                }
                else if (coblos == 3){
                    three = three +1;
                }
                break;
            case 6:
                cout << "===========Pemilu Selesai============" << endl;
                cout << "Nomor Urut 1: " << one << "Pemilih" << endl;
                cout << "Nomor Urut 2: " << two << "Pemilih" << endl;
                cout << "Nomor Urut 3: " << three << "Pemilih" << endl;
                if ((one > two) && (one > three)){
                    cout << " Pemilihan dimenangkan oleh paslon nomor 1";
                }
                else if ((two > one) && (two > three)){
                    cout << " Pemilihan dimenangkan oleh paslon nomor 2";
                }
                else if ((three > one) && (three > two)){
                    cout << " Pemilihan dimenangkan oleh paslon nomor 3";
                }
                break;
            default :
                cout << "Pilihan Tidak Tersedia" << endl;
        }
    }
    while(pilihan != 6);



    return 0;
}

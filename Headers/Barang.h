#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED

#include <iostream>

using namespace std;

//////DLL Barang rental//////
struct BarangRental {
    int ID, jumlah;
    string nama, brand;
};

typedef struct elemBarang *addressBarang;

struct elemBarang {
    BarangRental info;
    addressBarang next;
};

struct ListBarang {
    addressBarang first, last;
};

#endif
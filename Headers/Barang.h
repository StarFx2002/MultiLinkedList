#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED

#include <iostream>

using namespace std;

//////DLL Barang rental//////
struct BarangRental {
    string nama, brand;
    int jumlah;
};

typedef struct elemBarang *addressBarang;

struct elemBarang {
    BarangRental info;
    addressBarang next, prev;
};

struct ListBarang {
    addressBarang first, last;
};

#endif
#include <iostream>
#include "Main.h"

void createListBarang(ListBarang &LBr) {
    first(LBr) = NULL;
    last(LBr) = NULL;
}

addressBarang createElemBarang(int jumlah, string nama, string brand){
    addressBarang barang = new elemBarang;
    info(barang).jumlah = jumlah;
    info(barang).nama = nama;
    info(barang).brand = brand;
    next(barang) = NULL;
    prev(barang) = NULL;
    return barang;
}

void insertLast(ListBarang &LBr, addressBarang barang) {
    if (first(LBr) == NULL) {
        first(LBr) = barang;
        last(LBr)= barang;
    } else if (first(LBr) == last(LBr)) {
        next(first(LBr)) = barang;
        prev(barang)=first(LBr);
        last(LBr) = barang;
    } else {
        next(last(LBr)) = barang;
        prev(barang) = last(LBr);
        last(LBr) = barang;
    }
}

void showBarangList(ListBarang LBr){
    if (first(LBr) != NULL) {
        cout << "Data Barang Rental : \n" << endl;
        addressBarang p = first(LBr); int i = 1;
        while (p != NULL) {
            cout << "Data [" << i << "]" << endl;
            cout << "Nama : " << info(p).nama << endl;
            cout << "Brand : " << info(p).brand << endl;
            cout << "Jumlah : " << info(p).jumlah << endl;
            cout << endl;
            p = next(p);
            i++;
        } 
        cout << "\n=============\n";
        cout << endl;
    } else {
        cout << "List Barang Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    }
}

addressBarang deleteFirst(ListBarang &LBr){
    addressBarang p = NULL;
    if (first(LBr) == NULL) {
        cout << "List Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    } else if (first(LBr) == last(LBr)) {
        p = first(LBr);
        first(LBr) = NULL;
        last(LBr) = NULL;
    } else {
        p = first(LBr);
        first(LBr)=next(p);
        prev(first(LBr))= NULL;
        next(p)=NULL;
    }
    return p;
}

addressBarang deleteLast(ListBarang &LBr) {
    addressBarang p = NULL;
    if (first(LBr) == NULL) {
        cout << "List Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    } else if (first(LBr) == last(LBr)) {
        p = first(LBr);
        first(LBr) = NULL;
        last(LBr) = NULL;
    } else {
        p = last(LBr);
        last(LBr) = prev(p);
        next(last(LBr)) = NULL;
        prev(p) = NULL;
    }
    return p;
}

addressBarang deleteBarang(ListBarang &LBr, addressBarang barang) {
    addressBarang p = NULL;
    if (first(LBr) == NULL) {
        cout << "List Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    } else if (first(LBr) == last(LBr) || barang == first(LBr)) {
        p = deleteFirst(LBr);  
    } else {
        addressBarang q = first(LBr);
        while (next(q) != barang) {
            q = next(q);
        }
        p = next(q);
        next(q) = next(next(q));
        prev(next(q)) = q;
        prev(p) = NULL;
    }
    return p;
}

addressBarang searchBarang(ListBarang &LBr, string nama) {
    if (first(LBr) != NULL) {
        addressBarang p = first(LBr);
        while (p != NULL) {
            if (toLowerCase(info(p).nama) == toLowerCase(nama)) {
                return p;
            }
            p = next(p);
        }
    } else {
        cout << "List Barang Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    }
    return NULL;
}
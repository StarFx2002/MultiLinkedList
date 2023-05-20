#include <iostream>
#include "Customer.h"
#include "Util.h"

addressChild createElemChild(addressBarang adrBarang) {
    addressChild ch = new elemChild;
    info(ch) = adrBarang;
    ch->nBarang = 0;
    next(ch) = NULL;
    return ch;
}

void insertChildLast(addressCustomer &customer, addressChild child) { //The problem is here, it doesnt want to insert it to the element
    if (child(info(customer)) == NULL) {
        child(info(customer)) = child;
    } else {
        while (next(child(info(customer))) != NULL) {
            child(info(customer)) = next(child(info(customer)));
        }
        next(child(info(customer))) = child;
    }
    info(customer).nChild++;
}

addressChild deleteChildFirst(addressCustomer &customer) {
    addressChild ch = NULL;
    if (child(info(customer)) == NULL) {
        cout << info(customer).nama << " tidak punya child";
        cout << "\n=============\n";
        cout << endl;
        return ch;
    } else if (next(child(info(customer))) == NULL) {
        ch = child(info(customer));
        child(info(customer)) = NULL;
        info(customer).nChild--;
        next(ch) = NULL;
        return ch;
    } else {
        ch = child(info(customer));
        child(info(customer)) = next(child(info(customer)));
        info(customer).nChild++;
        next(ch) = NULL;
        return ch;
    }
}

void showChildList(addressCustomer customer) {
    addressChild child = child(info(customer));
    if (child != NULL) {
        BarangRental infoBarang = info(info(child));
        cout << "Data Barang Rental " << info(customer).nama << " : " << endl << endl;
        addressChild p = child(info(customer)); int i = 1;
        while (p != NULL) {
            cout << "Data [" << i << "]" << endl;
            cout << "Nama : " << infoBarang.nama << endl;
            cout << "Brand : " << infoBarang.brand << endl;
            cout << "Jumlah : " << p->nBarang << endl;
            cout << endl;
            p = next(p);
            i++;
        } 
        cout << "\n=============\n";
        cout << endl;
    } else {
        cout << "List Rental " << info(customer).nama << " Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    }
}
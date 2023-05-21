#include <iostream>
#include "Customer.h"
#include "Util.h"

addressChild createElemChild(addressBarang adrBarang) {
    addressChild p = new elemChild;
    info(p) = adrBarang;
    next(p) = NULL;
    p->nBarang = 0;
    return p;
}

void insertChildLast(addressCustomer &adrCustomer, addressChild adrChild) {
    if (child(info(adrCustomer)) == NULL) {
        child(info(adrCustomer)) = adrChild;
    } else {
        addressChild p = child(info(adrCustomer));
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = adrChild;
    }
    info(adrCustomer).nChild++;
}

addressChild deleteChildFirst(addressCustomer &adrCustomer) {
    addressChild p = NULL;
    if (child(info(adrCustomer)) == NULL) {
        cout << info(adrCustomer).nama << " tidak ada rental";
        cout << "\n=============\n";
        cout << endl;
    } else if (next(child(info(adrCustomer))) == NULL) {
        p = child(info(adrCustomer));
        child(info(adrCustomer)) = NULL;
        info(adrCustomer).nChild--;
    } else {
        p = child(info(adrCustomer));
        child(info(adrCustomer)) = next(child(info(adrCustomer)));
        info(adrCustomer).nChild--;
        next(p) = NULL;
    }
    return p;
}

addressChild deleteChildLast(addressCustomer &adrCustomer) {
    addressChild p = NULL;
    if (child(info(adrCustomer)) == NULL) {
        cout << info(adrCustomer).nama << " tidak ada rental";
        cout << "\n=============\n";
        cout << endl;
    } else if (next(child(info(adrCustomer))) == NULL) {
        p = child(info(adrCustomer));
        child(info(adrCustomer)) = NULL;
        info(adrCustomer).nChild--;
    } else {
        addressChild q = child(info(adrCustomer));
        while (next(next(q)) != NULL) {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
        info(adrCustomer).nChild--;
    }
    return p;
}

addressChild deleteChild(addressCustomer &adrCustomer, addressChild adrChild) {
    addressChild p = NULL;
    if (child(info(adrCustomer)) == NULL) {
        cout << info(adrCustomer).nama << " tidak ada rental";
        cout << "\n=============\n";
        cout << endl;
    } else if (next(child(info(adrCustomer))) == NULL) {
        p = child(info(adrCustomer));
        child(info(adrCustomer)) = NULL;
        info(adrCustomer).nChild--;
    } else if (adrChild == child(info(adrCustomer))) {
        p = deleteChildFirst(adrCustomer);
    } else {
        addressChild q = child(info(adrCustomer));
        while (next(q) != adrChild) {
            q = next(q);
        }
        p = next(q);
        next(q) = next(next(q));
        info(adrCustomer).nChild--;
    }
    return p;
}

void showChildList(addressCustomer adrCustomer) {
    addressChild child = child(info(adrCustomer));
    if (child != NULL) {
        cout << "Data Barang Rental " << info(adrCustomer).nama << " : " << endl << endl;
        addressChild p = child(info(adrCustomer)); int i = 1;
        while (p != NULL) {
            cout << "Data [" << i << "]" << endl;
            cout << "Nama : " << info(info(p)).nama << endl;
            cout << "Brand : " << info(info(p)).brand << endl;
            cout << "Jumlah : " << p->nBarang << endl;
            cout << endl;
            p = next(p);
            i++;
        } 
        cout << "\n=============\n";
        cout << endl;
    } else {
        cout << "List Rental " << info(adrCustomer).nama << " Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    }
}

//Return barang rental setelah selesai
void returnBarang(addressCustomer &adrCustomer) {
    if (child(info(adrCustomer)) != NULL) {
        while (child(info(adrCustomer)) != NULL) {
            addressChild temp = deleteChildFirst(adrCustomer);
            info(info(temp)).jumlah += temp->nBarang;
        }
    }
}

addressChild searchChild(addressCustomer adrCustomer, string namaBarang) {
    if (child(info(adrCustomer)) != NULL) {
        addressChild p = child(info(adrCustomer));
        while (p != NULL) {
            if (toLowerCase(info(info(p)).nama) == toLowerCase(namaBarang)) {
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
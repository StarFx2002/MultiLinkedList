#include <iostream>
#include "Customer.h"
#include "Util.h"

void createListCustomer(ListCustomer &Lcs) {
    first(Lcs) = NULL;
}

addressCustomer createElemCustomer(Customer customer) {
    addressCustomer adrCustomer = new elemCustomer;
    info(adrCustomer).nama  = customer.nama;
    info(adrCustomer).NIK = customer.NIK;
    info(adrCustomer).umur = customer.umur;
    info(adrCustomer).child = NULL;
    return adrCustomer;
}

void insertLast(ListCustomer &Lcs, addressCustomer adrCustomer) {
    if (first(Lcs) == NULL) {
        first(Lcs) = adrCustomer;
        next(first(Lcs)) = adrCustomer;
    } else if (next(first(Lcs)) == first(Lcs)) {
        next(first(Lcs)) = adrCustomer;
        next(adrCustomer) = first(Lcs);
    } else {
        addressCustomer p = first(Lcs);
        while (next(p) != first(Lcs)) {
            p = next(p);
        }
        next(p) = adrCustomer;
        next(adrCustomer) = first(Lcs);
    }
}

void showCustomerList(ListCustomer Lcs) {
    cout << "Data Customer : \n" << endl;
    addressCustomer p = first(Lcs); int i = 1;
    do {
        cout << "Data [" << i << "]" << endl;
        cout << "Nama : " << info(p).nama << endl;
        cout << "NIK : " << info(p).NIK << endl;
        cout << "Umur : " << info(p).umur << endl;
        cout << endl;
        p = next(p);
        i++;
    } while (p != first(Lcs));
    cout << "\n=============\n";
    cout << endl;
}

addressCustomer deleteFirst(ListCustomer &Lcs) {
    addressCustomer p = NULL;
    if (first(Lcs) == NULL) {
        cout << "List Kosong!" << endl;
        return p;
    } else if (next(first(Lcs)) == first(Lcs)) {
        p = first(Lcs);
        first(Lcs) = NULL;
        next(p) = NULL;
        return p;
    } else {
        addressCustomer q = first(Lcs);
        while (next(q) != first(Lcs)) {
            q = next(q);
        }
        p = first(Lcs); 
        first(Lcs) = next(first(Lcs));
        next(p) = NULL;
        next(q) = first(Lcs);
        return p;
    }
}

addressCustomer searchCustomer(ListCustomer Lcs, string nama) {
    addressCustomer p = first(Lcs);
    do {
        cout << info(p).nama << endl;
        if (info(p).nama == nama) {
            return p;
        }
        p = next(p);
    } while (p != first(Lcs));
    return NULL;
}
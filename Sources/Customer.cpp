#include <iostream>
#include "../Headers/Customer.h"
#include "../Headers/Util.h"

void createListCustomer(ListCustomer &Lcs) {
    first(Lcs) = NULL;
}

addressCustomer createElemCustomer(string nama, string NIK, int umur) {
    addressCustomer customer = new elemCustomer;
    info(customer).nama  = nama;
    info(customer).NIK = NIK;
    info(customer).umur = umur;
    return customer;
}

void insertLast(ListCustomer &Lcs, addressCustomer customer) {
    if (first(Lcs) == NULL) {
        first(Lcs) = customer;
        next(first(Lcs)) = customer;
    } else if (next(first(Lcs)) == first(Lcs)) {
        next(first(Lcs)) = customer;
        next(customer) = first(Lcs);
    } else {
        addressCustomer p = first(Lcs);
        while (next(p) != first(Lcs)) {
            p = next(p);
        }
        next(p) = customer;
        next(customer) = first(Lcs);
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
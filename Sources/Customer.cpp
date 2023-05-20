#include <iostream>
#include "Main.h"

//Membuat list customer
void createListCustomer(ListCustomer &Lcs) {
    first(Lcs) = NULL;
}

//Membuat elemen customer
addressCustomer createElemCustomer(Customer customer) {
    addressCustomer adrCustomer = new elemCustomer;
    info(adrCustomer).nama  = customer.nama;
    info(adrCustomer).NIK = customer.NIK;
    info(adrCustomer).umur = customer.umur;
    info(adrCustomer).nChild = 0;
    child(info(adrCustomer)) = NULL;
    next(adrCustomer) = NULL;
    return adrCustomer;
}

//Insert data di elemen terakhir
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

//Print data customer ke layar
void showCustomerList(ListCustomer Lcs) {
    if (first(Lcs) != NULL) {
        cout << "Data Customer : \n" << endl;
        addressCustomer p = first(Lcs); int i = 1;
        do {
            cout << "Data [" << i << "]" << endl;
            cout << "Nama : " << info(p).nama << endl;
            cout << "NIK : " << info(p).NIK << endl;
            cout << "Umur : " << info(p).umur << endl;
            cout << "Rental : [" << info(p).nChild << "]" << endl; 
            cout << endl;
            p = next(p);
            i++;
        } while (p != first(Lcs));
        cout << "\n=============\n";
        cout << endl;
    } else {
        cout << "List Customer Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
    }
}

//Hapus data terakhir dari list Customer
addressCustomer deleteLast(ListCustomer &Lcs) {
    addressCustomer p = NULL;
    if (first(Lcs) == NULL) {
        cout << "List Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
        return p;
    } else if (next(first(Lcs)) == first(Lcs)) {
        p = first(Lcs);
        first(Lcs) = NULL;
        next(p) = NULL;
        return p;
    } else {
        addressCustomer q = first(Lcs);
        while (next(next(q)) != first(Lcs)) {
            q = next(q);
        } 
        p = next(q);
        next(p) = NULL;
        next(q) = first(Lcs);
        return p;
    }
}

//Hapus data pertama dari list Customer
addressCustomer deleteFirst(ListCustomer &Lcs) {
    addressCustomer p = NULL;
    if (first(Lcs) == NULL) {
        cout << "List Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
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

//Mirip delete after tetapi prec akan langsung otomatis data sebelum adrCustomer
addressCustomer deleteCustomer(ListCustomer &Lcs, addressCustomer adrCustomer) {
    addressCustomer p = NULL;
    if (first(Lcs) == NULL) {
        cout << "List Kosong!" << endl;
        cout << "\n=============\n";
        cout << endl;
        return p;
    } else if (next(first(Lcs)) == first(Lcs)) {
        p = first(Lcs);
        first(Lcs) = NULL;
        next(p) = NULL;
        return p;
    } else if (adrCustomer == first(Lcs)) {
        p = deleteFirst(Lcs);
        return p;
    } else {
        addressCustomer q = first(Lcs);
        while (next(q) != adrCustomer) {
            q = next(q);
        }
        p = next(q); 
        next(q) = next(next(q));
        next(p) = NULL;
        return p;
    }
}

//Mencari customer berdasarkan namanya
addressCustomer searchCustomer(ListCustomer Lcs, string nama) {
    addressCustomer p = first(Lcs);
    do {
        if (info(p).nama == nama) {
            return p;
        }
        p = next(p);
    } while (p != first(Lcs));
    return NULL;
}
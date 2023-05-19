#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include "Barang.h"
#include "Child.h"

using namespace std;

/////CSLL Customer//////
struct Customer {
    string nama, NIK;
    int umur;
    addressChild child;
};

typedef struct elemCustomer *addressCustomer;

struct elemCustomer {
    Customer info;
    addressCustomer next;
};

struct ListCustomer {
    addressCustomer first;
};

//Customer Functions
void createListCustomer(ListCustomer &Lcs);
addressCustomer createElemCustomer(string nama, string NIK, int umur);
void insertLast(ListCustomer &Lcs, addressCustomer customer);
void showCustomerList(ListCustomer Lcs);
addressCustomer deleteFirst(ListCustomer &Lcs);

#endif // CUSTOMER_H_INCLUDED

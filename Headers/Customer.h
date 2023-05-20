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
    int ID;
};

//Customer Functions
void createListCustomer(ListCustomer &Lcs);
addressCustomer createElemCustomer(Customer customer);
void insertLast(ListCustomer &Lcs, addressCustomer adrCustomer);
void showCustomerList(ListCustomer Lcs);
addressCustomer deleteFirst(ListCustomer &Lcs);
addressCustomer searchCustomer(ListCustomer Lcs, string nama);

//Child Functions
addressChild createElemChild(addressBarang adrBarang);
void insertChildLast(addressCustomer parent, addressChild child);
addressChild deleteChildFirst(addressCustomer parent);

#endif // CUSTOMER_H_INCLUDED

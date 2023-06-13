#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include "Child.h"

using namespace std;

/////CSLL Customer//////
struct Customer {
    string nama, NIK;
    int nChild, umur;
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

#endif // CUSTOMER_H_INCLUDED

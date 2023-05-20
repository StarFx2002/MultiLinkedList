#include <iostream>
#include "Customer.h"
#include "Util.h"

addressChild createElemChild(addressBarang adrBarang) {
    addressChild ch = new elemChild;
    info(ch) = adrBarang;
    next(ch) = NULL;
    return ch;
}

void insertChildLast(addressCustomer customer, addressChild child) {
    addressChild ch = info(customer).child;
    if (ch == NULL) {
        ch = child;
    } else {
        while (next(ch) != NULL) {
            ch = next(ch);
        }
        ch = child;
    }
}

addressChild deleteChildFirst(addressCustomer customer) {
    addressChild ch = NULL;
    if (info(customer).child == NULL) {
        cout << info(customer).nama << " tidak punya child";
        return ch;
    } else if (next(customer) == NULL) {
        ch = info(customer).child;
        info(customer).child = NULL;
        next(ch) = NULL;
        return ch;
    } else {
        ch = info(customer).child;
        info(customer).child = next(info(customer).child);
        next(ch) = NULL;
        return ch;
    }
}
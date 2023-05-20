#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include "Barang.h"

//////SLL Customer child//////
typedef struct elemChild *addressChild;

struct elemChild {
    int nBarang;
    addressBarang info;
    addressChild next;
};

#endif
#include <iostream>

#include "Main.h"

using namespace std;

int main() {
    ListCustomer Lcs;
    ListBarang Lbr;

    createListCustomer(Lcs);
    createListBarang(Lbr);
    
    startMenu(Lcs, Lbr);
    return 0;
}
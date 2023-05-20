#include <iostream>

#include "Customer.h"
#include "Util.h"

using namespace std;

int main() {
    ListCustomer Lcs;
    ListBarang Lbr;

    createListCustomer(Lcs);

    startMenu(Lcs, Lbr);
    return 0;
}

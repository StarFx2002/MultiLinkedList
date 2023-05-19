#include <iostream>

#include "Customer.h"
#include "Util.h"

using namespace std;

int main() {
    ListCustomer Lcs;
    createListCustomer(Lcs);
    
    addressCustomer customer;
    customer = createElemCustomer("Aktsar", "1301200453", 20);
    insertLast(Lcs, customer);

    customer = createElemCustomer("Bruh", "111111111", 69);
    insertLast(Lcs, customer);

    customer = createElemCustomer("Textile", "138531324", 420);
    insertLast(Lcs, customer);

    deleteFirst(Lcs);

    showCustomerList(Lcs);
    return 0;
}
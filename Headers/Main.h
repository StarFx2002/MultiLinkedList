#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include "Customer.h"
#include "Barang.h"
#include "Child.h"
#include "Util.h"

//Customer Functions
void createListCustomer(ListCustomer &Lcs);
addressCustomer createElemCustomer(Customer customer);
void insertLast(ListCustomer &Lcs, addressCustomer adrCustomer);
void showCustomerList(ListCustomer Lcs);
addressCustomer deleteLast(ListCustomer &Lcs);
addressCustomer deleteFirst(ListCustomer &Lcs);
addressCustomer deleteCustomer(ListCustomer &Lcs, addressCustomer adrCustomer);
addressCustomer searchCustomer(ListCustomer Lcs, string nama);

//Child Functions
addressChild createElemChild(addressBarang adrBarang);
void insertChildLast(addressCustomer &parent, addressChild child);
addressChild deleteChildFirst(addressCustomer &parent);
void showChildList(addressCustomer customer);

//Barang Functions
void createListBarang(ListBarang &LBr);
addressBarang createElemBarang(int jumlah, string nama, string brand);
void insertLast(ListBarang &LBr, addressBarang barang);
void showBarangList(ListBarang LBr);
addressBarang deleteFirst(ListBarang &LBr);
addressBarang deleteLast(ListBarang &LBr);
addressBarang deleteBarang(ListBarang &LBr, addressBarang barang);
addressBarang searchBarang(ListBarang &LBr, string nama);

#endif
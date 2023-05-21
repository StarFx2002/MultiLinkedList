#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#define first(L) (L).first
#define last(L) (L).last
#define child(P) (P).child
#define next(P) (P)->next
#define info(P) (P)->info
#define prev(P) (P)->prev

void startMenu(ListCustomer &Lcs, ListBarang &Lbr);
string toLowerCase(string str);

#endif
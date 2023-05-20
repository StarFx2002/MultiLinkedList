#include <iostream>
#include "Customer.h"
#include "Util.h"

void startMenu(ListCustomer &Lcs, ListBarang&Lbr) {
    int i = 0;
    while (i < 1) {
        cout << "Selamat datang di Tubes Struktur Data" << endl;
        cout << endl;

        cout << "Anggota : \tAktsarrizqy Murad Mahraputra - 1301200453" << endl;
        cout << "\t\tFarrel Muhammad Al-Falah - 1301213282" << endl << endl;

        cout << "1. Tambah data customer" << endl;
        cout << "2. Tambah data barang rental" << endl;
        cout << "3. Link data customer - barang" << endl;
        cout << "4. Hapus linked data customer - barang" << endl;
        cout << "5. Hapus data customer" << endl;
        cout << "6. Hapus data barang" << endl;
        cout << "7. Show All List" << endl;
        cout << "8. Show List Customer" << endl;
        cout << "9. Show List Barang" << endl;
        cout << "10. Exit" << endl << endl;

        int j;
        cout << "Input : "; cin >> j;
        cout << "\n=============\n";
        cout << endl;

        if (j <= 6) cout << "Silahkan masukkan input berikut :" << endl;
        
        switch (j)
        {
        case 1:
            {
                Customer customer;
                int n;
                cout << "Jumlah data : "; cin >> n; cout << endl;
                for (int i = 0; i < n; i++) {
                    cout << "Data [" << i + 1 << "]" << endl;
                    cout << "Nama : "; cin.ignore(); getline(cin, customer.nama);
                    cout << "NIK : "; cin >> customer.NIK;
                    cout << "Umur : "; cin >> customer.umur;
                    cout << endl;
                    
                    addressCustomer adrCustomer = createElemCustomer(customer);
                    insertLast(Lcs, adrCustomer);
                    cout << "Data berhasil masuk CSLL Customer" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            {   
                int k = 0;
                while (k < 1) {
                    cout << "1. Delete first data" << endl;
                    cout << "2. Delete last data" << endl;
                    cout << "3. Delete sesuai nama" << endl;
                    cout << endl;

                    int n;
                    cout << "Input : "; cin >> n; cout << endl;
                    switch (n)
                    {
                    case 1:
                        {
                            addressCustomer temp = deleteFirst(Lcs);
                            if (temp != NULL) {
                                cout << "Data pertama berhasil dihapus dari CSLL Customer" << endl;
                                cout << "\n=============\n";
                                cout << endl;
                            }
                            k++;
                            break;
                        }
                    case 2:
                        {
                            addressCustomer temp = deleteLast(Lcs);
                            if (temp != NULL) {
                                cout << "Data terakhir berhasil dihapus dari CSLL Customer" << endl;
                                cout << "\n=============\n";
                                cout << endl;
                            }
                            k++;
                            break;
                        }
                    case 3:
                        {   
                            string nama;
                            cout << "Nama Customer yang ingin dihapus : "; cin.ignore();
                            getline(cin, nama);
                            addressCustomer adrCustomer = searchCustomer(Lcs, nama);
                            if (adrCustomer != NULL) {
                                addressCustomer temp = deleteCustomer(Lcs, adrCustomer);
                                cout << "Customer " << info(temp).nama <<" berhasil dihapus dari CSLL Customer" << endl;
                                cout << "\n=============\n";
                                cout << endl;
                            } else {
                                cout << "Nama tidak ditemukan" << endl;
                                cout << "\n=============\n";
                                cout << endl;
                            }
                            k++;
                            break;
                        }
                    default:
                        cout << "Input tidak dikenal" << endl << endl;
                        cout << "\n=============\n";
                        cout << endl;
                        break;
                    }
                }
                break;
            }
        case 6:
            break;
        case 8:
            showCustomerList(Lcs);
            break;
        case 10:
            i++;
            break;
        default:
            cout << "Input tidak dikenal" << endl << endl;
            cout << "\n=============\n";
            cout << endl;
            break;
        }
    }
}

void toLowerCase(string &str) {
    for (int i = 0; i < str.length(); i++) {

    // convert str[i] to lowercase
    str[i] = tolower(str[i]);
  }
}
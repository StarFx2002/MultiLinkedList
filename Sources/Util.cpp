#include <iostream>
#include "Main.h"

//Memulai tampilan menu di console application. Disini anda bisa menambah data,
//menghapus data, mencari data dll.
void startMenu(ListCustomer &Lcs, ListBarang&Lbr) {
    cout << "Selamat datang di Tubes Struktur Data" << endl;
    cout << endl;

    cout << "Anggota : \tAktsarrizqy Murad Mahraputra - 1301200453" << endl;
    cout << "\t\tFarrel Muhammad Al-Falah - 1301213282" << endl << endl;

    int i = 0;
    while (i < 1) {
        cout << "1. Tambah data customer" << endl;
        cout << "2. Tambah data barang rental" << endl;
        cout << "3. Link data rental customer" << endl;
        cout << endl;
        cout << "4. Hapus linked data rental customer" << endl;
        cout << "5. Hapus data customer" << endl;
        cout << "6. Hapus data barang" << endl;
        cout << endl;
        cout << "7. Show all list" << endl;
        cout << "8. Show list customer" << endl;
        cout << "9. Show list rental customer" << endl;
        cout << "10. Show list barang" << endl;
        cout << endl;
        cout << "11. Search customer" << endl;
        cout << "12. Search barang" << endl;
        cout << "13. Search rental" << endl;
        cout << endl;
        cout << "0. Exit" << endl << endl;

        int j;
        cout << "Input : "; cin >> j;
        cout << "\n=============\n";
        cout << endl;

        if (j > 0 && j <= 6) cout << "Silahkan masukkan input berikut :" << endl;
        
        switch (j)
        {
        case 1:
            {
                cout << "1. Insert First" << endl;
                cout << "2. Insert Last" << endl;
                cout << endl;

                int nCustomer, n;
                cout << "Input : "; cin >> n; cout << endl;

                if (n > 2 || n < 1) {
                    cout << "Input tidak dikenal" << endl << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }

                Customer customer;
                cout << "Jumlah data customer : "; cin >> nCustomer; cout << endl;
                for (int i = 0; i < nCustomer; i++) {
                    cout << "Data [" << i + 1 << "]" << endl;
                    cout << "Nama : "; cin.ignore(); getline(cin, customer.nama);
                    cout << "NIK : "; cin >> customer.NIK;
                    cout << "Umur : "; cin >> customer.umur;
                    cout << endl;
                    
                    addressCustomer adrCustomer = createElemCustomer(customer);
                    if (n == 1) {
                        insertFirst(Lcs, adrCustomer);
                    } else {
                        insertLast(Lcs, adrCustomer);
                    }
                    cout << "Data berhasil masuk CSLL Customer" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 2:
            {   
                cout << "1. Insert First" << endl;
                cout << "2. Insert Last" << endl;
                cout << endl;

                int nBarang, n;
                cout << "Input : "; cin >> n; cout << endl;

                if (n > 2 || n < 1) {
                    cout << "Input tidak dikenal" << endl << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }

                BarangRental barang;
                cout << "Jumlah data barang : "; cin >> nBarang; cout << endl;
                for (int i = 0; i < nBarang; i++) {
                    cout << "Data [" << i + 1 << "]" << endl;
                    cout << "Nama : "; cin.ignore(); getline(cin, barang.nama);
                    cout << "Brand : "; getline(cin, barang.brand);
                    cout << "Jumlah : "; cin >> barang.jumlah;
                    cout << endl;
                    
                    addressBarang adrBarang = createElemBarang(barang.jumlah, barang.nama, barang.brand);
                    if (n == 1) {
                        insertFirst(Lbr, adrBarang);
                    } else {
                        insertLast(Lbr, adrBarang);
                    }
                    cout << "Data berhasil masuk DLL Barang" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 3:
            {
                string namaCustomer, namaBarang; int nBarang;
                cout << "Nama customer : "; cin.ignore(); getline(cin, namaCustomer);
                addressCustomer adrCustomer = searchCustomer(Lcs, namaCustomer);
                if (adrCustomer != NULL) {
                    cout << "Nama barang yang dirental : "; getline(cin, namaBarang);
                    addressBarang adrBarang = searchBarang(Lbr, namaBarang);
                    if (adrBarang != NULL) {
                        cout << "Jumlah yang dirental : "; cin >> nBarang;
                        if (nBarang <= info(adrBarang).jumlah) {
                            info(adrBarang).jumlah -= nBarang;
                            addressChild adrChild = createElemChild(adrBarang);
                            adrChild->nBarang = nBarang;
                            insertChildLast(adrCustomer, adrChild);
                            cout << "\nData berhasil masuk SLL rental (child)" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        } else {
                            cout << "\nJumlah barang tidak cukup untuk dirental" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        }
                    } else {
                        cout << "\nBarang tidak ditemukan" << endl;
                        cout << "\n=============\n";
                        cout << endl;
                    }
                } else {
                    cout << "\nCustomer tidak ditemukan" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 4:
            {
                string nama;
                cout << "Nama customer : "; cin.ignore(); getline(cin, nama);
                cout << endl;

                addressCustomer adrCustomer = searchCustomer(Lcs, nama);
                if (adrCustomer == NULL) {
                    cout << "Customer tidak ditemukan" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }

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
                        addressChild temp = deleteChildFirst(adrCustomer);
                        if (temp != NULL) {
                            info(info(temp)).jumlah += temp->nBarang;
                            cout << "Data pertama berhasil dihapus dari customer " << info(adrCustomer).nama << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            delete temp;
                        }
                        break;
                    }
                case 2:
                    {
                        addressChild temp = deleteChildLast(adrCustomer);
                        if (temp != NULL) {
                            info(info(temp)).jumlah += temp->nBarang;
                            cout << "Data terakhir berhasil dihapus dari customer " << info(adrCustomer).nama << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            delete temp;
                        }
                        break;
                    }
                case 3:
                    {   
                        string nama;
                        cout << "Nama barang yang ingin dihapus dari customer :\n"; cin.ignore();
                        getline(cin, nama); cout << endl;
                        addressChild adrChild = searchChild(adrCustomer, nama);
                        if (adrChild != NULL) {
                            addressChild temp = deleteChild(adrCustomer, adrChild);
                            info(info(temp)).jumlah += temp->nBarang;
                            cout << "Barang " << info(info(temp)).nama <<" berhasil dihapus dari customer " << info(adrCustomer).nama << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            delete temp;
                        } else {
                            cout << "Barang tidak ditemukan" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        }
                        break;
                    }
                default:
                    cout << "Input tidak dikenal" << endl << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }
                break;
            }
        case 5:
            {   
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
                            returnBarang(temp);
                            cout << "Data pertama berhasil dihapus dari CSLL Customer" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            delete temp;
                        }
                        break;
                    }
                case 2:
                    {
                        addressCustomer temp = deleteLast(Lcs);
                        if (temp != NULL) {
                            returnBarang(temp);
                            cout << "Data terakhir berhasil dihapus dari CSLL Customer" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            delete temp;
                        }
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
                            returnBarang(temp);
                            cout << "Customer " << info(temp).nama <<" berhasil dihapus dari CSLL Customer" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            delete temp;
                        } else {
                            cout << "Customer tidak ditemukan" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        }
                        break;
                    }
                default:
                    cout << "Input tidak dikenal" << endl << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }
                break;
            }
        case 6:
            {   
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
                        addressBarang temp = deleteFirst(Lbr);
                        if (temp != NULL) {
                            cout << "Data pertama berhasil dihapus dari DLL Barang" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                            
                            addressCustomer p = first(Lcs);
                            do {
                                addressChild ch = searchChild(p, info(temp).nama);
                                if (ch != NULL) {
                                    deleteChild(p, ch);
                                }
                                p = next(p);
                            } while(p != first(Lcs));
                            delete temp;
                        }
                        break;
                    }
                case 2:
                    {
                        addressBarang temp = deleteLast(Lbr);
                        if (temp != NULL) {
                            cout << "Data terakhir berhasil dihapus dari DLL Barang" << endl;
                            cout << "\n=============\n";
                            cout << endl;

                            addressCustomer p = first(Lcs);
                            do {
                                addressChild ch = searchChild(p, info(temp).nama);
                                if (ch != NULL) {
                                    deleteChild(p, ch);
                                }
                                p = next(p);
                            } while(p != first(Lcs));
                            delete temp;
                        }
                        break;
                    }
                case 3:
                    {   
                        string nama;
                        cout << "Nama Barang yang ingin dihapus : "; cin.ignore();
                        getline(cin, nama);
                        addressBarang adrBarang = searchBarang(Lbr, nama);
                        if (adrBarang != NULL) {
                            addressBarang temp = deleteBarang(Lbr, adrBarang);
                            cout << "Barang " << info(temp).nama <<" berhasil dihapus dari DLL Barang" << endl;
                            cout << "\n=============\n";
                            cout << endl;

                            addressCustomer p = first(Lcs);
                            do {
                                addressChild ch = searchChild(p, info(temp).nama);
                                if (ch != NULL) {
                                    deleteChild(p, ch);
                                }
                                p = next(p);
                            } while(p != first(Lcs));
                            delete temp;
                        } else {
                            cout << "Barang tidak ditemukan" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        }
                        break;
                    }
                default:
                    cout << "Input tidak dikenal" << endl << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }
                break;
            }
        case 7:
            showCustomerList(Lcs);
            showBarangList(Lbr);
            break;
        case 8:
            showCustomerList(Lcs);
            break;
        case 9:
            {   
                if (first(Lcs) == NULL) {
                    cout << "List Customer Kosong!" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }

                cout << "1. Show All Customer Rental" << endl;
                cout << "2. Show Rental Spesifik All Customer" << endl;
                cout << "3. Show Rental Customer Spesifik" << endl;
                cout << endl;

                int n;
                cout << "Input : "; cin >> n; cout << endl;
                switch (n)
                {
                case 1:
                    {
                        if (first(Lcs) != NULL) {
                        cout << "Data Customer : \n" << endl;
                        addressCustomer p = first(Lcs); int i = 1;
                        do {
                            cout << "Data Customer [" << i << "]" << endl;
                            cout << "Nama : " << info(p).nama << endl << endl;
                            addressChild pCh = child(info(p)); int i = 1;
                            if (pCh != NULL) {
                                while (pCh != NULL) {
                                    cout << "\tRental " << info(p).nama << "[" << i << "]" << endl;
                                    cout << "\tNama : " << info(info(pCh)).nama << endl;
                                    cout << "\tBrand : " << info(info(pCh)).brand << endl;
                                    cout << "\tJumlah : " << pCh->nBarang << endl;
                                    cout << endl;
                                    pCh = next(pCh);
                                    i++;
                                } 
                            } else {
                                cout << "\t" << info(p).nama << " tidak ada merental" << endl;
                            }
                            cout << endl;
                            p = next(p);
                            i++;
                        } while (p != first(Lcs));
                        cout << "\n=============\n";
                        cout << endl;
                        } else {
                            cout << "List Customer Kosong!" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        }
                        break;
                    }
                case 2:
                    {
                        string nama;
                        cout << "Nama barang yang ingin dicari di semua customer :\n"; 
                        cin.ignore(); getline(cin, nama);
                        cout << "\n=============\n";
                        cout << endl;

                        addressCustomer p = first(Lcs); int i = 1;
                        do {
                            cout << "Data Customer [" << i << "]" << endl;
                            cout << "Nama : " << info(p).nama << endl << endl;
                            addressChild temp = searchChild(p, nama);
                            if (temp != NULL) {
                                cout << info(p).nama << " merental : " << temp->nBarang << " " << info(info(temp)).nama << " - " <<  info(info(temp)).brand << endl;
                            } else {
                                cout << info(p).nama <<" tidak rental " << nama << endl;
                            }
                            cout << endl;
                            p = next(p);
                            i++;
                        } while (p != first(Lcs));
                        cout << "\n=============\n";
                        cout << endl;
                        break;
                    }
                case 3:
                    {
                        string nama;
                        cout << "Nama customer : "; cin.ignore(); getline(cin, nama);
                        cout << "\n=============\n";
                        cout << endl;

                        addressCustomer adrCustomer = searchCustomer(Lcs, nama);
                        if (adrCustomer != NULL) {
                            showChildList(adrCustomer);
                        } else {
                            cout << "Customer tidak ditemukan" << endl;
                            cout << "\n=============\n";
                            cout << endl;
                        }
                        break;
                    }
                default:
                    cout << "Input tidak dikenal" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                    break;
                }
                break;
            }
        case 10:
            showBarangList(Lbr);
            break;
        case 11:
            {
                string nama;
                cout << "Nama Customer : "; cin.ignore(); getline(cin, nama);
                addressCustomer adrCustomer = searchCustomer(Lcs, nama);
                cout << endl;
                if (adrCustomer != NULL) {
                    cout << "Data [" << i << "]" << endl;
                    cout << "Nama : " << info(adrCustomer).nama << endl;
                    cout << "NIK : " << info(adrCustomer).NIK << endl;
                    cout << "Umur : " << info(adrCustomer).umur << endl;
                    cout << "Rental : [" << info(adrCustomer).nChild << "]" << endl; 
                    cout << endl;
                    cout << "\n=============\n";
                    cout << endl;
                } else {
                    cout << "Customer tidak ditemukan" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 12:
            {
                string nama;
                cout << "Nama Barang : "; cin.ignore(); getline(cin, nama);
                addressBarang adrBarang = searchBarang(Lbr, nama);
                cout << endl;
                if (adrBarang != NULL) {
                    cout << "Data [" << i << "]" << endl;
                    cout << "Nama : " << info(adrBarang).nama << endl;
                    cout << "Brand : " << info(adrBarang).brand << endl;
                    cout << "Jumlah : " << info(adrBarang).jumlah << endl;
                    cout << endl;
                    cout << "\n=============\n";
                    cout << endl;
                } else {
                    cout << "Barang tidak ditemukan" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 13:
            {
                string nama;
                cout << "Nama Customer : "; cin.ignore(); getline(cin, nama);
                addressCustomer adrCustomer = searchCustomer(Lcs, nama);
                if (adrCustomer != NULL) {
                    string namaRental;
                    cout << "Nama Rental : "; getline(cin, namaRental);
                    addressChild adrChild = searchChild(adrCustomer, namaRental);
                    if (adrChild != NULL) {
                        cout << endl;
                        cout << "Data Barang Rental " << info(adrCustomer).nama << " : " << endl << endl;
                        cout << "Nama : " << info(info(adrChild)).nama << endl;
                        cout << "Brand : " << info(info(adrChild)).brand << endl;
                        cout << "Jumlah : " << adrChild->nBarang << endl;
                        cout << endl;
                        cout << "\n=============\n";
                        cout << endl;
                    } else {
                        cout << endl;
                        cout << "Rental tidak ditemukan" << endl;
                        cout << "\n=============\n";
                        cout << endl;
                    }
                } else {
                    cout << endl;
                    cout << "Customer tidak ditemukan" << endl;
                    cout << "\n=============\n";
                    cout << endl;
                }
                break;
            }
        case 0:
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

//Mengkonversi string menjadi semuanya lower case
//Kita loop setiap char di string dan ubah dengan fungsi bawaan c++
string toLowerCase(string str) {
    string temp;
    for (int i = 0; i < str.length(); i++) {
        temp += tolower(str[i]);
    }
    return temp;
}
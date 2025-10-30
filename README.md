# <h1 align="center">Laporan Praktikum Modul  SINGLY LINKED LIST 2 (5) </h1>
<p align="center">Mario Sebastia Barus</p>

## Dasar Teori

Program ini menggunakan konsep Singly Linked List dalam bahasa C++ untuk mengelola data secara dinamis dengan bantuan pointer. Melalui beberapa fungsi seperti insert, delete, update, dan search, program dapat menambah, menghapus, dan mencari data tanpa batasan ukuran seperti pada array. File listBuah.cpp dan mainListBuah.cpp digunakan untuk mengolah dan menguji data buah, sedangkan Singlylist.cpp dan Singlylist.h berisi versi sederhana dengan data bertipe integer. Secara keseluruhan, program ini menunjukkan cara kerja memori dinamis yang efisien dan fleksibel menggunakan struktur linked list (Anggraini et al., 2024; Mbejo et al., 2025; Wijaya et al., 2018).

## Guided 

### [listbuah.cpp]

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node di dalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

// ----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// ----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----

// prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->isidata.nama == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

// prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

// prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if (harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama
                     << ", Jumlah : " << nodeBantu->isidata.jumlah
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (!found) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```


Kode diatas digunakan untuk membuat dan mengelola daftar buah Linked List satu arah di mana pengguna bisa menambah, menghapus, mengubah, menampilkan, dan mencari data buah secara dinamis di memori

### [listbuah.h]

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5(part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5(part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir);

#endif
```

Kode ini berfungsi untuk mendefinisikan struktur data serta kumpulan fungsi yang digunakan dalam mengelola data buah dengan konsep singly linked list.

### [main.cpp]

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData (List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```


Kode ini merupakan program utama main.cpp yang berfungsi untuk menguji dan menjalankan seluruh fungsi yang telah dibuat di file listBuah.h dan listBuah.cpp.

## Unguided 

### 1. [singlylish.cpp]

```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;
    return baru;
}

void hapusNode(Node* &p) {
    delete p;
    p = nullptr;
}

void tambahDepan(List &L, Node* p) {
    p->next = L.first;
    L.first = p;
}

void tampil(List L) {
    Node* bantu = L.first;
    if (bantu == nullptr) {
        cout << "List masih kosong." << endl;
    } else {
        cout << "Isi list: ";
        while (bantu != nullptr) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

Node* cariNode(List L, int nilai) {
    Node* bantu = L.first;
    while (bantu != nullptr) {
        if (bantu->data == nilai) {
            return bantu;
        }
        bantu = bantu->next;
    }
    return nullptr;
}

int totalData(List L) {
    Node* bantu = L.first;
    int total = 0;
    while (bantu != nullptr) {
        total += bantu->data;
        bantu = bantu->next;
    }
    return total;
}
```

Kode diatas digunakan untuk mengatur dan memanipulasi data menggunakan struktur Singly Linked List, meliputi operasi penambahan, penampilan, pencarian, perhitungan, serta penghapusan data.

#### Full code Screenshot:
<img width="611" height="911" alt="image" src="https://github.com/user-attachments/assets/de719e96-70b8-4d3b-bd68-00ca2f72b959" />
<img width="786" height="492" alt="image" src="https://github.com/user-attachments/assets/c8c18731-8d51-4e2c-bf4e-6c230bcec6f0" />


### [singlylist.h]

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* buatNode(int nilai);
void hapusNode(Node* &p);
void tambahDepan(List &L, Node* p);
void tampil(List L);
Node* cariNode(List L, int nilai);
int totalData(List L);

#endif
```

Kode ini berfungsi untuk menetapkan struktur data serta fungsi utama yang digunakan dalam mengelola data dengan konsep singly linked list

#### Full code Screenshot:
<img width="559" height="600" alt="image" src="https://github.com/user-attachments/assets/39fa1e92-f596-4667-b92f-6525d1f0d781" />


### [main.cpp]

```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    tambahDepan(L, buatNode(2));
    tambahDepan(L, buatNode(0));
    tambahDepan(L, buatNode(8));
    tambahDepan(L, buatNode(12));
    tambahDepan(L, buatNode(9));

    tampil(L);

    Node* ketemu = cariNode(L, 8);
    if (ketemu != nullptr)
        cout << "Data 8 ditemukan di alamat: " << ketemu << endl;
    else
        cout << "Data 8 tidak ditemukan." << endl;

    cout << "Total semua data: " << totalData(L) << endl;

    return 0;
}
```

#### Output:
<img width="1017" height="240" alt="image" src="https://github.com/user-attachments/assets/efaba401-f260-42d2-b64d-b3bcd16d5e56" />

Kode diatas adalah program utama main.cpp yang berfungsi untuk menguji dan menjalankan semua fungsi dari file Singlylist.h dan Singlylist.cpp. Program ini digunakan untuk membuat dan mengelola list, termasuk menambahkan data, menampilkan isi list, mencari nilai tertentu, serta menghitung total data dalam struktur Singly Linked List.

#### Full code Screenshot:
<img width="752" height="596" alt="image" src="https://github.com/user-attachments/assets/d8a39727-3461-4fc4-8343-9f93df62e846" />

## Kesimpulan
Dari hasil implementasi yang dilakukan, bisa disimpulkan bahwa penggunaan Singly Linked List pada bahasa C++ membuat pengelolaan data menjadi lebih mudah, fleksibel, dan efisien dibandingkan dengan array yang ukurannya tetap. Dengan berbagai fungsi yang ada, program dapat menambah, menghapus, mengubah, serta mencari data langsung di memori tanpa batasan jumlah elemen. File listBuah.cpp dan mainListBuah.cpp berfungsi untuk mengelola data buah secara dinamis, sedangkan Singlylist.cpp dan Singlylist.h merupakan versi sederhana yang menggunakan data berupa angka. Secara keseluruhan, program ini menunjukkan bagaimana konsep struktur data dinamis dan penggunaan pointer dapat membantu dalam pengelolaan memori secara efektif di pemrograman C++.

## Referensi
[1] Anggraini, Y. N., Zulfi, M. F., Butarbutar, L. E., & Rajagukguk, G. (2024). 
[2] Mbejo, M. T., Nopa, L. A., Saftina Putri, J., & Risky, M. (2025).
[3] Wijaya, H., Wardhono, W. S., & Arwani, I. (2018). 

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

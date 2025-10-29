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

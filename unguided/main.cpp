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

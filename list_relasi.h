#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct infotype_relasi{
    int harga;
    int jumlah_pesanan;

};
typedef struct elmlist_child *address_child;
typedef struct elmlist_parent *address_parent;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
    infotype_relasi info;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createListR(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi P);
void deleteLast(List_relasi &L, address_relasi P);
void deleteAfter(List_relasi &L ,address_relasi Prec, address_relasi P);
void deleteRelasi(List_relasi &L, address_relasi P);

/** PERLU MODIFIKASI */
address_relasi alokasi( address_parent P, address_child C, infotype_relasi x);
void dealokasi(address_relasi &P);
address_relasi findElmR(List_relasi L, address_parent P, address_child C);
void printInfo(List_relasi L);


#endif // LIST_RELASI_H_INCLUDED

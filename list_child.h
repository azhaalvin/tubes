#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED


#include <iostream>
#include "list_parent.h"
#include "list_relasi.h"
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info


struct infotype_child{
    string nama_resto;
    int jumlah_pendapatan;
};
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
};

struct List_child{
    address_child first;
    address_child last;
};

/** TIDAK PERLU MODIFIKASI */
void createListC(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(List_child &L , address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child P);
void deleteLast(List_child &L, address_child P);
void deleteAfter(List_child &L, address_child Prec, address_child P);
void deleteChild(List_child &L, address_child P);


/** PERLU MODIFIKASI */
address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElmC(List_child L, infotype_child x);
void printInfo(List_child L);


#endif // LIST_CHILD_H_INCLUDED

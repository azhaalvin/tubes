#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child
#define parent(P) P->parent

struct infotype_parent{
    string nama_makanan;
};
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
    address_parent prev;
};

struct List_parent {
    address_parent first;
    address_parent last;
};


/** TIDAK PERLU MODIFIKASI */
void createListP(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent P);
void deleteParent(List_parent &L, address_parent P);


/** PERLU MODIFIKASI */
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElmP(List_parent L, infotype_parent x);
void printInfo(List_parent L);


#endif // LIST_PARENT_H_INCLUDED

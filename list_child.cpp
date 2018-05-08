#include "list_child.h"

void createListC(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(List_child &L ,address_child &Prec, address_child P) {
    if ( Prec == NULL ){
        cout<<" prec tidak ada "<<endl;
    }
    else{
        if ( Prec == first(L)){
            insertFirst(L,P);
        }
        else if ( Prec == last(L)){
            next(Prec) = P;
            last(L) = P;
        }
        else
            next(P) = next(Prec);
            next(Prec)= P;
    }
}

void insertLast(List_child &L , address_child P){
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List_child &L, address_child P){
    P=first(L);
    first(L)=next(P);
    next(P)=NULL;
}

void deleteAfter(List_child &L,address_child Prec, address_child P){
    P=next(Prec);
    next(Prec)=next(P);
    next(P)=NULL;
}

void deleteLast(List_child &L,address_child P){
    P=first(L);
    while ( next(P) != last(L)){
        P=next(P);
    }
    last(L)=P;
    next(P)=NULL;
}

void deleteChild(List_child &L,address_child P){
    if ( first(L) == NULL ){
        cout<<"data tidak ada"<<endl;
    }else{
        if(P == NULL){
            cout<<"data not found \n";
        }else if( first(L) == P){
                deleteFirst(L,P);
        }else if(next(P)==NULL){
                deleteLast(L,P);
        }else{
            address_child prec=first(L);
            while(next(prec)!=NULL && next(prec)!=P){
                prec=next(prec);
            }
            deleteAfter(L,prec,P);
            }
        }
    }



void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
       cout << " -> "<< info(P).nama_resto<<" JUMLAH PENDAPATAN : "<<info(P).jumlah_pendapatan<<endl;
        P = next(P);
    }
}


address_child findElmC(List_child L, infotype_child x) {
    address_child P = first(L);
    address_child Q;
    bool found=false;
    if(first(L) != NULL){
        if(info(P).nama_resto == x.nama_resto){
            found = true;
            Q = P;
        }while(P != NULL && found == false){
            if(info(P).nama_resto == x.nama_resto){
                found = true;
                Q = P;
            }
            P = next(P);
        }
        if(found == true){
            return Q;
        }else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
    /*while(P != NULL) {
        if(info(P).nama_resto==x.nama_resto) {
            return P;
        }
        P = next(P);
    } */
   // return NULL;
}


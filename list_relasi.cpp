#include "list_relasi.h"

void createListR(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_parent P, address_child C, infotype_relasi x) {
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    info(Q) = x;
    next(Q) = NULL;
    return Q;
}

void dealokasi(address_relasi &P){
    delete P;
    P = NULL;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if ( first(L) == NULL ){
        P=first(L);
        next(P)=first(L);
    }
    else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(List_relasi &L ,address_relasi &Prec, address_relasi P) {
    if ( Prec == NULL ){
        cout<<" prec tidak ada "<<endl;
    }
    else{
        if ( Prec == first(L)){
            insertFirst(L,P);
        }
        else if ( next(Prec) == first(L)){
            insertLast(L,P);
        }
        else{
            next(P) = next(Prec);
            next(Prec)= P;
        }
    }
}
void insertLast(List_relasi &L , address_relasi P){
    if(first(L) == NULL) {
        first(L)=P;
        next(P)=first(L);
    } else {
        address_relasi Q = first(L);
        while( next(Q) != first(L)) {
          Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);

    }
}

void deleteFirst(List_relasi &L, address_relasi P){
    P=first(L);
    address_relasi Q = first(L);
    while ( (next(Q)) != first(L)){
        Q=next(Q);
    }
    first(L) = next(P);
    next(Q) = first(L);
    next(P) = NULL;
    dealokasi(P);
}
void deleteAfter(List_relasi &L,address_relasi Prec, address_relasi P){
    P=next(Prec);
    next(Prec)=next(P);
    next(P)=NULL;
    dealokasi(P);
}

void deleteLast(List_relasi &L,address_relasi P){
    address_relasi Q = first(L);
    while ( next(next(Q)) != first(L)){
        Q=next(Q);
    }
    P=next(Q);
    next(Q) = first(L);
    next(P) = NULL;
    dealokasi(P);
}

void deleteRelasi(List_relasi &L,address_relasi P){
    if ( first(L) == NULL ){
        cout<<"data tidak ada"<<endl;
    }
    else{
        if(P == NULL){
            cout<<"data not found \n";
        }
        else{
            if( P==first(L) && next(P)==first(L)){
                first(L)=NULL;
                cout<<"KALO DATA CUMA 1 !";
                dealokasi(P);
            }
            else if(P==first(L) && next(P)!=first(L)){
                deleteFirst(L,P);
                cout<<"delete first";
            }
            else if(P!=first(L) && next(P)==first(L)){
                deleteLast(L,P);
                cout<<"delete last";
            }
            else{
                address_relasi prec = first(L);
                while(next(prec)!=first(L) && next(prec)!=P){
                    prec=next(prec);
                }
                deleteAfter(L,prec,P);
                cout<<"delete after";
                }
        }
    }
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(next(P) !=first(L)) {
        cout<<"Nama Makanan : "<<info(parent(P)).nama_makanan<<" ----------> Harga : "<<info(P).harga<<"---- > di restoran "<<info(child(P)).nama_resto<<endl;
        P = next(P);
        }
    cout<<" Nama Makanan : "<<info(parent(P)).nama_makanan<<" ----------> Harga : "<<info(P).harga<<"---- > di restoran "<<info(child(P)).nama_resto<<endl;
}


address_relasi findElmR(List_relasi L, address_parent P, address_child C) {
    address_relasi R1 = first(L);
    address_relasi R;
    bool found=false;
    if(first(L) != NULL){
        while(next(R1) != first(L) && found == false){
            if(parent(R1)==P && child(R1)== C){
                found = true;
                R = R1;
            }
            R1 = next(R1);
        }
        if(next(R1) == first(L)){
               if(parent(R1)==P && child(R1)== C){
                found = true;
                R = R1;
                return R;
            }
        else if (found == true){
            return R;
        }

        }else{
            return NULL;
        }
    }
    else{
        return NULL;
    }

    }
    /*address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
    */


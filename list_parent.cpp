#include "list_parent.h"

void createListP(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void dealokasi(address_parent &P){
    delete P;
    P = NULL;
}
void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLast(List_parent &L , address_parent P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(List_parent &L ,address_parent &Prec, address_parent P) {
    if ( Prec == NULL ){
        cout<<" prec tidak ada "<<endl;
    }
    else{
        if ( Prec == first(L)){
            insertFirst(L,P);
        }
        else if ( Prec == last(L)){
            next(Prec) = P;
            prev(P) = Prec;
            last(L) = P;
        }
        else
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec))=P;
            next(Prec)= P;
    }
}

void deleteFirst(List_parent &L, address_parent &P){
    P=first(L);
    first(L)=next(first(L));
    next(P)=NULL;
    prev(first(L)) = NULL;

}

void deleteAfter(List_parent &L,address_parent Prec, address_parent P){
    P=next(Prec);
    next(Prec)=next(P);
    prev(next(P))=Prec;
    next(P)=NULL;
    prev(P)=NULL;
    dealokasi(P);
}

void deleteLast(List_parent &L,address_parent &P){
    P=last(L);
    last(L)=prev(last(L));
    prev(P)=NULL;
    next(last(L))=NULL;

}

void deleteParent(List_parent &L,address_parent P){
    if ( first(L) == NULL ){
        cout<<"data tidak ada"<<endl;
    }
    else{
        if(P == NULL){
            cout<<"data not found \n";
        }
        else{
                if( P==first(L) && P==last(L)){
                    first(L) = NULL;
                    last(L) = NULL;
                    dealokasi(P);
                    cout<<"DELETE KALO DATA 1 \n";
                }
                else if(P==first(L) && next(P)!=last(L)){
                    deleteFirst(L,P);
                    dealokasi(P);
                    cout<<"DELETE FIRST \n";
                }
                else if(P != first(L) && P==last(L)){
                    deleteLast(L,P);
                    dealokasi(P);
                    cout<<"DELETE LAST \n";
                }
                else{
                    address_parent prec=first(L);
                    while(next(prec)!=NULL && next(prec)!=P){
                        prec=next(prec);
                    }
                   deleteAfter(L,prec,P);
                    cout<<"DELETE AFTER \n";
                }
            }
        }
    }


void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        while ( P != NULL){
            cout<<info(P).nama_makanan<<endl;
            P = next(P);
        }
    }
}

address_parent findElmP(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    address_parent Q;
    bool found=false;
    if(first(L) != NULL){
        if(info(P).nama_makanan == x.nama_makanan){
            found = true;
            Q = P;
        }
        while(P != NULL && found == false){
            if(info(P).nama_makanan == x.nama_makanan){
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
    }else{
        return NULL;
    }
    /*if (first(L)!= NULL){
    address_parent P = first(L);
    while (next(P) != NULL){
        if((info(P).nama_makanan )==( x.nama_makanan)) {
            return P;
        }
        P = next(P);
    }
    if((info(P).nama_makanan )==( x.nama_makanan)){
        return P;
    } else {
    return NULL;
    }
    */
}


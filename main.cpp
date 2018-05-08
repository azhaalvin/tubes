#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"
#include "sub_main.h"


int main()
{
    string jawab;
    List_child LC;
    List_parent LP;
    List_relasi LR;
    createListC(LC);
    createListP(LP);
    createListR(LR);
    master(LC,LP,LR);
}



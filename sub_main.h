#ifndef SUB_MAIN_H_INCLUDED
#define SUB_MAIN_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

void master(List_child &LC,List_parent &LP,List_relasi &LR);
void admin(List_child &LC,List_parent &LP,List_relasi &LR);
void pelanggan(List_child &LC,List_parent &LP,List_relasi &LR);
void a_tambahR(List_child &LC);//di dalam void admin
void a_tambahM(List_child LC,List_parent &LP,List_relasi &LR);//di dalam void admin
void a_hapusM(List_child &LC,List_parent &LP,List_relasi &LR);//di dalam void admin
void a_hapusR(List_child &LC,List_parent LP,List_relasi &LR);//di dalam void admin
void lihat_resto(List_child &LC);
void lihat_MhargaResto(List_child &LC,List_parent &LP,List_relasi &LR);
void p_cariM(List_parent LP,List_child LC,List_relasi LR);
void p_pesan(List_child &LC,List_parent &LP,List_relasi &LR);//di dalam void pelanggan
void daftar_menu(List_child &LC,List_parent &LP,List_relasi &LR);//di dalam void pelanggan untuk show menu
//void exit();


#endif // SUB_MAIN_H_INCLUDED

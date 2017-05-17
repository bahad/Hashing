

#include <iostream>
#include "Liste.h"

Liste::Liste() {
    this->bas = nullptr;
    this->son = nullptr;
}

void Liste::Ekle(Kayit yeniKayit) {

    Kayit *yeni = new Kayit(yeniKayit);

    if (this->bas == nullptr) {
        this->bas = this->son = yeni;
    } else {
        son->sonraki = yeni;
        son = yeni;
    }
}

Kayit Liste::Ara(int ogrNo){
    Kayit *tmp = this->bas;

    while(tmp != NULL){
        if(tmp->ogrNo == ogrNo){
            return Kayit(*tmp); //Kayidin kopyasi
        }
        tmp = tmp->sonraki;
    }

    return Kayit(-1, -1, "","", "");
    //Bos kayit
}

/*
void Liste::Yazdir() {
    //
   // list_node *tmp = this->education;
    //while ( tmp != NULL ) {
     //   tmp->print_list();
     //   std::cout << "******\n";
      //  tmp = tmp->next;
    //}


    Kayit *tmp = this->bas;
    while(tmp != nullptr){
        cout << tmp->anahtar
    }
}
*/





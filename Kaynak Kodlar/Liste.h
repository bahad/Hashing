

#ifndef Y_PROLAB1_2_LISTE_H
#define Y_PROLAB1_2_LISTE_H

#include "Kayit.h"

class Liste {
public:
    Kayit *bas;
    Kayit *son;

    Liste();
    void Ekle(Kayit yeniKayit);
    Kayit Ara(int);
};


#endif //Y_PROLAB1_2_LISTE_H

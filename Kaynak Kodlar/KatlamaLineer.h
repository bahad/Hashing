

#ifndef Y_PROLAB1_2_HASHTABLOSU_H
#define Y_PROLAB1_2_HASHTABLOSU_H

#include "Kayit.h"

class KatlamaLineer {

private:
    static const int tabloBoyutu = 500;
    Kayit *kayitlar[tabloBoyutu];
    int olusturmaMaliyeti;
    int kapasite;

    int Katlama(int ogrenciNumarasi);

public:
    KatlamaLineer();


    void Yoklama();
    void Arama(int);
};


#endif //Y_PROLAB1_2_HASHTABLOSU_H

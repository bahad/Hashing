

#ifndef Y_PROLAB1_2_KATLAMAAYRIK_H
#define Y_PROLAB1_2_KATLAMAAYRIK_H


#include "Kayit.h"
#include "Liste.h"

class KatlamaAyrik {
private:
    static const int tabloBoyutu = 500;
    Liste kayitlar[tabloBoyutu];
    int kapasite;
    int olusturmaMaliyeti;
    int Katlama(int ogrenciNumarasi);

public:
    KatlamaAyrik();


    void Yoklama();
    void Arama(int);
};


#endif //Y_PROLAB1_2_KATLAMAAYRIK_H

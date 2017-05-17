
#ifndef Y_PROLAB1_2_KAREORTASIAYRIK_H
#define Y_PROLAB1_2_KAREORTASIAYRIK_H

#include "Kayit.h"
#include "Liste.h"

class KareortasiAyrik {

private:
    static const int tabloBoyutu = 500;
    Liste kayitlar[tabloBoyutu];
    int kapasite;
    int olusturmaMaliyeti;
    int KareOrtasi(int unsigned long long);

public:
    KareortasiAyrik();


    void Yoklama();
    void Arama(int);

};


#endif //Y_PROLAB1_2_KAREORTASİAYRIK_H


#ifndef Y_PROLAB1_2_KAREORTASILINEER_H
#define Y_PROLAB1_2_KAREORTASILINEER_H


#include "Kayit.h"

class KareortasiLineer {
private:
    static const int tabloBoyutu = 500;
    Kayit *kayitlar[tabloBoyutu];
    int kapasite;
    int olusturmaMaliyeti;

    int KareOrtasi(unsigned long long ogrenciNumarasi);

public:
    KareortasiLineer();


    void Yoklama();
    void Arama(int );
};


#endif //Y_PROLAB1_2_KAREORTASILINEER_H



#ifndef Y_PROLAB1_2_BOLENKALANAYRIK_H
#define Y_PROLAB1_2_BOLENKALANAYRIK_H


#include "Kayit.h"
#include "Liste.h"
class BolenkalanAyrik {
private:
    static const int tabloBoyutu = 500;
    Liste kayitlar[tabloBoyutu];
    int kapasite;
    int olusturmaMaliyeti;
    int BolenKalan(int ogrenciNumarasi);

public:
    BolenkalanAyrik();


    void Yoklama();
    void Arama(int);
};


#endif //Y_PROLAB1_2_BOLENKALANAYRIK_H

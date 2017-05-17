

#ifndef Y_PROLAB1_2_BOLENKALANLINEER_H
#define Y_PROLAB1_2_BOLENKALANLINEER_H


#include "Kayit.h"

class BolenkalanLineer {
private:
    static const int tabloBoyutu = 500;
    Kayit *kayitlar[tabloBoyutu];
    int kapasite;
    int olusturmaMaliyeti;
    int BolenKalan(int ogrenciNumarasi);

public:
    BolenkalanLineer();

    void Arama(int);
    void Yoklama();
};


#endif //Y_PROLAB1_2_BOLENKALANLİNEER_H

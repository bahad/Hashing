

#ifndef Y_PROLAB1_2_NORMALTABLO_H
#define Y_PROLAB1_2_NORMALTABLO_H


#include "Kayit.h"

class NormalTablo {
private:
    static const int tabloBoyutu = 500;
    Kayit *kayitlar[tabloBoyutu];
    int olusturmaMaliyeti;
public:
    NormalTablo();
    void Arama(int);
};


#endif //Y_PROLAB1_2_NORMALTABLO_H

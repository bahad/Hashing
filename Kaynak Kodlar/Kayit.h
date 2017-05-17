

#ifndef Y_PROLAB1_2_KAYIT_H
#define Y_PROLAB1_2_KAYIT_H


#include <string>

using namespace std;

class Kayit {
public:

    Kayit(long anahtar, int ogrNo, string isim, string soyisim, const string deger) :
            anahtar(anahtar), ogrNo(ogrNo), deger(deger), isim(isim), soyisim(soyisim) {

        sonraki = nullptr;
    }


    long int anahtar;
    string deger;
    int ogrNo;
    string isim;
    string soyisim;
    Kayit *sonraki;     // Burayi ayrik tasma
};


#endif //Y_PROLAB1_2_KAYİT_H

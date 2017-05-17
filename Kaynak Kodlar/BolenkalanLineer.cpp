

#include <fstream>
#include <sstream>
#include <iostream>
#include "BolenkalanLineer.h"

using namespace std;

BolenkalanLineer::BolenkalanLineer() {
    for (int i = 0; i < tabloBoyutu; i++) {
        this->kayitlar[i] = NULL;       // NULL değilse boş değildir
    }
    this->olusturmaMaliyeti = 0;
    this->kapasite = 0;
}

int BolenkalanLineer::BolenKalan(int ogrenciNumarasi) {

    return ogrenciNumarasi % tabloBoyutu;
}

void BolenkalanLineer::Yoklama() {
    ifstream f("../kisiler.txt");
    olusturmaMaliyeti++;
    int ogrNo;
    olusturmaMaliyeti++;
    string isim;
    olusturmaMaliyeti++;
    string soyisim;
    olusturmaMaliyeti++;

    for (std::string line; std::getline(f, line);) {
        if (kapasite == tabloBoyutu) {
            std::cout << "Tablo kapasitesi doldu, " << kapasite << "'den sonraki kayıtlar eklenemedi" << endl;
            olusturmaMaliyeti++;
            break;
        }

        //internetten
        std::stringstream stream(line);
        olusturmaMaliyeti++;

        while (stream >> ogrNo >> isim >> soyisim) {

            int adres = BolenKalan(ogrNo);  //öğrenci numarasi -> hash
            olusturmaMaliyeti++;

            while (this->kayitlar[adres] != NULL) {
                adres = (adres + 1) % tabloBoyutu;
                olusturmaMaliyeti++;
            }

            string deger = to_string(ogrNo) + " " + isim + " " + soyisim;
            olusturmaMaliyeti++;

            Kayit *tmp = new Kayit(adres, ogrNo, isim, soyisim, deger);
            olusturmaMaliyeti++;
            kayitlar[adres] = tmp;
            olusturmaMaliyeti++;
            kapasite++;
            olusturmaMaliyeti++;
        }
    }

    ofstream cikti("../bolenkalan-lineer.txt");
    olusturmaMaliyeti++;
    for (int i = 0; i < tabloBoyutu; i++) {
        if (this->kayitlar[i] != NULL) {
            olusturmaMaliyeti++;
            cikti << this->kayitlar[i]->anahtar << " => " << this->kayitlar[i]->deger << endl;
        }

    }
    cikti.close();

}


void BolenkalanLineer::Arama(int aranan) {
    int aramaMaliyeti = 0;
    int hash = BolenKalan(aranan);
    aramaMaliyeti++;
    int adres = hash;
    aramaMaliyeti++;
    int sayac = 0;
    aramaMaliyeti++;

    while (this->kayitlar[adres]->ogrNo != aranan) {
        if (sayac >= 500) {
            cout << "Bolen Kalan Lineer Yoklama tablosunda bulunamadi" << endl;
            return;
        }
        adres = (adres + 1) % tabloBoyutu;
        aramaMaliyeti++;
        sayac++;
    }

    cout << "Bolen Kalan Lineer Yoklama tablosunda: " << endl;
    cout << "\t Dosya olusturma maliyeti: " << olusturmaMaliyeti << endl;
    cout << "\t Arama  maliyeti: " << aramaMaliyeti << endl;
    cout << "\t Hash: " << hash << endl;
    cout << "\t Tabloda yeri: " << adres << endl;
    cout << "\t\t " << kayitlar[adres]->deger << endl;
}



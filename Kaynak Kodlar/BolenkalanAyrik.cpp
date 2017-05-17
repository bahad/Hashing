

#include <fstream>
#include <iostream>
#include <sstream>
#include "BolenkalanAyrik.h"

using namespace std;

BolenkalanAyrik::BolenkalanAyrik() {
    for (int i = 0; i < tabloBoyutu; i++) {
        this->kayitlar[i] = Liste();
    }
    this->kapasite = 0;
    this->olusturmaMaliyeti = 0;
}


int BolenkalanAyrik::BolenKalan(int ogrenciNumarasi) {

    return ogrenciNumarasi % tabloBoyutu;
}

void BolenkalanAyrik::Yoklama() {
    ifstream f("../kisiler.txt");
    olusturmaMaliyeti++;
    string isim;
    olusturmaMaliyeti++;
    string soyisim;
    olusturmaMaliyeti++;
    int ogrNo;
    olusturmaMaliyeti++;
    for (std::string line; std::getline(f, line);) {
        //Tablo doldu olayı burda yok
        std::stringstream stream(line);
        olusturmaMaliyeti++;
        while (stream >> ogrNo >> isim >> soyisim) {
            int adres = BolenKalan(ogrNo);
            olusturmaMaliyeti++;

            string deger = to_string(ogrNo) + " " + isim + " " + soyisim;
            olusturmaMaliyeti++;
            Kayit tmp = Kayit(adres, ogrNo, isim, soyisim, deger);
            olusturmaMaliyeti++;
            kayitlar[adres].Ekle(tmp);
            olusturmaMaliyeti++;
            kapasite++;
        }
    }

    ofstream cikti("../bolenkalan-ayrik.txt");
    olusturmaMaliyeti++;
    for (int i = 0; i < tabloBoyutu; i++) {
        Kayit *tmp = kayitlar[i].bas;   //ilk düğümün yeri
        olusturmaMaliyeti++;
        cikti << i << " => ";
        while (tmp != nullptr) {
            cikti << tmp->deger << " | ";
            tmp = tmp->sonraki;     // tmp'i bir sonraki düğüme at, bir sonraki eleman
            olusturmaMaliyeti++;
        }
        cikti << endl;

    }
    cikti.close();
}


void BolenkalanAyrik::Arama(int aranan) {
    int aramaMaliyeti = 0;
    int hash = BolenKalan(aranan);
    aramaMaliyeti++;
    int adres = hash;
    aramaMaliyeti++;
    int sayac = 0;
    aramaMaliyeti++;


    Kayit *tmp = kayitlar[hash].bas;

    while (tmp != NULL) {
        if (tmp->ogrNo == aranan) {

            cout << "Bolen Kalan Ayrik Tasma tablosunda: " << endl;
            cout << "\t Dosya olusturma maliyeti: " << olusturmaMaliyeti << endl;
            cout << "\t Arama  maliyeti: " << aramaMaliyeti << endl;
            cout << "\t Hash: " << hash << endl;
            cout << "\t Tabloda yeri: " << adres << endl;
            cout << "\t\t " << tmp->deger << endl;
            return;
        }
        aramaMaliyeti++;
        tmp = tmp->sonraki;
    }


    cout << "Bolen Kalan Ayrik Tasma tablosunda bulunamadi" << endl;
    return;

}


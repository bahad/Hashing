
#include <fstream>
#include <iostream>
#include <sstream>
#include "KatlamaAyrik.h"

using namespace std;

KatlamaAyrik::KatlamaAyrik() {
    for (int i = 0; i < tabloBoyutu; i++) {
        this->kayitlar[i] = Liste();
    }
    this->olusturmaMaliyeti = 0;
    this->kapasite = 0;
}


int KatlamaAyrik::Katlama(int ogrenciNumarasi) {
    int toplam = 0;
    while (ogrenciNumarasi != 0) {
        toplam = (toplam + ogrenciNumarasi % 100);
        ogrenciNumarasi = ogrenciNumarasi / 100;
    }
    return toplam % tabloBoyutu;
}

void KatlamaAyrik::Yoklama() {
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
            int adres = Katlama(ogrNo);
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

    ofstream cikti("../katlama-ayrik.txt");
    olusturmaMaliyeti++;
    for (int i = 0; i < tabloBoyutu; i++) {
        Kayit *tmp = kayitlar[i].bas;
        olusturmaMaliyeti++;
        cikti << i << " => ";
        while (tmp != nullptr) {
            cikti << tmp->deger << " | ";
            tmp = tmp->sonraki;
            olusturmaMaliyeti++;
        }
        cikti << endl;

    }
    cikti.close();
}
void KatlamaAyrik::Arama(int aranan) {
    int aramaMaliyeti = 0;
    int hash = Katlama(aranan);
    aramaMaliyeti++;
    int adres = hash;
    aramaMaliyeti++;
    int sayac = 0;
    aramaMaliyeti++;

    Kayit *tmp = kayitlar[hash].bas;

    while (tmp != NULL) {
        if (tmp->ogrNo == aranan) {

            cout << "Katlama Ayrik Tasma tablosunda: " << endl;
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


    cout << "Katlama Ayrik Tasma tablosunda bulunamadi" << endl;
    return;
}


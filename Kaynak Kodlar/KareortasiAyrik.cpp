

#include <fstream>
#include <sstream>
#include <iostream>
#include "KareortasiAyrik.h"
KareortasiAyrik::KareortasiAyrik() {
    for (int i = 0; i < tabloBoyutu; i++) {
        this->kayitlar[i] = Liste();
    }
    this->olusturmaMaliyeti = 0;
    this->kapasite = 0;
}

int KareortasiAyrik::KareOrtasi(unsigned long long ogrenciNumarasi) {
    unsigned long long  sq = ogrenciNumarasi * ogrenciNumarasi;
    int sonuc = 0;
    string s = to_string(sq);
    s = s.substr(6, 3);
    sonuc = std::stoi(s);
    return sonuc % tabloBoyutu;
}

void KareortasiAyrik::Yoklama() {
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
            int adres = KareOrtasi(ogrNo);
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

    ofstream cikti("../kareortasi-ayrik.txt");
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

void KareortasiAyrik::Arama(int aranan) {
    int aramaMaliyeti = 0;
    int hash = KareOrtasi(aranan);
    aramaMaliyeti++;
    int adres = hash;
    aramaMaliyeti++;
    int sayac = 0;
    aramaMaliyeti++;


    Kayit *tmp = kayitlar[hash].bas;

    while (tmp != NULL) {
        if (tmp->ogrNo == aranan) {

            cout << "Kare Ortasi Ayrik Tasma tablosunda: " << endl;
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


    cout << "Kare Ortasi Ayrik Tasma tablosunda bulunamadi" << endl;
    return;
}


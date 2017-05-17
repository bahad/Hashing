

#include "KatlamaLineer.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

KatlamaLineer::KatlamaLineer() {
    for (int i = 0; i < tabloBoyutu; i++) {
        this->kayitlar[i] = NULL;
    }
    this->olusturmaMaliyeti = 0;
    this->kapasite = 0;
}

/*
 * İkili parçalara bölmek için 100 ile işlem yapıyoruz.
 * Daha sonra "toplam" değişkeni tablo boyutundan büyük olamayacağı için,
 *  tablo boyutuna göre modunu alıyoruz. (500 => 0, 501 => 1)
 *
 *  Örn: 130461063
 *
 *       1 + 30 + 46 + 10 + 63
 *
 *  toplam => 63  sayi => 1304610
 *  toplam => 73  sayi => 13046
 *  toplam => 119 sayi => 130
 *  toplam => 149 sayi => 1
 *  toplam => 150 sayi => 0

 */
int KatlamaLineer::Katlama(int ogrenciNumarasi) {
    int toplam = 0;
    while (ogrenciNumarasi != 0) {
        int sag = ogrenciNumarasi % 100;
        toplam = toplam + sag;
        ogrenciNumarasi = ogrenciNumarasi / 100;
    }
    return toplam % tabloBoyutu;
}

void KatlamaLineer::Yoklama() {
    ifstream f("../kisiler.txt");
    olusturmaMaliyeti++;
    string isim;
    olusturmaMaliyeti++;
    string soyisim;
    olusturmaMaliyeti++;
    int ogrNo;
    olusturmaMaliyeti++;
    for (std::string line; std::getline(f, line);) {
        if (kapasite == tabloBoyutu) {
            std::cout << "Tablo kapasitesi doldu, " << kapasite << "'den sonraki kayıtlar eklenemedi" << endl;
            olusturmaMaliyeti++;
            break;
        }
        std::stringstream stream(line);
        olusturmaMaliyeti++;
        while (stream >> ogrNo >> isim >> soyisim) {
            int adres = Katlama(ogrNo);
            olusturmaMaliyeti++;

            while (this->kayitlar[adres] != NULL) {
                adres = (adres + 1) % tabloBoyutu;      // Bir sonraki adres tablo boyutunu aşmasın diye modunu alıyoruz.
                olusturmaMaliyeti++;
            }
            string deger = to_string(ogrNo) + " " + isim + " " + soyisim;
            olusturmaMaliyeti++;
            Kayit *tmp = new Kayit(adres, ogrNo, isim, soyisim, deger);
            olusturmaMaliyeti++;
            kayitlar[adres] = tmp;
            olusturmaMaliyeti++;
            kapasite++;
        }
    }

    ofstream cikti("../katlama-lineer.txt");
    olusturmaMaliyeti++;
    for (int i = 0; i < tabloBoyutu; i++) {
        if (this->kayitlar[i] != NULL) {
            olusturmaMaliyeti++;
            cikti << this->kayitlar[i]->anahtar << " => " << this->kayitlar[i]->deger << endl;
        }

    }
    cikti.close();

}

void KatlamaLineer::Arama(int aranan) {
    int aramaMaliyeti = 0;
    int hash = Katlama(aranan);
    aramaMaliyeti++;
    int adres = hash;
    aramaMaliyeti++;
    int sayac = 0;
    aramaMaliyeti++;

    while (this->kayitlar[adres]->ogrNo != aranan) {
        if (sayac >= 500) {
            cout << "Kare Ortasi Lineer Yoklama tablosunda bulunamadi" << endl;
            return;
        }
        adres = (adres + 1) % tabloBoyutu;
        aramaMaliyeti++;
        sayac++;
    }

    cout << "Katlama Lineer Yoklama tablosunda: " << endl;
    cout << "\t Dosya olusturma maliyeti: " << olusturmaMaliyeti << endl;
    cout << "\t Arama  maliyeti: " << aramaMaliyeti << endl;
    cout << "\t Hash: " << hash << endl;
    cout << "\t Tabloda yeri: " << adres << endl;
    cout << "\t\t " << kayitlar[adres]->deger << endl;
}




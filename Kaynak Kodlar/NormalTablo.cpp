

#include <fstream>
#include <sstream>
#include <iostream>
#include "NormalTablo.h"


NormalTablo::NormalTablo() {
    this->olusturmaMaliyeti = 0;
    ifstream f("../kisiler.txt");
    olusturmaMaliyeti++;
    int ogrNo;
    olusturmaMaliyeti++;
    string isim;
    olusturmaMaliyeti++;
    string soyisim;
    olusturmaMaliyeti++;

    int sayac = 0;
    olusturmaMaliyeti++;

    for (std::string line; std::getline(f, line);) {

        //internetten
        std::stringstream stream(line);
        olusturmaMaliyeti++;

        while (stream >> ogrNo >> isim >> soyisim) {


            string deger = to_string(ogrNo) + " " + isim + " " + soyisim;
            olusturmaMaliyeti++;

            kayitlar[sayac] = new Kayit(sayac, ogrNo, isim, soyisim, deger);
            olusturmaMaliyeti++;

            sayac++;
        }
    }
}

void NormalTablo::Arama(int aranan) {
    int aramaMaliyeti = 0;
    for(int i = 0; i < tabloBoyutu; i++){
        aramaMaliyeti++;
        if(kayitlar[i]->ogrNo == aranan){
            cout << "Kisiler dosyasinda Lineer Arama: " << endl;
            cout << "\t Dosya olusturma maliyeti: " << olusturmaMaliyeti << endl;
            cout << "\t Arama  maliyeti: " << aramaMaliyeti << endl;
            cout << "\t Hash: - "  << endl;
            cout << "\t Tabloda yeri: " << i << endl;
            cout << "\t\t " << kayitlar[i]->deger << endl;
            return;
        }
    }
}






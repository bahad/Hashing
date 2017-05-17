

#include <fstream>
#include <iostream>
#include <sstream>
#include "KareortasiLineer.h"

using namespace std;

KareortasiLineer::KareortasiLineer() {
    for (int i = 0; i < tabloBoyutu; i++) {
        this->kayitlar[i] = NULL;
    }
    this->olusturmaMaliyeti = 0;
    this->kapasite = 0;
}

/*
 * Gelen öğrenci numarasının karesini alıyoruz.
 * 9 basamaklı sayının karesi 17-18 olabilir.
 * Büyük olduğu için int olarak tutumayız, taşar.
 * Bunun yerine unsigned long long int olarak tutuyoruz.
 *
 * Bize bu elde ettigimiz yeni sayının ortadaki "n" hanesi lazım (çünkü öyle istedik? bizde n=3)
 * Burda 3 haneye göre yaptık fakat değiştirilebilir
 * Eşit ayıramayacağımız için eşite en yakın durumu yakalamamız lazım,
 *  -sondaki 3'lü grup yokmuş gibi düşün.
 *
 * 		    Burası
		    Lazım
		    ***			Burayı
		    | |			Alma
    169 523 030 050 201 00      => 17 gelme durumu
    999 999 998 000 000 001     => 18 gelme durumu

    012 345 678 9AB CDE     => indisler (10'dan büyükleri tek karakterle göstermem gerekti)

 * Bu durumda yapmamız gereken şey aslında,
 *  - 6. basamaktaki sayi * 100 + 7. basamaktaki * 10 + 8. basamaktaki * 1
 *  - olması gerekiyor
 *
 *  Bunun yerine bulduğumuz bu kare sayıyı bir stringe(karakter dizisine),
 *      çevirip C++'da bulunan alt string bulma fonksiyonuyla,
 *      6. basamaktan 3 adım ilerleyerek oluşan alt stringi bulalım.
 *      Daha sonra bunu tekrar sayıya çevirelim.
 *
 *      Yukardaki örnek için [stringiAtadığımızDeğişken].substr(6,3) (başlangıç indisi, adım sayısı)
 *      yaparsak 030 elde ederiz.
 *      Bunu tekrar integera çevirirsek 30 elde ederiz. (baştaki 0'ın hiç bir anlamı yok matematikte)
 *
 */
int KareortasiLineer::KareOrtasi(unsigned long long ogrenciNumarasi) {
    unsigned long long  kare = ogrenciNumarasi * ogrenciNumarasi;
    int sonuc = 0;

    string s = to_string(kare);

    s = s.substr(6, 3);
    sonuc = std::stoi(s);   //string to integer "030" => 30

    return sonuc % tabloBoyutu;
}

void KareortasiLineer::Yoklama() {
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
            int adres = KareOrtasi(ogrNo);
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
        }
    }

    ofstream cikti("../kareortasi-lineer.txt");
    olusturmaMaliyeti++;
    for (int i = 0; i < tabloBoyutu; i++) {
        if (this->kayitlar[i] != NULL) {
            cikti << this->kayitlar[i]->anahtar << " => " << this->kayitlar[i]->deger << endl;
            olusturmaMaliyeti++;
        }

    }
    cikti.close();
}

void KareortasiLineer::Arama(int aranan) {
    int aramaMaliyeti = 0;
    int hash = KareOrtasi(aranan);
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

    cout << "Kare Ortasi Lineer Yoklama tablosunda: " << endl;
    cout << "\t Dosya olusturma maliyeti: " << olusturmaMaliyeti << endl;
    cout << "\t Arama  maliyeti: " << aramaMaliyeti << endl;
    cout << "\t Hash: " << hash << endl;
    cout << "\t Tabloda yeri: " << adres << endl;
    cout << "\t\t " << kayitlar[adres]->deger << endl;
}





#include <iostream>
#include <random>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "KatlamaLineer.h"
#include "KareortasiLineer.h"
#include "BolenkalanLineer.h"
#include "BolenkalanAyrik.h"
#include "KatlamaAyrik.h"
#include "KareortasiAyrik.h"
#include "NormalTablo.h"

using namespace std;


//http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string randomString(size_t length) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<> indexRand(0, 25);
    auto randchar = [&]() -> char {
        const char charset[] =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[indexRand(rng) % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

//http://stackoverflow.com/questions/13445688/how-do-generate-a-random-number-in-c
string randomID() {

    std::mt19937 rng;   //random besleyici
    rng.seed(std::random_device()());

    // 130 201 010
    std::uniform_int_distribution<> yilRand(10, 15);    //[10-15]0
    std::uniform_int_distribution<> bolumRand(100, 500);    // [10-15]0 [100-400]
    std::uniform_int_distribution<> siraRand(1, 500);       //  [10-15]0 [100-400] [001-500]


    string yil = to_string(yilRand(rng)) + "0";

    string bolum = to_string(bolumRand(rng));

    auto sira = [&]() -> string {
        string s = to_string(siraRand(rng));

        if (s.length() == 1) {
            s = "00" + s;
        } else if (s.length() == 2) {
            s = "0" + s;
        }

        return s;
    };

    //     130   201     010
    return yil + bolum + sira();

}

void randomDosyaOlustur() {
    int kisiSayisi = 500;
    ofstream randomDosya("../kisiler.txt");

    vector<string> okulNumaralari(kisiSayisi, " "); // icinde okul numaralarını tutuyoruz, daha sonra aynı oluşmasın diye bakacağız


    for (int i = 0; i < kisiSayisi; i++) {
        string okulNo;
        string isim;
        string soyisim;

        do {
            okulNo = randomID();
            isim = randomString(10);
            soyisim = randomString(10);

        } while (binary_search(okulNumaralari.begin(), okulNumaralari.end(), okulNo));

        okulNumaralari.push_back(okulNo);

        randomDosya << okulNo << " " << isim << " " << soyisim << endl;

        cout << "\r" << i + 1 << " eklendi";
    }
    cout << endl;

    randomDosya.close();
}

int main() {

    /*
     //for debug

    vector<int> test;
    int tmp;
    int c = 0;
     */
    randomDosyaOlustur();

    KatlamaLineer katlamalineer = KatlamaLineer();
    katlamalineer.Yoklama();

    KareortasiLineer kareortasilineer = KareortasiLineer();
    kareortasilineer.Yoklama();

    BolenkalanLineer bolenkalanlineer = BolenkalanLineer();
    bolenkalanlineer.Yoklama();

    BolenkalanAyrik bolenkalanayrik = BolenkalanAyrik();
    bolenkalanayrik.Yoklama();

    KatlamaAyrik katlamaayrik = KatlamaAyrik();
    katlamaayrik.Yoklama();

    KareortasiAyrik kareortasiayrik = KareortasiAyrik();
    kareortasiayrik.Yoklama();

    NormalTablo normaltablo = NormalTablo();

    int ogrenciNo=0;
    while(1){
        cout << "Tum tablolarda aranacak ogrenci numarasini giriniz (Cikmak icin -1): "<< endl;
        cin >> ogrenciNo;
        if(ogrenciNo == -1){
            break;
        }

        bolenkalanlineer.Arama(ogrenciNo);
        kareortasilineer.Arama(ogrenciNo);
        katlamalineer.Arama(ogrenciNo);

        bolenkalanayrik.Arama(ogrenciNo);
        kareortasiayrik.Arama(ogrenciNo);
        katlamaayrik.Arama(ogrenciNo);

        normaltablo.Arama(ogrenciNo);
    }

    return 0;
}
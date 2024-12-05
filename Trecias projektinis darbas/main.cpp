#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const char ABECELE[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
//Si funkcija uzkoduoja vartotojo ivesta zodi.
//Raktas yra labai svarbus nes jis nurodo kokia raide reikes naudoti sifruojant zodi
string encode(const char *text, char *key) {

    char encoded[50];
    int textIndex[50];
    int keyIndex[50];
    int tekstoTlgis, keyilgis;

    tekstoTlgis = strlen(text);
    for (int i = 0; i < tekstoTlgis; i++) {
        for(int j=0; j<sizeof(ABECELE); j++) {
            if(tolower(text[i]) == ABECELE[j]) {
                textIndex[i] = j ;
            }
        }
    }

        keyilgis = strlen(key);
        for(int i=0; i< keyilgis; i++) {
            for(int j=0; j<sizeof(ABECELE); j++) {
            if(tolower(key[i]) == ABECELE[j]) {
               keyIndex[i] = j ;
            }
            }
        }

        cout << "Uzkoduotas tekstas: " << '\n';
        for(int i=0; i< tekstoTlgis; i++) {
            int keyPradzia = i % keyilgis;
            encoded[i] = (textIndex[i] + keyIndex[keyPradzia]) % sizeof(ABECELE);
            cout << ABECELE[encoded[i]];
        }
    cout << '\n';
    return encoded; // grazina gauta zodi i main dali, kurioje yra isvedamas rezultatas
}


//Si funkcija desifruoja vartotojo ivesta uzsifruota zodi su raktu
string decod(const char *text, char *key) {

    char decoded[50];
    int textIndex[50];
    int keyIndex[50];
    int tekstoTlgis, keyilgis;

    tekstoTlgis = strlen(text);
    for (int i = 0; i < tekstoTlgis; i++) {
        for(int j=0; j<sizeof(ABECELE); j++) {
            if(tolower(text[i]) == ABECELE[j]) {
                textIndex[i] = j ;
            }
        }
    }

    keyilgis = strlen(key);
    for(int i=0; i< keyilgis; i++) {
        for(int j=0; j<sizeof(ABECELE); j++) {
            if(tolower(key[i]) == ABECELE[j]) {
                keyIndex[i] = j ;
            }
        }
    }

    cout << "Neuzkoduotas tekstas: " << '\n';
    for(int i=0; i< tekstoTlgis; i++) {
        int keyPradzia = i % keyilgis;
        decoded[i] = (textIndex[i] - keyIndex[keyPradzia] + sizeof(ABECELE)) % sizeof(ABECELE);
        cout << ABECELE[decoded[i]];
    }
    cout << '\n';
    return decoded; // grazina gauta zodi i main dali, kurioje yra isvedamas rezultatas
}

int getASCII(char ch) {
    return static_cast<int>(ch);
}

int getOutOfASCII (int skaicius) {
    return static_cast<char>(skaicius);
}

// ASCII koduote
void encode2() {
    char text2[50];
    char key2[50];
    char encoded2[50];

    cout << "Iveskite norima zodi, kuri norite uzkoduoti: " << '\n';
    cin >> text2;
    cout << "Iveskie rakta: " << '\n';
    cin >> key2;

    int textIlgis = strlen(text2);
    int keyIlgis = strlen(key2);

    for(int i=0; i< textIlgis; i++) {
        int textASCII = getASCII(text2[i]);
        int keyASCII = getASCII(key2[i%keyIlgis]);

        //Kad reikste ASCII koduoteje butu nuo 33 iki 127
        encoded2[i] = (textASCII + keyASCII - 33) % 94 + 33;
        cout << encoded2[i]; // isvedame uzsifruota zodi
    }
    cout << '\n';
}

void decode2() {
    char text2[50];
    char key2[50];
    char decoded2[50];

    cout << "Iveskite uzkoduota zodi: " << '\n';
    cin >> text2;
    cout << "Iveskie rakta: " << '\n';
    cin >> key2;

    int textIlgis = strlen(text2);
    int keyIlgis = strlen(key2);

    for(int i=0; i< textIlgis; i++) {
        int textASCII = getASCII(text2[i]);
        int keyASCII = getASCII(key2[i%keyIlgis]);

        decoded2[i] = (textASCII - keyASCII - 33 + 94) % 94 + 33; // kad isvedinetu nuo 33 iki 127
        // konvertuojam i simboli ir isvedame
        char decoded3 = getOutOfASCII(decoded2[i]);
        cout << decoded3;
    }
    cout << '\n';
}

int main() {
   int op=0;
    int pas=0;

    while (op!=3) {
        cout << "Pasirinkite norima funkcija" << '\n';
        cout << "1. Paprastas sifravimas desifravimas" << '\n';
        cout << "2. ASCII sifravimas desifravimas" << '\n';
        cout << "3. Iseiti" << '\n';
        cin >> op;

        switch (op) {
            case 1:
                cout << "Sifravimas ir desifravimas su abecele" << '\n';
            cout << "1. Sifravimas" << '\n';
            cout << "2. Desifravimas" << '\n';
            cin >> pas;
            if (pas == 1) {
                cout << "Iveskite norima zodi, kuri norite uzkoduoti: " << '\n';
                char text[50];
                cin >> text;
                cout << "Iveskie rakta: " << '\n';
                char key[50];
                cin >> key;

                string encoded = encode(text, key);
                cout << encoded << '\n';
            }
                else if (pas == 2) {
                    cout << "Iveskite uzsifruota teksta: " << '\n';
                   char text[50];
                    cin >> text;
                    cout << "Iveskie rakta: " << '\n';
                    char key[50];
                    cin >> key;

                    string decoded = decod(text, key);
                    cout << decoded << '\n';
                }
            else {
                cout << "Tokio pasirinkimo nera. Bandykite dar karta" << '\n';
            }
            break;
            case 2:
                cout << "Sifravimas ir desifravimas su ASCII" << '\n';
            cout << "1. Sifravimas" << '\n';
            cout << "2. Desifravimas" << '\n';
            cin >> pas;
            if(pas == 1) {
                encode2();
            }
            else if (pas == 2) {
              decode2();
            }
            else {
                cout << "Tokio pasirinkimo nera. Bandykite dar karta" << '\n';
            }
                break;
            case 3:
                cout << "Jus isejote is programos" << '\n';
            break;
            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta" << '\n';
            break;
        }
    }

    return 0;
}

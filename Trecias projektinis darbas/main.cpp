#include <iostream>
#include <string>
#include <cstring>

using namespace std;


//Si funkcija uzkoduoja vartotojo ivesta zodi.
//Raktas yra labai svarbus nes jis nurodo kokia raide reikes naudoti sifruojant zodi
string encode(string text, int key) {

    char ABECELE[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string encoded = "";

    for (int i = 0; i < text.length(); i++){
        int low = tolower(text[i]);
        int index = low - 97;
        int shift = (index + key) % 26;
        char character = ABECELE[shift];
        encoded.push_back(character); // cia ivyksta kaip grandine nes kiekviena zodi ikelia ir susidaro pilnas uzsifruotas zodis
    }
    return encoded; // grazina gauta zodi i main dali, kurioje yra isvedamas rezultatas
}

//Si funkcija desifruoja vartotojo ivesta uzsifruota zodi su raktu
string decod(string encode, int key) {

    char ABECELE[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string decoded = "";

    for (int i = 0; i < encode.length(); i++) {
        int low = tolower(encode[i]);
        int index = low - 97;
        int shift = index - key;
        // cia panasiai kaip if salyga tik vienoje eiluteje kur pliusas yra true kur procentas yra false
        //si salyga reikalinga tam, kad skaiciai eitu is kitos puses
        (shift < 0) ? shift = shift + 26 : shift = shift % 26;
        decoded.push_back(ABECELE[shift]); // cia ivyksta kaip grandine nes kiekviena zodi ikelia ir susidaro pilnas desifruotas zodis
    }
    return decoded; // grazina gauta zodi i main dali, kurioje yra isvedamas rezultatas
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
                string text = "";
                cin >> text;
                cout << "Iveskie rakta: " << '\n';
                int key;
                cin >> key;
                key = key % 26;

                string encoded = encode(text, key);
                cout << encoded << '\n';
            }
                else if (pas == 2) {
                    cout << "Iveskite uzsifruota teksta: " << '\n';
                    string encode = "";
                    cin >> encode;
                    cout << "Iveskie rakta: " << '\n';
                    int key;
                    cin >> key;

                    string decoded = decod(encode, key);
                    cout << decoded << '\n';
                }
            else {
                cout << "Tokio pasirinkimo nera. Bandykite dar karta" << '\n';
            }
            break;
            case 2:
                cout << "ASCII koduote" << '\n';
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

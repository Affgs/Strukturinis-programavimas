#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//Tikrina ar ivesta raide bus balsis ar ne
bool Balsis(char raide) {
 char mazRaides[] = {'a','e','i','y','o','u'};
    char didRaides[] = {'A','E','I','Y','O','U'};

    for (int i = 0; i < 6; i++) {
        if(raide == mazRaides[i]|| raide == didRaides[i]) {
            return true;
        }
    }
        return false;
}

int didziausiasBendrasisDaliklis(int sk1, int sk2) {
    while (sk2 != 0) {
        int laikinas = sk2; //isaugome sk 2
        sk2 = sk1 % sk2; //radame liekana
        sk1 = laikinas; //perkeliam is laikino i sk1
    }
    return sk1; //sk1 yra didziausias bendrasis daliklis
}

//Zaidimas, kuriame turite atespeji skaiciu nuo 1 iki 100
void game() {
    srand(time(0)); // sugeneruoja atsitiktini skaiciu
    int atsitiktinisSk = rand() % 100 + 1;
    int spejimas;

    cout << "Atspekite skaiciu nuo 1 iki 100" << endl;

    while(true) {
        cout << "Iveskite skaiciu kuri norite speti: " << endl;
        cin >> spejimas;

        if(spejimas < atsitiktinisSk) {
            cout << "Per mazas" << endl;
        }
        else if (spejimas > atsitiktinisSk) {
            cout << "Per didelis" << endl;
        }
        else {
            cout << "Jus atspejote skaiciu" << endl;
            break;
        }
    }
}

void void_fizzbuzz(int n) {
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0 && i % 5 == 0) {
            cout << "Fizzbuzz" << endl;
        }
        else if(i % 3 == 0) {
            cout << "Fizz" << endl;
        }
        else if(i % 5 == 0) {
            cout << "Buzz" << endl;
        }
        else {
            cout << i << endl;
        }
    }
}


int main() {

    int operacija = 0;

    while (operacija!=5) {
        cout << "Pasirinkite viena is norimu funkciju" << endl;
        cout << "1. Balses patikrinimas" <<endl;
        cout << "2. Didziausias bendras daliklis" << endl;
        cout << "3. Zaidimas" << endl;
        cout << "4. Fizzbuzz" << endl;
        cout << "5. Iseiti" << endl;
        cout << "Jusu pasirinkimas" << endl;
        cin >> operacija;
        switch (operacija) {
            case 1:
                char raide;
            cout << "Iveskite raide" << endl;
            cin >> raide;

            if (Balsis(raide)) {
                cout << "Raide yra balsis" << endl;
            }
            else {
                cout << "Raide nera balsis" << endl;
            }
                break;
            case 2:
                int sk1, sk2;
            cout << "Iveskite du skaicius, kad galetumeme rasti didziausia bendraji dalikli" << endl;
            cin >> sk1 >> sk2;
            int rezultatas;
            rezultatas = didziausiasBendrasisDaliklis(sk1,sk2);
            cout <<"Didziausias bendrasis daliklis yra: " << rezultatas << endl;
            break;
            case 3:
                game();
                break;
            case 4:
                int n;
            cout << "Iveskite sveikaji teigiamaji skaiciu ";
            cin >> n;

            if(n>0) {
                void_fizzbuzz(n);
            }
            else {
                cout << "Ivestas skaicius turi buti sveikasis ir teigiamas" << endl;
            }
                break;
            case 5:
                cout << "Jus isejote is funkciju pasirinkimo" << endl;
            break;
            default:
                cout << "Tokio pasirinkimo nera" << endl;
        }
    }
    return 0;
}




#include  <iostream>
#include <iomanip>

using namespace std;

//Valiutos INR - Indijos rupija, GBP - Britanijos svaras, USD - Amerijos doleris.
double GBPsell = 0.9060;
double GBPbuy = 0.8450;
double GBPcompare = 0.8593;
double USDcompare = 1.0713;
double USDbuy = 1.0547;
double USDsell = 1.1309;
double INRcompare = 88.8260;
double INRbuy = 85.2614;
double INRsell = 92.83341
;

//Kovertavimas i kita valiuta ir tuo paciu tai yra palyginimas kiek euru gali buti kitos valiutos  arba atvirksciai
//Vartotojas pasirenka is kokios valiutos i kokia kita valiuta jis nori konvertuoti iraso suma ir gali pamatyti irasyta suma ir salia konvertuotos valiutos suma
void getCompareCurrency() {
    int op = 0;
    double pradk;
    double galutk;
    while (op != 7) {
        cout << "Pasirinkite kuria valiuta Jus norite konvertuoti i kita valiuta." << endl;
        cout << "1. EUR - Eurus i GBP - Didziosios Britanijos svaras" << endl;
        cout << "2. EUR - Eurus i USD - Juntiniu valstyju doleris " << endl;
        cout << "3. EUR - Eurus i INR - Indijos rupija" << endl;
        cout << "4. GBP - Didziosios Britanijos svaras i EUR - Eurus" << endl;
        cout << "5. USD - Juntiniu valstyju doleris i EUR - Eurus" << endl;
        cout << "6. INR - Indijos rupija i EUR - Eurus" << endl;
        cin >> op;
        switch (op) {
            case 1:
            cout << "Irasykite norima EUR valiutos kieki" << endl;
            cin >> pradk;
            galutk = pradk * GBPcompare;
            cout << pradk << fixed <<setprecision(2) << " EUR " << galutk << fixed <<  setprecision(2) << " GBP." << endl;
            break;
            case 2:
            cout << "Irasykite norima EUR valiutos kieki" << endl;
            cin >> pradk;
            galutk = pradk * USDcompare;
            cout <<  pradk << fixed <<setprecision(2) << " EUR " << galutk << fixed <<setprecision(2) << " USD." << endl;
            break;
            case 3:
            cout << "Irasykite norima EUR valiutos kieki" << endl;
            cin >> pradk;
            galutk = pradk * INRcompare;
            cout << pradk << fixed <<setprecision(2) << " EUR " << galutk << fixed <<setprecision(2) << " INR." << endl;
            break;
            case 4:
            cout << "Irasykite norima GBP valiutos kieki" << endl;
            cin >> pradk;
            galutk = pradk / GBPcompare;
            cout << pradk << fixed <<setprecision(2) << " GBP " << galutk << fixed <<setprecision(2) << " EUR." << endl;
            break;
            case 5:
            cout << "Irasykite norima USD valiutos kieki" << endl;
            cin >> pradk;
            galutk = pradk / USDcompare;
            cout << pradk << fixed <<setprecision(2) << " USD " << galutk << fixed <<setprecision(2) << " EUR." << endl;
            break;
            case 6:
            cout << "Irasykite norima INR valiutos kieki" << endl;
            cin >> pradk;
            galutk = pradk / INRcompare;
            cout  << pradk << fixed <<setprecision(2) << " INR " << galutk << fixed <<setprecision(2) << " EUR." << endl;
            break;
            case 7:
                cout << "Jus isejote is valiutos konvertavimo/palyginimo programos" << endl;
            break;
            default:
                cout <<"Tokio pasirinkimo nera. Bandykite dar karta"<<endl;

        }
    }
}

//Valiutos pirkimas vartotojas iraso norima suma uz kuria nori nusipirkti valiuta ir gale jis pamatys uz kiek euru pirko ir koki kieki valiutos gavo
void getBuyCurrency() {
    int ope = 0;
    double pradinisk;
    double galutinisk;
    while (ope != 7) {
        cout << "Pasirinkite, kuria valiuta Jus norite nusipirkti: EUR, GBP, USD arba INR." << endl;
        cout << "1. GBP - Didziosios Britanijos svaras uz EUR - Eurus" << endl;
        cout << "2. USD - Junktiniu valstyju doleris uz EUR - Eurus" << endl;
        cout << "3. INR - Indijos rupija uz EUR - Eurus" << endl;
        cout << "4. EUR - Eurus uz GBP - Didziosios Britanijos svarus" << endl;
        cout << "5. EUR - Eurus uz USD - Jungtiniu valstyju dolerius" << endl;
        cout << "6. EUR - Eurus uz INR - Indijos rupijas" << endl;
        cin >> ope;
        switch (ope) {
            case 1:
            cout << "Irasykite norima EUR kieki uz kuri noresite nusipirkti GBP valiuta" << endl;
            cin >> pradinisk;
            galutinisk = pradinisk * GBPbuy;
            cout << pradinisk << fixed <<setprecision(2) << " EUR " << galutinisk << fixed <<setprecision(2) << " GBP" << endl;
            break;
            case 2:
            cout << "Irasykite norima EUR kieki uz kuri noresite nusipirkti USD valiuta" << endl;
            cin >> pradinisk;
            galutinisk = pradinisk * USDbuy;
            cout<< pradinisk << fixed <<setprecision(2) << " EUR " << galutinisk << fixed <<setprecision(2) << " USD" << endl;
            break;
            case 3:
            cout << "Irasykite norima EUR kieki uz kuri noresite nusipirkti INR valiuta" << endl;
            cin >> pradinisk;
            galutinisk = pradinisk * INRbuy;
            cout << pradinisk << fixed <<setprecision(2) << " EUR " << galutinisk << fixed <<setprecision(2) << " INR" << endl;
            break;
            case 4:
            cout << "Irasykite norima GBP kieki uz kuri noresite nusipirkti EUR valiuta" << endl;
            cin >> pradinisk;
            galutinisk = pradinisk / GBPbuy;
            cout << pradinisk << fixed <<setprecision(2) << " GBP " << galutinisk << fixed <<setprecision(2) << " EUR" << endl;
            break;
            case 5:
            cout << "Irasykite norima USD kieki uz kuri noresite nusipirkti EUR valiuta" << endl;
            cin >> pradinisk;
            galutinisk = pradinisk / USDbuy;
            cout << pradinisk << fixed <<setprecision(2) << " USD " << galutinisk << fixed <<setprecision(2) << " EUR" << endl;
            break;
            case 6:
            cout << "Irasykite norima INR kieki uz kuri noresite nusipirkti EUR valiuta" << endl;
            cin >> pradinisk;
            galutinisk = pradinisk / INRbuy;
            cout << pradinisk << fixed <<setprecision(2) << " INR " << galutinisk << fixed <<setprecision(2) << " EUR" << endl;
            break;
            case 7:
                cout << "Jus isejote is valiutos pirkimo programos" << endl;
            break;
            default:
                cout <<"Tokio pasirinkimo nera. Bandykite dar karta"<<endl;
        }
    }

}

//valiutos pardavimas kur vartotojas irasys koki kieki valiutos nori parduoti ir pamatys kiek jis gaus pinigu uz tai
void getSellCurrency() {
    int operac = 0;
    double pradinis;
    double galutinis;
    while (operac != 7) {
        cout << "Pasirinkite kuria valiuta Jus norite parduoti: EUR, GBP, USD arba INR" << endl;
        cout << "1. GBP - Didziosios Britanijos svaras uz EUR - Eurus" << endl;
        cout << "2. USD - Junktiniu valstyju doleris uz EUR - Eurus" << endl;
        cout << "3. INR - Indijos rupija uz EUR - Eurus" << endl;
        cout << "4. EUR - Eurus uz GBP - Didziosios Britanijos svarus" << endl;
        cout << "5. EUR - Eurus uz USD - Jungtiniu valstyju dolerius" << endl;
        cout << "6. EUR - Eurus uz INR - Indijos rupijas" << endl;
        cin >> operac;
        switch (operac) {
            case 1:
            cout << "Irasykite valiutos GBP kieki kuriJus norite parduoti uz Eurus" << endl;
            cin >> pradinis;
            galutinis = pradinis * GBPsell;
            cout << pradinis << fixed <<setprecision(2) << " kiekis " << galutinis << fixed <<setprecision(2) << " GBP" << endl;
            break;
            case 2:
            cout << "Irasykite valiutos USD kieki kuriJus norite parduoti uz Eurus" << endl;
            cin >> pradinis;
            galutinis = pradinis * USDsell;
            cout << pradinis << fixed <<setprecision(2) << " kiekis " << galutinis << fixed <<setprecision(2) << " USD" << endl;
            break;
            case 3:
            cout << "Irasykite valiutos INR kieki kuri Jus norite parduoti uz Eurus" << endl;
            cin >> pradinis;
            galutinis = pradinis * INRsell;
            cout << pradinis << fixed <<setprecision(2) << " kiekis " << galutinis << fixed <<setprecision(2) << " INR" << endl;
            break;
            case 4:
            cout << "Irasykite valiutos EUR kieki kuri Jus norite parduoti uz GBP" << endl;
            cin >> pradinis;
            galutinis = pradinis / GBPsell;
            cout << pradinis << fixed <<setprecision(2) << " kiekis " << galutinis << fixed <<setprecision(2) << " EUR" << endl;
            break;
            case 5:
            cout << "Irasykite valiutos EUR kieki kuri Jus norite parduoti uz USD" << endl;
            cin >> pradinis;
            galutinis = pradinis / USDsell;
            cout << pradinis << fixed <<setprecision(2) << " kiekis " << galutinis << fixed <<setprecision(2) << " EUR" << endl;
            break;
            case 6:
            cout << "Irasykite valiutos EUR kieki kuri Jus norite parduoti uz INR" << endl;
            cin >> pradinis;
            galutinis = pradinis / INRsell;
            cout << pradinis << fixed <<setprecision(2) << " kiekis " << galutinis << fixed <<setprecision(2) << " EUR" << endl;
            break;
            case 7:
                cout << "Jus isejote is valiutos pardavimo programos" << endl;
            break;
            default:
                cout <<"Tokio pasirinkimo nera. Bandykite dar karta"<<endl;
        }
    }
}

int main() {

    int operacija = 0;

    //Maine mes galime pasirinkti programa kuria norime ir mus iskarto nukreipia i viena is 3 funkciju kurioje yra atliekami visi pasirinkimai ir sprendimai
    //Tose funkcijuose yra daugiau pasirinkimu, kurie palygina, nuperka arba parduoda valiuta
    while (operacija != 4) {
        cout <<"Valiutos pasirinkimas"<<endl;
        cout <<"1. Valiutos palyginimas"<<endl;
        cout <<"2. Valiutos pirkimas"<<endl;
        cout <<"3. Valiutos pardavimas"<<endl;
        cout <<"4. Iseiti"<<endl;
        cout <<"Jusu pasirinkimas"<<endl;
        cin >> operacija;
        switch (operacija) {
            case 1:
               getCompareCurrency();
                break;
            case 2:
                getBuyCurrency();
                break;
            case 3:
                getSellCurrency();
                break;
            case 4:
                cout << "Jus isejote is valiutos programos" << endl;
                break;
            default:
                cout << "Tokio pasirinkimo nera" << endl;
        }
        }
    
    return 0;
}


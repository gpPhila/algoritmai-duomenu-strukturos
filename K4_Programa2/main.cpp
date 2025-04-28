/*
Duotas dvikryptis sąrašas, kurio elementai yra simboliai. Nustatyti ar yra jame duotas
žodis
*/

#include <iostream>
#include <string>
using namespace std;

struct dviKryptSarasas {
    dviKryptSarasas *pirmyn;
    char duom;
    dviKryptSarasas *atgal;
};
dviKryptSarasas *pradzia = nullptr , *pabaiga = nullptr;

void ivedimas();
bool patikrinimas(const string& zodis);
void salinimas();
int main() {
    int pasirinkimas;
    string zodis;
    while (pasirinkimas !=4) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Simboliu ivedimas."<<endl;
        cout<<"2. Zodzio ivedimas ir paieska sarase."<<endl;
        cout<<"3. Istrinti visus saraso elementus."<<endl;
        cout<<"4. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                ivedimas();
            break;

            case 2:
                cout<<"Iveskite zodi:"<<endl;
                cin>>zodis;
                if (patikrinimas(zodis)) {
                    cout << "Sarase yra toks zodis!" << endl;
                } else {
                    cout << "Sarase nera tokio zodzio." << endl;
                }
            break;

            case 3:
                salinimas();
                cout<<"Simboliai buvo istrinti, galite bandyti dar karta arba iseiti."<<endl;
            break;

            case 4:
                cout<<"Jus isejote."<<endl;
            break;

            default:
                cout<<"Tokio pasirinkimo nera,"<<endl;
        }
    }
    return 0;
}

void ivedimas() {
    int skaicius;
    char reiksme;
    cout<<"Kiek simboliu norite ivesti?"<<endl;
    cin>>skaicius;
    cout<<"Iveskite simbolius per tarpa:"<<endl;
    for (int i = 0; i < skaicius; i++) {
        cin>>reiksme;
        dviKryptSarasas *naujas = new dviKryptSarasas{nullptr, reiksme, nullptr};

        if (pradzia == nullptr) {
            pradzia = pabaiga = naujas;
        } else {
            pabaiga -> pirmyn = naujas;
            naujas -> atgal = pabaiga;
            pabaiga = naujas;
        }
    }
    cout<<"Ivesti simboliai yra:"<<endl;
    dviKryptSarasas *pr = pradzia;
    while (pr) {
        cout<<pr->duom<<" ";
        pr = pr->pirmyn;
    }
    cout<<endl;
}

bool patikrinimas(const string& zodis) {

    int simboliuSkaiciai[26] = {0}; //bus irasyta kiek kartu kiekviena raide buvo ivesta
    dviKryptSarasas *pr = pradzia;
    while (pr) {
        //patikrina ar tai isvis yra raide
        if (pr->duom >= 'a' && pr->duom <= 'z') {
            simboliuSkaiciai[pr->duom - 'a']++; //apsk kiek kartu pasikartoja raide
        }
        pr = pr->pirmyn;
    }

    //kiekviena raide ivestame zodyje
    for (char x : zodis) {
        if (x >= 'a' && x <= 'z') {
            if (simboliuSkaiciai[x - 'a'] > 0) {
                simboliuSkaiciai[x - 'a']--;
            } else {
                return false;
            }
        }
    }
    return true;

    //zodzio paieska pradzia->pabaiga
    /*
    dviKryptSarasas *pr = pradzia;
    while (pr) {
        dviKryptSarasas *temp = pr;
        int zodisIndex = 0;

        while (temp && zodisIndex < zodis.length() && temp->duom == zodis[zodisIndex]) {
            zodisIndex++;
            temp = temp->pirmyn;
        }

        if (zodisIndex == zodis.length()) {
            return true;
        }
        pr = pr->pirmyn;
    }

    return false;
    */
}

void salinimas() {
    dviKryptSarasas *pr = pradzia;
    while (pr) {
        dviKryptSarasas *temp = pr;
        pr = pr->pirmyn;
        delete temp;
    }
    pradzia = pabaiga = nullptr;
}
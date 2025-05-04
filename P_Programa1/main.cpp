/*
Daugianaris "P" su sveikais koeficientais galima atvaizduoti kaip sąrašą ir, jei elementas ai=0, tai jį galima į
sąrašą ir neįvesti.
Sukurti loginę funkciją Ivesti(P), kuri įveda daugianarį iš tekstinio failo.
*/

#include <iostream>
#include <fstream>

using namespace std;

struct sarasas {
    int duom;
    sarasas *kitas;
};
sarasas *pradzia = nullptr, *pabaiga = nullptr;

void daugianIvedimas ();
void ivesti();

int main () {
    int pasirinkimas;
    while (pasirinkimas !=3) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Daugianariu ivedimas i tekstini faila."<<endl;
        cout<<"2. Daugianario ivedimas is tekstinio failo i sarasa."<<endl;
        cout<<"3. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                daugianIvedimas();
            break;

            case 2:
                ivesti();
            break;

            case 3:
                cout<<"Jus isejote."<<endl;
            break;

            default:
                cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    return 0;
}

void daugianIvedimas () {
    int k, skaicius, laipsnis;
    ofstream failas;
    failas.open("daugianaris.txt");

    cout<<"Kiek kartu norite ivesti?"<<endl;
    cin>>k;

    for (int i = 0; i < k; i++) {
        cout<<"Iveskite "<<i+1<<" elemento skaiciu: "<<endl;
        cin>>skaicius;
        cout<<"Iveskite "<<i+1<<" elemento lapsni: "<<endl;
        cin>>laipsnis;
        failas << skaicius << " " << laipsnis << endl;
    }
    failas.close();

    cout<<"Skaiciai su laipsniais buvo irasyti i tekstini faila."<<endl;
}

void ivesti() {
    ifstream failas;
    failas.open("daugianaris.txt");

    int skaicius, laipsnis;
    while (failas >> skaicius >> laipsnis) {
        if (skaicius == 0) {
            continue;
        }

        sarasas *naujasSk = new sarasas {laipsnis, nullptr};
        if (pradzia == nullptr) {
            pradzia = naujasSk;
        } else {
            sarasas *temp = pradzia;
            while (temp->kitas !=nullptr) {
                temp = temp->kitas;
            }
            temp->kitas = naujasSk;
        }
        sarasas *naujasLap = new sarasas(skaicius, nullptr);
        sarasas *temp = pradzia;
        while (temp->kitas !=nullptr) {
            temp = temp->kitas;
        }
        temp->kitas = naujasLap;
    }

    failas.close();

    cout<<"Saraso duomenys: "<<endl;
    sarasas *temp = pradzia;
    while (temp != nullptr) {
        cout << temp->duom << " ";
        temp = temp->kitas;
    }
    cout << endl;
}
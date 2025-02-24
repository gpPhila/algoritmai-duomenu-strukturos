#include <iostream>
using namespace std;

void masyvoIvedimas(int *&masyvas, int &dydis);
void masyvoIsvedimas(int *&masyvas, int &dydis);
void rastiMazIndex(int *&masyvas, int &dydis);
void sumaPoPirmoNeig(int *&masyvas, int &dydis);
void suspaustiMasyva(int *&masyvas, int &dydis);

int main()
{
    int *masyvas = nullptr;
    int dydis = 0;

    int pasirinkimas;
    while (pasirinkimas !=6) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Ivedimas i masyva."<<endl;
        cout<<"2. Masyvo isdevimas."<<endl;
        cout<<"3. Rasti maziausia pagal absoliucia reiksme elemento indeksa."<<endl;
        cout<<"4. Suma pagal absoliucia reiksme elementu, esanciu po pirmojo neigiamo elemento."<<endl;
        cout<<"5. Suspausti masyva."<<endl;
        cout<<"6. Iseiti."<<endl;
        cin>>pasirinkimas;
        switch (pasirinkimas) {
            case 1: masyvoIvedimas(masyvas, dydis);
            break;

            case 2: masyvoIsvedimas(masyvas, dydis);
            break;

            case 3: rastiMazIndex(masyvas, dydis);
            break;

            case 4: sumaPoPirmoNeig(masyvas, dydis);
            break;

            case 5: suspaustiMasyva(masyvas, dydis);
            break;

            case 6: cout<<"Viso gero."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    delete[] masyvas;
    return 0;
}

void masyvoIvedimas(int *&masyvas, int &dydis) {
    cout<<"Pasirinkimas: Ivedimas i masyva."<<endl;

    cout<<"Iveskite masyvo dydi: ";
    cin>>dydis;
    masyvas = new int[dydis];

    cout<<"Iveskite masyvo duomenis (per tarpa): "<<endl;
    for (int i = 0; i < dydis; i++) {
        cin >> masyvas[i];
    }

    cout<<"Masyvo duomenys buvo irasyti."<<endl;
    cout<<endl;
}

void masyvoIsvedimas(int *&masyvas, int &dydis) {
    cout<<"Pasirinkimas: Masyvo isvedimas."<<endl;
    cout<<"Masyvo duomenys:"<<endl;

    for (int i = 0; i < dydis; i++) {
        cout<<masyvas[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

void rastiMazIndex(int *&masyvas, int &dydis) {
    int mazElementas = abs(masyvas[0]);
    int mazIndex = 0;
    cout<<"Pasirinkimas: Rasti maziausia pagal absoliucia reiksme elemento indeksa."<<endl;

    for (int i = 0; i < dydis; i++) {
        if (abs(masyvas[i]) < mazElementas) {
            mazElementas = masyvas[i];
            mazIndex = i;
        }
    }
    cout<<"Maziauso elemento pagal absoliucia reiksme INDEKSAS: "<<mazIndex<<endl;
    cout<<endl;
}

void sumaPoPirmoNeig(int *&masyvas, int &dydis) {
    int pirmNeigElemIndex = -1;
    cout<<"Pasirinkimas: Suma pagal absoliucia reiksme elementu, esanciu po pirmojo neigiamo elemento."<<endl;

    for (int i = 0; i < dydis; i++) {
        if (masyvas[i] < 0) {
            pirmNeigElemIndex = i;
            break;
        }
    }

    if (pirmNeigElemIndex == -1) {
        cout << "Nera neigiamu elementu." << endl;
        return;
    }

    cout<<"Pirmo neigiamo elemento INDEKSAS: "<<pirmNeigElemIndex<<endl;

    int suma = 0;
    for (int i = pirmNeigElemIndex + 1; i < dydis; i++) {
        suma += abs(masyvas[i]);
    }

    cout<<"Suma: "<<suma<<endl;
    cout<<endl;
}




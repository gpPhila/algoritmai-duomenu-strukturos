#include <iostream>
using namespace std;

struct sarasas {
    int duom;
    sarasas *kitas;
};
sarasas *pradzia = nullptr, *pabaiga = nullptr;

void ivedimasSarasas();
void isvedimasSaraso();
void mazElementas();
void sumaIkiPirmNulElem();
void sarasoTvarkymas();

int main()
{
    int pasirinkimas;
    while (pasirinkimas !=6) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Ivedimas i sarasa."<<endl;
        cout<<"2. Saraso isdevimas."<<endl;
        cout<<"3. Rasti maziausia pagal absoliucia reiksme elementa."<<endl;
        cout<<"4. Rasti suma pagal absoliucia reiksme elementu, iki pirmojo lygaus 0 elemento."<<endl;
        cout<<"5. Saraso tvarkymas: pirmoje puseje - lyginiai indeksai (iskaitant 0), antroje puseje - nelyginiai."<<endl;
        cout<<"6. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: ivedimasSarasas();
            break;

            case 2: isvedimasSaraso();
            break;

            case 3: mazElementas();
            break;

            case 4: sumaIkiPirmNulElem();
            break;

            case 5: sarasoTvarkymas();
            break;

            case 6: cout<<"Viso gero."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    return 0;
}

void ivedimasSarasas () {
    cout<<"Pasirinkimas: Ivedimas i sarasa."<<endl;

    int sarasoDydis;
    cout << "Iveskite saraso dydi: ";
    cin >> sarasoDydis;

    cout << "Iveskite saraso elementus: "<<endl;
    for (int i = 0; i < sarasoDydis; i++) {
        int skaicius;
        cin >> skaicius;

        sarasas *naujas = new sarasas{skaicius, nullptr};

        if (!pradzia) {
            pradzia = naujas;
        } else {
            pabaiga->kitas = naujas;
        }
        pabaiga = naujas;
    }
    cout<<"Elementu ivedimas yra atliktas."<<endl;
    cout<<endl;
}

void isvedimasSaraso() {
    cout<<"Pasirinkimas: Saraso isvedimas."<<endl;
    cout<<"Saraso duomenys: "<<endl;

    sarasas *pr=pradzia;
    while (pr !=NULL) {
        cout<< pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<endl;
    cout<<endl;
}

void mazElementas() {
    cout<<"Pasirinkimas: Rasti maziausia pagal absoliucia reiksme elementa."<<endl;

    sarasas *temp = pradzia;
    int minReiksme = temp->duom; //pirmiausias elementas

    while (temp) {
        if (abs(temp->duom) < abs(minReiksme)) {
            minReiksme = temp->duom;
        }
        temp = temp->kitas;
    }
    cout<<"Maziausias elementas pagal absoliucia reiksme: "<<minReiksme<<endl;
    cout<<endl;
}

void sumaIkiPirmNulElem() {
    cout<<"Pasirinkimas: Rasti suma pagal absoliucia reiksme elementu, iki pirmojo lygaus 0 elemento."<<endl;

    sarasas *temp = pradzia;
    int suma = 0;
    while (temp) {
        if (temp->duom == 0) {
        break;
        }
        suma += abs(temp->duom);
        temp = temp->kitas; //kad eitu toliau
    }
    cout<<"Suma elementu iki pirmojo lygaus 0 elemento: "<<suma<<endl;
    cout<<endl;
}

void sarasoTvarkymas() {
    cout << "Pasirinkimas: Saraso tvarkymas: pirmoje puseje - lyginiai indeksai (iskaitant 0), antroje puseje - nelyginiai." << endl;

    sarasas *lygPradzia = nullptr, *lygPabaiga = nullptr;
    sarasas *nelygPradzia = nullptr, *nelygPabaiga = nullptr;
    sarasas *temp = pradzia;
    int index = 0;

    while (temp) {
        if (index % 2 == 0) { //t.y. lyginiai skaiciai
            if (!lygPradzia) {
                lygPradzia = lygPabaiga = temp;
            }
            else {
                lygPabaiga->kitas = temp;
                lygPabaiga = lygPabaiga->kitas;
            }
        } else {
            if (!nelygPradzia) {
                nelygPradzia = nelygPabaiga = temp;
            }
            else {
                nelygPabaiga->kitas = temp;
                nelygPabaiga = nelygPabaiga->kitas;
            }
        }
        temp = temp->kitas;
        index++;
    }

    pradzia = lygPradzia;
    lygPabaiga->kitas = nelygPradzia; // suliejam sarasus
    nelygPabaiga->kitas = nullptr;

    cout << "Atnaujinti saraso duomenys: "<<endl;
    sarasas *pr=pradzia;
    while (pr !=NULL) {
        cout<< pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<endl;
    cout<<endl;
}

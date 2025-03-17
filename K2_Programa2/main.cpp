#include <iostream>
using namespace std;

    /*
Sukurti sąrašą, realizuojant duomenų įvedimą, įterpimą prieš ir po nurodyto elemento, norimo
elemento pašalinimą bei didžiausio elemento radimą. Realizuoti funkcijas, kurios:
a. Visus nelyginius skaičius perkelia į vienkryptį ciklinį sąrašą.
b. Apskaičiuoja kiek cikliniame sąraše yra elementų didesnių už 15.
c. Panaikina visus ciklinio sąrašo elementus, kurie yra mažesni už 10, atspausdinant juos
ekrane.
    */

struct sarasas {
    int duom;
    sarasas *kitas;
};
sarasas *pradzia = nullptr, *pabaiga = nullptr;

struct ciklinisSarasas {
    int duom;
    ciklinisSarasas *kitas;
};
ciklinisSarasas *pradziaCikl = nullptr;

void ivedimasSarasas();
void isvedimasSaraso();
void didElementas();
void iterpimasPries();
void iterpimasPo();
void elementoSalinimas();
void nelygPerkelimas(sarasas *pradzia);
void didesniuUz();
void panaikintiMazUz();

int main()
{
    int pasirinkimas;
    while (pasirinkimas !=10) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Ivedimas i sarasa."<<endl;
        cout<<"2. Saraso isdevimas."<<endl;
        cout<<"3. Iterpti elementa PRIES pasirinkta elementa."<<endl;
        cout<<"4. Iterpti elementa PO pasirinkto elemento."<<endl;
        cout<<"5. Norimo elemento salinimas."<<endl;
        cout<<"6. Rasti didziausia elementa."<<endl;
        cout<<"7. Nelyginiu skaiciu perkelimas i vienkrypti ciklini sarasa."<<endl;
        cout<<"8. Apskaiciuoti kiek cikliniame sarase yra elementu didesniu uz 15."<<endl;
        cout<<"9. Panaikinti ciklinio saraso elementus, mazesnius uz 10."<<endl;
        cout<<"10. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: ivedimasSarasas();
            break;
            case 2: isvedimasSaraso();
            break;
            case 3: iterpimasPries();
            break;
            case 4: iterpimasPo();
            break;
            case 5: elementoSalinimas();
            break;
            case 6: didElementas();
            break;
            case 7: nelygPerkelimas(pradzia);
            break;
            case 8: didesniuUz();
            break;
            case 9: panaikintiMazUz();
            break;
            case 10: cout<<"Viso gero."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera, bandykite dar karta."<<endl;
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

void didElementas() {
    cout<<"Pasirinkimas: Rasti didziausia elementa."<<endl;

    sarasas *temp = pradzia;
    int didReiksme = temp->duom;

    while (temp) {
        if (temp->duom > didReiksme) {
            didReiksme = temp->duom;
        }
        temp = temp->kitas;
    }
    cout<<"Didziausias elementas: "<<didReiksme<<endl;
    cout<<endl;
}

void iterpimasPries() {
    cout<<"PRIES koki elementa norite iterpti nauja?"<<endl;
    int priesElem, naujaReiksme;
    cin>>priesElem;
    cout<<"Iveskite naujo elemento reiksme: "<<endl;
    cin>>naujaReiksme;

    sarasas *naujasPries = new sarasas{naujaReiksme, nullptr};

    //jeigu pries pirma elementa
    if (pradzia->duom == priesElem) {
        naujasPries->kitas = pradzia;
        pradzia = naujasPries;
        return;
    }

    sarasas *temp = pradzia, *pries = nullptr;
    while (temp && temp->duom != priesElem) {
        pries = temp;
        temp = temp->kitas;
    }

    if (temp) {
        pries->kitas = naujasPries;
        naujasPries->kitas = temp;
    }
}

void iterpimasPo() {
    cout<<"PO kokio elemento norite iterpti nauja?"<<endl;
    int poElem, naujaReiksme;
    cin>>poElem;
    cout<<"Iveskite naujo elemento reiksme: "<<endl;
    cin>>naujaReiksme;

    sarasas *naujasPo = new sarasas{naujaReiksme, nullptr};
    sarasas *temp = pradzia;

    if (temp == pabaiga) {
        pabaiga = naujasPo;
    }

    while (temp && temp->duom != poElem) {
        temp = temp->kitas;
    }

    if (temp) {
        naujasPo->kitas = temp->kitas;
        temp->kitas = naujasPo;
    }
}

void elementoSalinimas() {
    cout<<"Koki elementa norite pasalinti?"<<endl;
    int delElem;
    cin>>delElem;

    sarasas *temp = pradzia, *pries = nullptr;
    while (temp && temp->duom != delElem) {
        pries = temp;
        temp = temp->kitas;
    }

    if (temp) {
        if (temp == pradzia) {
            pradzia = pradzia->kitas;
        } else if (temp->kitas == nullptr) {
                pries->kitas = nullptr;
                pabaiga = pries;
        } else {
            pries->kitas = temp->kitas;
        }
        delete temp;
    }
}

void nelygPerkelimas(sarasas *pradzia) {

    sarasas *temp = pradzia;
    while (temp) {
        if (temp->duom % 2 != 0) {
            ciklinisSarasas *naujas = new ciklinisSarasas {temp->duom, nullptr};

            if (pradziaCikl == nullptr) {
                pradziaCikl = naujas;
                pradziaCikl->kitas = pradziaCikl; // tampa cikliniu
            } else {
                ciklinisSarasas *pask = pradziaCikl;
                while (pask->kitas != pradziaCikl) {
                    pask = pask->kitas;
                }
                pask->kitas = naujas;
                naujas->kitas = pradziaCikl;
            }
        }
        temp = temp->kitas;
    }
    cout<<"Ciklinis sarasas:"<<endl;

    ciklinisSarasas *temp1 = pradziaCikl;
    do {
        cout << temp1->duom << " ";
        temp1 = temp1->kitas;
    } while (temp1 != pradziaCikl);
    cout<<endl;
}

void didesniuUz() {

    if (!pradziaCikl) {
        cout << "Ciklinis sarasas yra tuscias." << endl;
        return;
    }

    int skaicius = 0;
    ciklinisSarasas *temp = pradziaCikl;
    do {
        if (temp->duom > 15) {
            skaicius++;
        }
        temp = temp->kitas;
    } while (temp != pradziaCikl);

    cout<<"Skaiciu, didesniu uz 15, yra: "<<skaicius<<endl;
    cout<<endl;
}

void panaikintiMazUz() {
    cout<<"Pasirinkimas: Panaikinti ciklinio saraso elementus, mazesnius uz 10."<<endl;
    cout<<"Skaiciai, kurie bus panaikinti: "<<endl;

    ciklinisSarasas *temp = pradziaCikl, *pask = nullptr;
    bool firstIteration = true;

    do {
        if (temp->duom < 10) {
            cout<<temp->duom<<" ";

            if (temp == pradziaCikl) {
                // jeigu sarase yra tik vienas elementas
                if (pradziaCikl->kitas == pradziaCikl) {
                    pradziaCikl = nullptr;
                } else {
                    pradziaCikl = temp->kitas;
                    pask->kitas = pradziaCikl;
                }
            } else {
                pask->kitas = temp->kitas;
            }

            ciklinisSarasas *deleteTemp = temp;
            temp = temp -> kitas;
            delete deleteTemp;
        } else {
            pask = temp;
            temp = temp->kitas;
        }
        // Check if we have completed a full cycle
        if (temp == pradziaCikl && !firstIteration) {
            break;
        }
        firstIteration = false;
    } while (pradziaCikl != nullptr);
}


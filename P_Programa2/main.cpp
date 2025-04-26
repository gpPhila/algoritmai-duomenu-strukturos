/*
Sukurti dinaminį dvikryptį ciklinį sąrašą, realizuojant elemento įterpimo, pašalinimo,
spausdinimo bei paieškos funkcijas. Perkelti to sąrašo visus elementus į vienkryptį ciklinį
sąrašą, realizuojant jį kaip deką (įterpimas į priekį ar į galą, pašalinimas iš pradžios ar iš
galo).
*/

#include <iostream>
using namespace std;

struct dvikryptCiklinisSarasas {
    dvikryptCiklinisSarasas *pirmyn;
    int duom;
    dvikryptCiklinisSarasas *atgal;
};
dvikryptCiklinisSarasas *pradziaDvikCikl = nullptr;

struct vienkryptCiklinisSarasas {
    int duom;
    vienkryptCiklinisSarasas *kitas;
};
vienkryptCiklinisSarasas *pradziaVienCikl = nullptr, *pabaigaVienCikl = nullptr; //realizuotas kaip dekas

void iterpimas (dvikryptCiklinisSarasas*& pradziaDvikCikl);
void salinimas(dvikryptCiklinisSarasas*& pradziaDvikCikl);
void spausdinimas ();
void paieska();
void perkelimasIPradzia();
void perkelimasIPabaiga();

int main()
{
    int pasirinkimas;
    while (pasirinkimas !=7) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Iterpimas."<<endl;
        cout<<"2. Spausdinimas."<<endl;
        cout<<"3. Paieska."<<endl;
        cout<<"4. Salinimas."<<endl;
        cout<<"5. Visu elementu perkelimas i kito saraso pradzia."<<endl;
        cout<<"6. Visu elementu perkelimas i kito saraso pabaiga."<<endl;
        cout<<"7. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: iterpimas(pradziaDvikCikl);
            break;

            case 2: spausdinimas();
            break;

            case 3: paieska();
            break;

            case 4: salinimas(pradziaDvikCikl);
            break;

            case 7: cout<<"Jus isejote is meniu."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    return 0;
}

void iterpimas(dvikryptCiklinisSarasas*& pradziaDvikCikl) {
    int skaicius, reiksme;
    cout<<"Kiek elementu norite ivesti?"<<endl;
    cin>>skaicius;

    cout<<"Iveskite elementus (pro tarpa): "<<endl;
    for (int i = 0; i < skaicius; i++) {
        cin>>reiksme;
        dvikryptCiklinisSarasas *naujas = new dvikryptCiklinisSarasas{nullptr, reiksme, nullptr};
        if (pradziaDvikCikl == nullptr) {
            pradziaDvikCikl = naujas;
            naujas -> pirmyn = naujas;
            naujas -> atgal = naujas;
        } else {
            dvikryptCiklinisSarasas *pask = pradziaDvikCikl -> atgal;
            pask -> pirmyn = naujas;
            naujas -> atgal = pask;
            naujas -> pirmyn = pradziaDvikCikl;
            pradziaDvikCikl -> atgal = naujas;
        }
    }
}

void spausdinimas() {
    cout<<"Ciklinio saraso elementai:"<<endl;
    dvikryptCiklinisSarasas *temp = pradziaDvikCikl;
    do {
        cout << temp->duom << " ";
        temp = temp->pirmyn;
    } while (temp != pradziaDvikCikl);
    cout<<endl;
}

void paieska() {
    int elem;
    cout<<"Kokio elemento ieskome?"<<endl;
    cin>>elem;
    bool rastas = false;

        dvikryptCiklinisSarasas *temp = pradziaDvikCikl;
        do {
            if (temp -> duom == elem) {
                rastas = true;
                break;
            }
            temp = temp -> pirmyn;
        } while (temp != pradziaDvikCikl);

    if (rastas == true) {
        cout<<"Elementas buvo rastas!"<<endl;
    } else {
        cout<<"Tokio elemento nera sarase."<<endl;
    }
}

void salinimas(dvikryptCiklinisSarasas*& pradziaDvikCikl) {
    spausdinimas();
    int salinamas;
    cout<<"Iveskite, koki elementa norite pasalinti: ";
    cin>>salinamas;

    dvikryptCiklinisSarasas *temp = pradziaDvikCikl;
    do {
        if (temp -> duom == salinamas) {
            //vienintelis elementas
            if (temp == pradziaDvikCikl && temp -> pirmyn == pradziaDvikCikl) {
                delete temp;
                pradziaDvikCikl = nullptr;
            }
            //pirmas elementas
            else if (temp == pradziaDvikCikl) {
                temp->atgal -> pirmyn = temp -> pirmyn;
                temp->pirmyn -> atgal = temp -> atgal;
                pradziaDvikCikl = temp -> pirmyn;
                delete temp;
            } else {
                temp -> atgal -> pirmyn = temp -> pirmyn;
                temp -> pirmyn -> atgal = temp -> atgal;
                delete temp;
            }
            cout<<"Elementas buvo pasalintas!"<<endl;
            return;
        }
        temp = temp -> pirmyn;
    } while (temp != pradziaDvikCikl);
}

void perkelimasIPradzia(dvikryptCiklinisSarasas*& pradziaDvikCikl) {
    while (pradziaDvikCikl -> pirmyn != nullptr) {
        
    }
}

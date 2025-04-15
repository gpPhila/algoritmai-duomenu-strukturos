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
void salinimas();
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

    if (pradziaDvikCikl -> duom == elem) {
        cout<<"Elementas buvo rastas!"<<endl;
        return;
    }

    dvikryptCiklinisSarasas *temp = pradziaDvikCikl;
    do {

        temp = temp -> pirmyn;
    } while (temp != pradziaDvikCikl);
    cout<<endl;
}


#include <iostream>
#include <limits.h>
using namespace std;

/*
Sukurti steką, realizuotą kaip vienkryptis sąrašas. Sukurti funkcijas, kurios vykdo duomenų
įvedimą, bei pašalinimą. Realizuoti funkcijas, kurios:
a. 5 pašalintus elementus įrašys į dvikryptį sąrašą.
b. Dvikrypčiame sąraše sukeis vietomis didžiausią ir mažiausią elementą, o paskui
atspausdins ir pradinį ir sukeistą sąrašą.
c. Pašalins iš dvikrypčio sąrašo visus lyginius elementus bei parodys juos ekrane
*/

struct stekas {
    int duom;
    stekas *kitas;
};
stekas *pradziaStekas;

struct dvikryptSarasas {
    dvikryptSarasas *pirmyn;
    int duom;
    dvikryptSarasas *atgal;
};
dvikryptSarasas *pradzia = nullptr, *pabaiga = nullptr;

void stekoPildymas();
void stekoIsvedimas();
void salinimasIsSteko();
void isStekoISarasa();
void sukeitimasVietomis();
void pasalintiLyginius();

int main() {
    int pasirinkimas;
    while (pasirinkimas !=7) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Ivedimas i steka."<<endl;
        cout<<"2. Steko isdevimas."<<endl;
        cout<<"3. Elemento salinimas is steko."<<endl;
        cout<<"4. Perrasyti 5 elementus is steko i sarasa."<<endl;
        cout<<"5. Did. ir maz. elementu sukeitimas vietomis sarase."<<endl;
        cout<<"6. Pasalinti lyginius skaicius is saraso."<<endl;
        cout<<"7. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: stekoPildymas();
            break;
            case 2: stekoIsvedimas();
            break;
            case 3: salinimasIsSteko();
            break;
            case 4: isStekoISarasa();
            break;
            case 5: sukeitimasVietomis();
            break;
            case 6: pasalintiLyginius();
            break;
            case 7: cout<<"Viso gero."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera, bandykite dar karta."<<endl;
        }
    }
    return 0;
}

void stekoPildymas() {
    cout<<"Pasirinkimas: Ivedimas i steka."<<endl;
    cout << "Iveskite steko dydi: "<<endl;
    int stekoDydis;
    cin >> stekoDydis;
    cout << "Iveskite steko duomenys: "<<endl;

    for (int i = 0; i < stekoDydis; i++) {
        int elem;
        cin >> elem;

        stekas *naujas = new stekas{elem, pradziaStekas};
        pradziaStekas = naujas;
    }
    cout<<endl;
}


void stekoIsvedimas() {
    cout<<"Pasirinkimas: Steko isdevimas."<<endl;
    cout << "Steko duomenys: "<<endl;

    stekas *pr = pradziaStekas;
    while (pr !=NULL) {
        cout<< pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<endl;
}

void salinimasIsSteko() {
    cout<<"Pasirinkimas: Elemento salinimas is steko."<<endl;
    cout<<"Virsutinis steko elementas buvo panaikintas."<<endl;

    stekas *temp = pradziaStekas;
    pradziaStekas = pradziaStekas->kitas;

    delete temp;
    cout<<endl;
}

void isStekoISarasa() {
    cout<<"Pasirinkimas: Perrasyti 5 elementus is steko i sarasa."<<endl;
    for (int i = 0; i < 5; i++) {

        stekas *temp = pradziaStekas;
        pradziaStekas = pradziaStekas->kitas;

        dvikryptSarasas *naujas = new dvikryptSarasas{nullptr, temp->duom, nullptr};

        if (pradzia == nullptr) {
            pradzia = pabaiga = naujas;
        } else {
            pabaiga->pirmyn = naujas;
            naujas->atgal = pabaiga;
            pabaiga = naujas;
        }
        delete temp;
    }
    cout<<"Dvikrypcio saraso duomenys: "<<endl;
    dvikryptSarasas *temp = pradzia;
    while (temp) {
        cout<<temp->duom<<" ";
        temp = temp->pirmyn;
    }
    cout<<endl;
}

void sukeitimasVietomis() {
    cout<<"Pasirinkimas: Did. ir maz. elementu sukeitimas vietomis sarase."<<endl;

    cout<<"Dvikrypcio saraso duomenys pries elementu sukeitima: "<<endl;
    dvikryptSarasas *temp1 = pradzia;
    while (temp1) {
        cout<<temp1->duom<<" ";
        temp1 = temp1->pirmyn;
    }
    cout<<endl;

    dvikryptSarasas *temp = pradzia;
    dvikryptSarasas *maz = nullptr, *did = nullptr;
    int mazReiksme = INT_MAX, didReiksme = INT_MIN;

    //rasti maz ir did elementus
    while (temp != nullptr) {
        if (temp->duom < mazReiksme) {
            mazReiksme = temp->duom;
            maz = temp;
        }
        if (temp->duom > didReiksme) {
            didReiksme = temp->duom;
            did = temp;
        }
        temp = temp->pirmyn;
    }

    if (maz->atgal != nullptr) {
        maz->atgal->pirmyn = did;
    }
    if (maz->pirmyn != nullptr) {
        maz->pirmyn->atgal = did;
    }
    if (did->atgal != nullptr) {
        did->atgal->pirmyn = maz;
    }
    if (did->pirmyn != nullptr) {
        did->pirmyn->atgal = maz;
    }

    dvikryptSarasas *tempElem = maz->pirmyn;
    maz->pirmyn = did->pirmyn;
    did->pirmyn = tempElem;

    tempElem = maz->atgal;
    maz->atgal = did->atgal;
    did->atgal = tempElem;

    // jeigu reikia pakeisti pradzia/pabaiga
    if (maz == pradzia) {
        pradzia = did;
    } else if (did == pradzia) {
        pradzia = maz;
    }
    if (maz == pabaiga) {
        pabaiga = did;
    } else if (did == pabaiga) {
        pabaiga = maz;
    }

    cout<<"Dvikrypcio saraso duomenys po elementu sukeitimo: "<<endl;
    dvikryptSarasas *temp2 = pradzia;
    while (temp2) {
        cout<<temp2->duom<<" ";
        temp2 = temp2->pirmyn;
    }
    cout<<endl;
}

void pasalintiLyginius() {
    cout<<"Pasirinkimas: Pasalinti lyginius skaicius is saraso."<<endl;
    cout<<"Lyginiai skaiciai kurie bus pasalinti:"<<endl;
    dvikryptSarasas *temp = pradzia;

    while (temp) {
        if (temp->duom % 2 == 0) {
            cout<<temp->duom<<" ";
            dvikryptSarasas *salintiElem = temp;
            temp = temp->pirmyn;

            if (salintiElem == pradzia) {
                pradzia = salintiElem->pirmyn;
                if (pradzia) pradzia->atgal = nullptr;
            } else if (salintiElem == pabaiga) {
                pabaiga = salintiElem->atgal;
                if (pabaiga) pabaiga->pirmyn = nullptr;
            } else {
                salintiElem->atgal->pirmyn = salintiElem->pirmyn;
                salintiElem->pirmyn->atgal = salintiElem->atgal;
            }

            delete salintiElem;
        } else {
            temp = temp->pirmyn;
        }
    }
    cout<<endl;
    cout<<"Atnaujintas dvikryptis sarasas: "<<endl;
    dvikryptSarasas *temp1 = pradzia;
    while (temp1) {
        cout<<temp1->duom<<" ";
        temp1 = temp1->pirmyn;
    }
    cout<<endl;
}
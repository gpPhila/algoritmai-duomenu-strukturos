#include <iostream>
using namespace std;

struct dvikryptSarasas {
    dvikryptSarasas *pirmyn;
    int duom;
    dvikryptSarasas *atgal;
};
dvikryptSarasas *pradzia = nullptr, *pabaiga = nullptr;

struct ciklinisSarasas {
    ciklinisSarasas *pirmyn;
    int duom;
    ciklinisSarasas *atgal;
};
ciklinisSarasas *pradziaCikl = nullptr;

struct stekas {
    int duom;
    stekas *kitas;
};

stekas *pradziaStekas;

void lygSkaiciai (dvikryptSarasas *pradzia);
void ciklSarasoSpaudinimas (ciklinisSarasas *pradziaCikl);
void nelygSkaiciai (dvikryptSarasas *pradzia);
void stekoDuomenuSalinimas (stekas *pradziaStekas);

int main()
{
    int skaicius;
    int reiksme;
    cout<<"Iveskite elementu skaiciu:"<<endl;
    cin>>skaicius;
    cout<<"Iveskite "<<skaicius<<" elementu reiksmes:"<<endl;

    for (int i = 0; i < skaicius; i++) {
        cin>>reiksme;
        dvikryptSarasas *naujas = new dvikryptSarasas{nullptr, reiksme, nullptr};

        if (pradzia == nullptr) {
            pradzia = pabaiga = naujas;
        } else {
            pabaiga -> pirmyn = naujas;
            naujas -> atgal = pabaiga;
            pabaiga = naujas;
        }
    }

    lygSkaiciai(pradzia);
    ciklSarasoSpaudinimas(pradziaCikl);
    nelygSkaiciai(pradzia);
    stekoDuomenuSalinimas(pradziaStekas);
    return 0;
}

void lygSkaiciai (dvikryptSarasas *pradzia) {
    dvikryptSarasas *temp = pradzia;

    while (temp) {
        if (temp->duom % 2 == 0) {
            ciklinisSarasas *naujasCikl = new ciklinisSarasas{nullptr, temp->duom};

            if (pradziaCikl == nullptr) {
                pradziaCikl = naujasCikl;
                pradziaCikl->pirmyn = pradziaCikl;
            } else {
                ciklinisSarasas *last = pradziaCikl;
                while (last->pirmyn != pradziaCikl) {
                    //making sure it doesn't loop forever
                    last = last->pirmyn;
                    //iesko paskutinio node
                }
                last->pirmyn = naujasCikl;
                naujasCikl->pirmyn = pradziaCikl;
            }
        }
        temp = temp->pirmyn;
    }
}

void ciklSarasoSpaudinimas(ciklinisSarasas *pradziaCikl) {
    cout<<"Ciklinis sarasas:"<<endl;

    ciklinisSarasas *temp = pradziaCikl;
    do {
        cout << temp->duom << " ";
        temp = temp->pirmyn;
    } while (temp != pradziaCikl);
    cout<<endl;
}

void nelygSkaiciai(dvikryptSarasas *pradzia) {
    dvikryptSarasas *elem = pradzia;
    while (elem) {
        if (elem->duom % 2 != 0) {
            stekas *newElem = new stekas;
            newElem->duom = elem->duom;
            newElem->kitas = pradziaStekas;
            pradziaStekas = newElem;
        }
        elem = elem->pirmyn;
    }
}

void stekoDuomenuSalinimas(stekas *pradziaStekas) {
    cout<<"Steko duomenys pries salinima:"<<endl;

    while (pradziaStekas) {
        cout << pradziaStekas->duom << " ";
        stekas *temp = pradziaStekas;
        pradziaStekas = pradziaStekas->kitas;
        delete temp;
    }
    cout << endl;
    cout<<"Steko duomenys buvo pasalinti."<<endl;
}


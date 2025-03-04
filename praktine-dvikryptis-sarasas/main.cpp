#include <iostream>
using namespace std;

struct dviKrypSarasas{
  dviKrypSarasas *pirmyn;
  int duom;
  dviKrypSarasas *atgal;
};
dviKrypSarasas *pradzia = nullptr , *pabaiga = nullptr;

int main() {
    int skaicius;
    int reiksme;
    cout<<"Iveskite elementu skaiciu:"<<endl;
    cin>>skaicius;
    cout<<"Iveskite "<<skaicius<<" elementu reiksmes:"<<endl;

//------------------duomenu ivedimas---------------------------

    for (int i = 0; i < skaicius; i++) {
        cin>>reiksme;
        dviKrypSarasas *naujas = new dviKrypSarasas{nullptr, reiksme, nullptr};

        if (pradzia == nullptr) {
            pradzia = pabaiga = naujas;
        } else {
            pabaiga -> pirmyn = naujas;
            naujas -> atgal = pabaiga;
            pabaiga = naujas;
        }
    }

    //-------------------duomenu isvedimas----------------------------
    cout<<"Saraso duomenys yra: "<<endl;
    dviKrypSarasas *pr = pradzia;
    while (pr) {
        cout<<pr->duom<<" ";
        pr = pr->pirmyn;
    }
    cout<<endl;

    //--------------------------elementu iterpimas---------------------------------

    cout<<"PRIES koki elementa norite iterpti nauja?"<<endl;
    int priesElem, naujaReiksme;
    cin>>priesElem;
    cout<<"Iveskite naujo elemento reiksme: "<<endl;
    cin>>naujaReiksme;

    dviKrypSarasas *temp = pradzia;
    while (temp && temp->duom != priesElem) {
        //keep replaying the loop for as long as "temp"
        //and for as long as "duom" isn't "priesElem"
        temp = temp->pirmyn;
    }

    dviKrypSarasas *naujasPries = new dviKrypSarasas{temp, naujaReiksme, temp};
    if (temp->atgal) {
        temp->atgal->pirmyn = naujasPries;
    } else {
        pradzia=naujasPries;
    }

    cout<<"Atnaujintas sarasas:"<<endl;
    pr = pradzia;
    while (pr) {
        cout<<pr->duom<<" ";
        pr = pr->pirmyn;
    }
    cout<<endl;
    return 0;
}

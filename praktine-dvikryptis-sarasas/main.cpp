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

    //--------------------------elementu iterpimas PRIES---------------------------------

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

    dviKrypSarasas *naujasPries = new dviKrypSarasas{temp, naujaReiksme, temp->atgal};
    //jeigu buvo 2 ir 3 ir norim iterpti 5, dabar temp->atgal =2, todel darome atgal=[temp->atgal]
    if (temp->atgal) {
        //patikrina ar yra elementas pries temp
        temp->atgal->pirmyn = naujasPries;
        //[temp->atgal] is basically 2
        //pirmyn dvejeto rodys i naujasPries
        //atnaujina pirmyn rodykle kad ji rodytu i naujaspries
    } else {
        pradzia=naujasPries;
    }
    temp->atgal = naujasPries;
    //we stole atgal from the temp element, so it needs to point somewhere

    cout<<"Atnaujintas sarasas:"<<endl;
    pr = pradzia;
    while (pr) {
        cout<<pr->duom<<" ";
        pr = pr->pirmyn;
    }
    cout<<endl;

    //--------------------------elementu iterpimas PO---------------------------------

    cout<<"PO kokio elemento norite iterpti nauja?"<<endl;
    int poElem, pnaujaReiksme;
    cin>>poElem;
    cout<<"Iveskite naujo elemento reiksme: "<<endl;
    cin>>pnaujaReiksme;

    dviKrypSarasas *tempPo = pradzia;
    while (tempPo && tempPo->duom != poElem) {
        //keep replaying the loop for as long as "tempPo" is alive lol
        //and for as long as "duom" isn't "poElem"
        tempPo = tempPo->pirmyn;
    }

    dviKrypSarasas *naujasPo = new dviKrypSarasas{tempPo->pirmyn, pnaujaReiksme, tempPo};
    if (tempPo->pirmyn) {
        tempPo->pirmyn->atgal = naujasPo;
    } else {
        pabaiga=naujasPo;
    }
    tempPo->pirmyn=naujasPo;

    cout<<"Atnaujintas sarasas:"<<endl;
    pr = pradzia;
    while (pr) {
        cout<<pr->duom<<" ";
        pr = pr->pirmyn;
    }
    cout<<endl;

    return 0;
}

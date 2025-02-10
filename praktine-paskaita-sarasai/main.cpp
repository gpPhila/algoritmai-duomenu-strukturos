#include <iostream>
using namespace std;

struct sarasas {
    int duom;
    sarasas *kitas;
};

void iterpti_pradzia (int elementas);
int pasalinti_elementa_pradzia();
int pasalinti_elementa_pabaiga();
void iterpti_pabaiga(int elementas);
void spausdinti_sarasa();
sarasas *pradzia, *pabaiga, *elem;

int main()
{
    int reiksme;
    pradzia=NULL; pabaiga=NULL;
    elem= new sarasas();

    cout<<"Iveskite skaiciu: "<<endl;
    cin>>reiksme;
    elem->duom=reiksme;
    elem->kitas=NULL;
    pradzia=pabaiga=elem;

    for (int i=1;i<=4;i++) {
        cout<<"Iveskite skaiciu: "<<endl;
        cin>>reiksme;
        iterpti_pabaiga(reiksme);
    }

    cout<<"Ivestas sarasas su 5 elementais iterptais i pradzia:"<<endl;
    spausdinti_sarasa();

    return 0;
}

/*
void iterpti_pradzia (int elementas)
{
    sarasas *el= new sarasas();
    el->duom=elementas;
    el->kitas=pradzia;
    pradzia=el;
}
*/

void iterpti_pabaiga (int elementas) {
    sarasas *el= new sarasas(); //sukuriame/pridedame nauja elementa
    el->duom=elementas; //priskiriame elementui reiksme
    el->kitas=NULL; //rodykle = NULL, arba saraso pabaiga
    pabaiga->kitas=el; //link'iname paskutini elementa prie naujo
    pabaiga=el; //atnaujiname pabaiga kad rodykle point'u i nauja elementa
}

void spausdinti_sarasa() {
   sarasas *pr=pradzia;
    //t.y. prasideda nuo saraso pradzios
    while (pr !=NULL) {
    cout<< pr->duom<<" ";
        pr=pr->kitas;
    }
}

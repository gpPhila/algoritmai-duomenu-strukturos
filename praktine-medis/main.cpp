#include <iostream>
#include <regex>
using namespace std;

struct medis {
    string data;
    medis *kaire;
    medis *desine;
};

medis *naujas_elementas(string pavarde) {
    medis *p;
    p = new medis;
    p -> data = pavarde;
    p -> desine = NULL;
    p -> kaire = NULL;
    return p;
}

void iterpimas (medis*& saknis);
void paieska ();
void spausdinimas (medis *saknis);
void salinimas ();

int main() {
    medis* saknis = NULL;
    int pasirinkimas;
    while (pasirinkimas !=5) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Ivedimas."<<endl;
        cout<<"2. Paieska."<<endl;
        cout<<"3. Spausdinimas."<<endl;
        cout<<"4. Salinimas"<<endl;
        cout<<"5. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: iterpimas(saknis);
            break;

            case 3: spausdinimas(saknis);
            break;

            default: cout<<"Oopsie woopsie."<<endl;
        }
    }
    return 0;
}

void iterpimas(medis*& saknis) {
    string pavarde;
    cout<<"Iveskite pavarde: ";
    cin>>pavarde;

    if (saknis ==NULL) {
        saknis = naujas_elementas(pavarde);
        return;
    }

    if (pavarde < saknis->data) {
        iterpimas(saknis->kaire);
    } else {
        iterpimas(saknis->desine);
    }
}

void spausdinimas(medis *saknis) {
    if (saknis != NULL) {
        spausdinimas(saknis->kaire);
        cout<<saknis->data<<endl;
        spausdinimas(saknis->desine);
    }
}


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
void paieska (medis *saknis);
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

            case 2: paieska(saknis);
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

    medis* naujas = naujas_elementas(pavarde);

    //jeigu pavardziu dar nera, pirma ivesta pavarde tampa saknimi
    if (saknis ==NULL) {
        saknis = naujas;
        return;
    }

    //jeigu saknis buvo pere, tai dabar dabartinis - pere
    medis* dabartinis = saknis;
    medis* tevai = NULL;

    //ieskos laisva vieta (kaire arba desine, laisva vieta vaikui irasyti nzn)
    while (dabartinis != NULL) {

        //pridedant nauja pavarde, pries tai buvusi tampa tevu
        tevai = dabartinis;
        if (pavarde < dabartinis->data) {
            dabartinis = dabartinis->kaire;
        } else {
            dabartinis = dabartinis->desine;
        }
    }

    //pagaliau prideda pavarde i medi
    if (pavarde < tevai->data) {
        tevai->kaire = naujas;
    } else {
        tevai->desine = naujas;
    }
}

void spausdinimas(medis *saknis) {
    if (saknis != NULL) {
        spausdinimas(saknis->kaire);
        cout<<saknis->data<<endl;
        spausdinimas(saknis->desine);
    }
}

void paieska (medis *saknis) {

    if (saknis == NULL) {
        cout<<"Jokiu pavardziu dar nebuvo ivesta."<<endl;
        return;
    }

    string ieskPav;
    cout<<"Kokia pavarde ieskome?"<<endl;
    cin>>ieskPav;

    medis* dabartinis = saknis;
    medis* tevai = NULL;

    while (dabartinis != NULL) {

        if (ieskPav == dabartinis->data) {
            cout << "Pavarde rasta!" << endl;
            return;
        }

        tevai = dabartinis;
        if (ieskPav < dabartinis -> data) {
           dabartinis = dabartinis -> kaire;
        } else {
            dabartinis = dabartinis -> desine;
        }
    }

    cout<<"Pavardes nera."<<endl;
}

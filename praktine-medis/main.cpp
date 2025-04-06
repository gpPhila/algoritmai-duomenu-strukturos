#include <iostream>
#include <regex>
#include <string>
using namespace std;

struct eile {
    string duom;
    eile* pradzia;
    eile* pabaiga;
};
eile* q = NULL;

struct dekas {
    string duom;
    dekas *pries;
    dekas *kitas;
};
dekas* pradzia = NULL;

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

medis *rasti_max(medis *saknis) {
    if (saknis==NULL) {
        return NULL;
    } else if (saknis -> desine!=NULL) {
        return rasti_max(saknis -> desine);
    }
    return saknis;
}

void iterpimas (medis*& saknis);
void paieska (medis *saknis);
void spausdinimas (medis *saknis);
void salinimas (medis*& saknis);
void perrasymasIDeka (medis*& saknis, dekas*& pradzia);
void spausdintiDeka (dekas* pradzia);
void perrasymasIDekoPabaiga (medis*& saknis, dekas*& pradzia);
void isMedzioIEile (medis*& saknis, eile*& q);
void spausditiEIle (eile* q);

int main() {
    medis* saknis = NULL;
    int pasirinkimas;
    while (pasirinkimas !=10) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Ivedimas"<<endl;
        cout<<"2. Paieska"<<endl;
        cout<<"3. Spausdinimas"<<endl;
        cout<<"4. Salinimas"<<endl;
        cout<<"5. Nuo A iki L -> dekas"<<endl;
        cout<<"6. Nuo R iki Z -> dekas"<<endl;
        cout<<"7. Spausdinti deka"<<endl;
        cout<<"8. Pasalinti nuo M iki P, ir -> eile"<<endl;
        cout<<"9. Spausdinti eile"<<endl;
        cout<<"10. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: iterpimas(saknis);
            break;

            case 2: paieska(saknis);
            break;

            case 3: spausdinimas(saknis);
            break;

            case 4: salinimas(saknis);
            break;

            case 5: perrasymasIDeka(saknis,pradzia);
                    spausdintiDeka(pradzia);
            break;

            case 6: perrasymasIDekoPabaiga(saknis, pradzia);
                    spausdintiDeka(pradzia);
            break;

            case 7: spausdintiDeka(pradzia);
            break;

            case 8: isMedzioIEile(saknis, q);
                    spausditiEIle(q);
            break;

            case 9: spausditiEIle(q);
            break;

            case 10: cout<<"Jus isejote is meniu. Viso gero!"<<endl;
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

    while (dabartinis != NULL) {

        if (ieskPav == dabartinis->data) {
            cout << "Pavarde rasta!" << endl;
            return;
        }

        if (ieskPav < dabartinis -> data) {
           dabartinis = dabartinis -> kaire;
        } else {
            dabartinis = dabartinis -> desine;
        }
    }

    cout<<"Pavardes nera."<<endl;
}

void salinimas (medis*& saknis) {
    if (saknis == NULL) {
        cout<<"Jokiu pavardziu dar nebuvo ivesta."<<endl;
        return;
    }

    string pasalinPav;
    cout<<"Kokia pavarde norite pasalinti?"<<endl;
    cin>>pasalinPav;

    medis* dabartinis = saknis;
    medis* tevas = NULL;

    while (dabartinis != NULL) {
        if (pasalinPav == dabartinis->data) {
            //jeigu elementas neturi vaiku
            if (dabartinis -> kaire == NULL && dabartinis -> desine == NULL) {
                if (dabartinis==saknis) {
                    delete saknis;
                    saknis = NULL;
                } else if (tevas->kaire == dabartinis) {
                    delete dabartinis;
                    tevas->kaire = NULL;
                } else {
                    delete dabartinis;
                    tevas->desine = NULL;
                }
                cout<<"blah"<<endl;
                cout<<"Pavarde buvo pasalinta!"<<endl;
                return;
            }

            /*
            //jeigu yra bent vienas vaikas kaireje puseje
                if (dabartinis -> kaire !=NULL && dabartinis -> desine == NULL) {
                    if (dabartinis == saknis) {
                        medis* temp = saknis;
                        saknis = saknis->kaire;
                        delete temp;
                    } else if (tevas->kaire == dabartinis) {
                        tevas->kaire = dabartinis->kaire;
                        delete dabartinis;
                    } else {
                        tevas->desine = dabartinis->kaire;
                    }
                    cout<<"Pavarde buvo pasalinta!"<<endl;
                    return;
                }

            //jeigu yra bent vienas vaikas desineje puseje
            if (dabartinis -> kaire == NULL && dabartinis -> desine != NULL) {
                if (dabartinis == saknis) {
                    medis* temp = saknis;
                    saknis = saknis->desine;
                    delete temp;
                } else if (tevas->desine == dabartinis) {
                    tevas->desine = dabartinis->desine;
                    delete dabartinis;
                } else {
                    tevas->kaire = dabartinis->desine;
                }
                cout<<"Pavarde buvo pasalinta!"<<endl;
                return;
            }
            */

            //jeigu yra bent vienas vaikas
            else if (dabartinis->kaire == NULL || dabartinis->desine == NULL) {

                //paaiskinimas: condition ? expression_if_true : expression_if_false;
                medis* temp = (dabartinis->kaire != NULL) ? dabartinis->kaire : dabartinis->desine;
                cout<<"Naikinama pavarde: "<<dabartinis->data<<endl;

                if (dabartinis == saknis) {
                    saknis = temp;
                } else if (tevas->kaire == dabartinis) {
                    tevas->kaire = temp;
                } else {
                    tevas->desine = temp;
                }
                delete dabartinis;
                // PRIDETI JEIGU DU VAIKAI YRA
                cout << "Pavarde buvo pasalinta!" << endl;
                return;
            }

            //jeigu elementas turi du vaikus
            else {
                medis* maxKaireje = rasti_max(dabartinis->kaire);
                string temp = maxKaireje->data;

                medis* tempTevas = dabartinis;
                medis* tempDabartinis = dabartinis->kaire;

                if (tempDabartinis->data == temp) {
                    dabartinis->kaire = tempDabartinis->kaire;
                    delete tempDabartinis;
                } else {

                    while (tempDabartinis->desine != NULL && tempDabartinis->desine->data != temp) {
                        tempTevas = tempDabartinis;
                        tempDabartinis = tempDabartinis->desine;
                    }

                    medis* naikinti = tempDabartinis->desine;
                    tempDabartinis->desine = naikinti->kaire;
                    delete naikinti;
                }
                dabartinis->data = temp;

                cout<<"Pavarde buvo pasalinta yahoo."<<endl;
                return;
            }
        }

        tevas = dabartinis;
        if (pasalinPav < dabartinis -> data) {
            dabartinis = dabartinis -> kaire;
        } else {
            dabartinis = dabartinis -> desine;
        }
    }
    cout << "Tokios pavardes nebuvo ivesta." << endl;
}

void perrasymasIDeka(medis*& saknis, dekas*& pradzia) {
    if (saknis ==NULL) {
        return;
    }

    //kaire-saknis-desine
    perrasymasIDeka(saknis->kaire, pradzia);

    char pirmaRaide = toupper(saknis->data[0]);
    if (pirmaRaide >= 'A' && pirmaRaide <= 'L') {
        //kuriamas naujas deko elementas
        dekas* naujas = new dekas;
        naujas->duom = saknis->data;
        naujas->pries = NULL;
        naujas->kitas = pradzia;

        if (pradzia != NULL) {
            pradzia->pries = naujas;
        }
        pradzia = naujas;
    }
    perrasymasIDeka(saknis->desine, pradzia);
}

void spausdintiDeka(dekas* pradzia) {
    cout << "Deko elementai:" << endl;
    dekas* temp = pradzia;
    while (temp != NULL) {
        cout << temp->duom << " ";
        temp = temp->kitas;
    }
    cout << endl;
}

void perrasymasIDekoPabaiga(medis *&saknis, dekas *&pradzia) {
    if (saknis ==NULL) {
        return;
    }
    perrasymasIDekoPabaiga(saknis->kaire, pradzia);

    //atskirai kuriamas naujas elementas ir veliau pridedamas i deko pabaiga
    char pirmaRaide = toupper(saknis->data[0]);
    if (pirmaRaide >= 'R' && pirmaRaide <= 'Z') {
        dekas* naujas = new dekas;
        naujas->duom = saknis->data;
        naujas->pries = NULL;
        naujas->kitas = NULL;

        if (pradzia == NULL) {
            pradzia = naujas;
        } else {
            dekas* temp = pradzia;
            while (temp->kitas !=NULL) {
                temp = temp->kitas;
            }
            temp->kitas = naujas;
            naujas->pries = temp;
        }
    }
    perrasymasIDekoPabaiga(saknis->desine, pradzia);
}

//SITAI FUNKCIJAS BUTINAS DEBUGGING
void isMedzioIEile (medis*& saknis, eile*& q) {
    if (saknis ==NULL) {
        return;
    }
    isMedzioIEile(saknis->kaire, q);
    char pirmaRaide = toupper(saknis->data[0]);
    if (pirmaRaide >= 'M' && pirmaRaide <= 'P') {
        eile* naujas = new eile;
        naujas->duom = saknis->data;
        naujas->pradzia = NULL;
        naujas->pabaiga = NULL;

        if (q == NULL) {
            q = naujas;
        }
        else {
            eile* temp = q;
            while (temp->pabaiga != NULL) {
                temp = temp->pabaiga;
            }
            temp->pabaiga = naujas;
            naujas->pradzia = temp;
        }

        medis* temp = saknis;
        if (saknis->kaire == NULL && saknis->desine == NULL) {
            saknis = NULL;
        } else if (saknis->kaire == NULL || saknis->desine == NULL) {
            saknis = saknis->kaire != NULL ? saknis->kaire : saknis->desine;
        } else {
            medis* maxKaireje = rasti_max(saknis->kaire);
            saknis->data = maxKaireje->data;
            isMedzioIEile(saknis->kaire, q);
        }
        delete temp;
    }
    isMedzioIEile(saknis->desine, q);
}

void spausditiEIle(eile *q) {
    eile* temp = q;
    cout<<"Eiles elementai: ";
    while (temp != NULL) {
        cout << temp->duom << " ";
        temp = temp->pabaiga;
    }
    cout<<endl;
}

#include <iostream>

using namespace std;

int main() {
    int masyvoDydis;
    cout << "Iveskite masyvo dydi:" << endl;
    cin>>masyvoDydis;

    int masyvas1[masyvoDydis];
    int skaicius;
    cout<<"Iveskite masyvo duomenis (per tarpa):"<<endl;

    for (int i = 0; i < masyvoDydis; i++) {
        cin>>skaicius;
        masyvas1[i] = skaicius;
    }

    cout<<"Masyvo duomenys: "<<endl;
    for (int i = 0; i < masyvoDydis; i++) {
        cout<<masyvas1[i]<<" ";
    }
    cout<<endl;

    //------------------1 uzduotis-----------------------------
    int neigSkaciuSuma = 0;
    for (int i = 0; i < masyvoDydis; i++) {
        if (masyvas1[i] < 0) {
            neigSkaciuSuma += masyvas1[i];
        }
    }
    cout<<"Neigiamu skaiciu suma: "<<neigSkaciuSuma<<endl;

    int didElementas = masyvas1[0];
    int mazElementas = masyvas1[0];
    int didIndex = 0, mazIndex = 0;
    for (int i = 0; i < masyvoDydis; i++) {
        if (masyvas1[i] > didElementas) {
            didElementas = masyvas1[i];
            didIndex = i;
        }
    }
    for (int i = 0; i < masyvoDydis; i++) {
        if (masyvas1[i] < mazElementas) {
            mazElementas = masyvas1[i];
            mazIndex = i;
        }
    }

    cout << "Didziausias elementas: " << didElementas << " (Indeksas: " << didIndex << ")" << endl;
    cout << "Maziausias elementas: " << mazElementas << " (Indeksas: " << mazIndex << ")" << endl;

    if (didIndex > mazIndex) swap(didIndex, mazIndex); //kad butu teisingas order

    cout<<"(Jeigu) atnaujinti indeksai: "<<endl;
    cout << "Didziausias elementas: " << didElementas << " (Indeksas: " << didIndex << ")" << endl;
    cout << "Maziausias elementas: " << mazElementas << " (Indeksas: " << mazIndex << ")" << endl;

    int sandauga = 1;
    if (didIndex + 1 == mazIndex) {
        cout << "Nera elementu tarp didziausio ir maziausio." << endl;
    } else {
        for (int i = didIndex + 1; i < mazIndex; i++) {
            sandauga *= masyvas1[i];
        }
        cout << "Sandauga elementu tarp didziausio ir maziausio: " << sandauga << endl;
    }

    for (int i = 0; i < masyvoDydis - 1; i++) {
        for (int j = 0; j < masyvoDydis - i - 1; j++) {
            if (masyvas1[j] > masyvas1[j + 1]) {
                swap(masyvas1[j], masyvas1[j + 1]);
            }
        }
    }

    cout << "Surusiuotas masyvas didejimo tvarka: ";
    for (int i = 0; i < masyvoDydis; i++) {
        cout << masyvas1[i] << " ";
    }
    cout << endl;
    return 0;
}

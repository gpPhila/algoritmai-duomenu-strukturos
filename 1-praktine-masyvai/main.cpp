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
    for (int i = 0; i < masyvoDydis; i++) {
        if (masyvas1[i] > didElementas) {
            didElementas = masyvas1[i];
        }
    }
    for (int i = 0; i < masyvoDydis; i++) {
        if (masyvas1[i] < mazElementas) {
            mazElementas = masyvas1[i];
        }
    }
    cout<<didElementas<<" "<<mazElementas<<endl;
    return 0;
}

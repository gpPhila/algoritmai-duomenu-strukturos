/*
Daugianaris "P" su sveikais koeficientais galima atvaizduoti kaip sąrašą ir, jei elementas ai=0, tai jį galima į
sąrašą ir neįvesti.
Sukurti loginę funkciją Ivesti(P), kuri įveda daugianarį iš tekstinio failo.
*/

#include <iostream>
#include <fstream>

using namespace std;

void daugianIvedimas ();
bool ivesti();

int main () {
    int pasirinkimas;
    while (pasirinkimas !=3) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Daugianariu ivedimas i tekstini faila."<<endl;
        cout<<"2. ."<<endl;
        cout<<"3. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                daugianIvedimas();
            break;

            case 3:
                cout<<"Jus isejote."<<endl;
            break;

            default:
                cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    return 0;
}

void daugianIvedimas () {
    int k, skaicius, laipsnis;
    ofstream failas("daugianaris.txt");

    cout<<"Kiek kartu norite ivesti?"<<endl;
    cin>>k;

    for (int i = 0; i < k; i++) {
        cout<<"Iveskite "<<i+1<<" elemento skaiciu: "<<endl;
        cin>>skaicius;
        cout<<"Iveskite "<<i+1<<" elemento lapsni: "<<endl;
        cin>>laipsnis;
        failas << skaicius << " " << laipsnis << endl;
    }
    failas.close();
}
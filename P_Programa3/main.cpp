/*
Sukurti sąrašą, sudarytą iš atsitiktinių skaičių. Apskaičiuoti sumą elementų, esančių tarp
mažiausio ir didžiausio elemento.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct sarasas {
    int duom;
    sarasas *kitas;
};
sarasas *pradzia = nullptr, *pabaiga = nullptr;

void ivedimas();
void suma();

int main() {
    int pasirinkimas;
    while (pasirinkimas !=3) {
        cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
        cout<<"1. Sukurti sarasa, sudaryta is atsitiktiniu skaiciu."<<endl;
        cout<<"2. Apskaiciuoti suma elementu, esanciu tarp maziausio ir didziausio elementu."<<endl;
        cout<<"3. Iseiti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: ivedimas();
            break;

            case 2: suma();
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

void ivedimas () {
    int kiekis;
    cout<<"Kiek skaiciu turi buti ivesta i sarasa?"<<endl;
    cin>>kiekis;

    srand(time(0)); //reset'ina skaiciu seka, be jo po kiekvieno programos iskvietimo butu tie patys skaiciai

    for (int i = 0; i < kiekis; i++) {
            int atsitiktinisSk = rand() % 100 + 1; //nuo 1 iki 100

            sarasas *naujas = new sarasas;
            naujas->duom = atsitiktinisSk;
            naujas->kitas = nullptr;

             if (pradzia == nullptr) {
                pradzia = pabaiga = naujas;
            } else {
                pabaiga->kitas = naujas;
                pabaiga = naujas;
            }
    }

        cout << "Atsitiktiniu skaiciu sarasas: ";
        sarasas *temp = pradzia;
        while (temp) {
            cout << temp->duom << " ";
            temp = temp->kitas;
        }
        cout << endl;
}

void suma () {
    int did, maz;
    sarasas *temp = pradzia;
    did = pradzia-> duom;
    maz = pradzia->duom;

    while (temp) {
        if (temp -> duom > did) {
            did=temp-> duom;
        }
        if (temp -> duom < maz) {
            maz=temp-> duom;
        }
        temp = temp-> kitas;
    }

    cout<<"Didziausias elementas: "<<did<<endl;
    cout<<"Maziausias elementas: "<<maz<<endl;

    sarasas *pradeti =nullptr, *baigti =nullptr;

    temp = pradzia;
    while (temp) {
        if (!pradeti && (temp->duom == maz || temp->duom == did)) {
            pradeti = temp;
        } else if (pradeti && (temp->duom == maz || temp->duom == did) && temp->duom != pradeti->duom) {
            baigti = temp;
            break;
        }
        temp = temp->kitas;
    }

    int suma = 0;
    temp = pradeti->kitas;
    while (temp && temp != baigti) {
        suma += temp->duom;
        temp = temp->kitas;
    }

    cout<<"Suma tarp elementu "<<pradeti->duom<<" ir "<<baigti->duom<<": "<<suma<<endl;
}
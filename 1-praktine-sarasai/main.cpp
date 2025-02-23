#include <iostream>
using namespace std;

struct sarasas1 {
    int duom;
    sarasas1 *kitas;
};

struct sarasas2 {
    int duom;
    sarasas2 *kitas;
};

void sortDescending(sarasas1 *&pradzia) {

    bool swapped;
    do {
        swapped = false;
        sarasas1 *temp = pradzia;
        while (temp->kitas) {
            if (temp->duom < temp->kitas->duom) { // Swap if out of order
                swap(temp->duom, temp->kitas->duom);
                swapped = true;
            }
            temp = temp->kitas;
        }
    } while (swapped);
}

int main() {
    //---------------------------1 uzd-----------------------------------
    int sarasas1Dydis;
    cout << "Iveskite saraso dydi: "<<endl;
    cin >> sarasas1Dydis;

    sarasas1 *pradzia = nullptr, *pabaiga = nullptr;

    cout << "Iveskite saraso elementus: ";
    for (int i = 0; i < sarasas1Dydis; i++) {
        int skaicius;
        cin >> skaicius;

        sarasas1 *naujas = new sarasas1{skaicius, nullptr};

        if (!pradzia) {
            pradzia = naujas;
        } else {
            pabaiga->kitas = naujas;
        }
        pabaiga = naujas;
    }

    ///elementu isvedimas
    cout << "Saraso elementai: ";
    sarasas1 *temp = pradzia; //temp parodo kad pradesim nuo pradzios, ty rodykle i pirma elementa
    while (temp) {
        cout << temp->duom << " "; //rodykle i elementa
        temp = temp->kitas; //paima sekancio elemento adresa, tokiu budu tampa rodykle i sekanti elementa
    }
    cout << endl;

    bool nemazejantiSeka = true;
    sarasas1 *tempSeka = pradzia;

    while (tempSeka->kitas) { //sustabdo kai tempSeka = null
        if (tempSeka->duom > tempSeka->kitas->duom) {
            nemazejantiSeka = false;
            break;
        }
        tempSeka = tempSeka->kitas;
    }

    if (nemazejantiSeka) { //jeigu bool kint liko true, tada:
        cout << "Seka YRA nemazejanti." << endl;
    } else {
        cout << "Seka NERA nemazejanti." << endl;
        sortDescending(pradzia);
    }

    /// Spausdiname surikiuota sarasa
    cout << "Surikiuotas sarasas: ";
    temp = pradzia;
    while (temp) {
        cout << temp->duom << " ";
        temp = temp->kitas;
    }
    cout << endl;

    return 0;
}

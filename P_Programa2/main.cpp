/*
Sukurti dinaminį dvikryptį ciklinį sąrašą, realizuojant elemento įterpimo, pašalinimo,
spausdinimo bei paieškos funkcijas. Perkelti to sąrašo visus elementus į vienkryptį ciklinį
sąrašą, realizuojant jį kaip deką (įterpimas į priekį ar į galą, pašalinimas iš pradžios ar iš
galo).
*/

#include <iostream>
using namespace std;

struct dvikryptCiklinisSarasas {
    dvikryptCiklinisSarasas *pirmyn;
    int duom;
    dvikryptCiklinisSarasas *atgal;
};
dvikryptCiklinisSarasas *pradziaDvikCikl = nullptr;

struct vienkryptCiklinisSarasas {
    int duom;
    vienkryptCiklinisSarasas *kitas;
};
vienkryptCiklinisSarasas *pradziaVienCikl = nullptr, *pabaigaVienCikl = nullptr; //realizuotas kaip dekas

void iterpimas ();
void salinimas();
void spausdinimas ();
void paieska();
void perkelimas();

int main()
{
    
    return 0;
}

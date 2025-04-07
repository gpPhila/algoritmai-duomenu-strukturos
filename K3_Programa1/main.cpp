 /*
 Sukurti dvejetainį medį, kurio elementai sveiki skaičiai. Realizuoti įterpimo, paieškos,
 spausdinimo ir šalinimo operacijas bei atlikti šiuos veiksmus:
 a. Įrašyti iš medžio visus skaičius, kurie priklauso intervalui [a;b], įrašyti į eilę,
 realizuotą kaip sąrašas.
 b. Panaikinti iš medžio visus skaičius, kurie priklauso intervalui [0;a] įrašant juos į deko,
 realizuotą kaip sąrašas, į pradžią.
 c. Panaikinti iš medžio visus skaičius, kurie priklauso intervalui [b;c] įrašant juos į deko,
 realizuotą kaip sąrašas, į pabaigą.
 d. Spausdinti deką ir eilę
  */

 #include <iostream>
 using namespace std;

 struct medis {
  int data;
  medis *kaire;
  medis *desine;
 };
medis* saknis = NULL;

 medis *naujas_elementas(int skaicius) {
  medis *p;
  p = new medis;
  p -> data = skaicius;
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

struct elem {
  int data;
  elem *kitas;
 };

struct eile {
  int data;
  elem *pradzia;
  elem *pabaiga;
 };
eile* q = NULL;

 void iterpimas (medis*& saknis);
 void paieska (medis *saknis);
 void spausdinimas (medis *saknis);
 void salinimas (medis*& saknis);
 void irasymasIEile (medis *saknis, eile*& q);
 void spausdintiEile (eile* q);

int ieskSk;
int pasalintiSk;
int a, b, c;

 int main() {
  int pasirinkimas;
  while (pasirinkimas !=10) {
   cout<<"Iveskite pasirinkto veiksmo numeri: "<<endl;
   cout<<"1. Ivedimas i medi"<<endl;
   cout<<"2. Paieska medyje"<<endl;
   cout<<"3. Medzio spausdinimas"<<endl;
   cout<<"4. Salinimas is medzio"<<endl;
   cout<<"5. Intervalo [a; b] elementu irasymas i eile"<<endl;
   cout<<"6. "<<endl;
   cout<<"7. "<<endl;
   cout<<"8. Spausdinti eile"<<endl;
   cout<<"9. "<<endl;
   cout<<"10. Iseiti"<<endl;
   cin>>pasirinkimas;

   switch (pasirinkimas) {
    case 1: iterpimas(saknis);
            cout<<"Skaicius buvo irasytas i medi"<<endl;
    break;

    case 2: cout<<"Kokio skaiciaus ieskome?"<<endl;
            cin>>ieskSk;
            paieska(saknis);
    break;


    case 3:  cout<<"Medzio duomenys: "<<endl;
             spausdinimas(saknis);
    break;

    case 4:  cout<<"Koki skaiciu norite pasalinti? "<<endl;
             cin>>pasalintiSk;
             salinimas(saknis);
    break;

    case 5: cout<<"Iveskite intervala [a; b] - visi jam priklausantys skaiciai bus irasyti i eile"<<endl;
            cin>>a >> b;
            irasymasIEile(saknis, q);
    break;

    case 8: spausdintiEile(q);
    break;

    case 10: cout<<"Jus isejote is meniu. Viso gero!"<<endl;
    break;

    default: cout<<"Tokio pasirinkimo nera."<<endl;
   }
  }
  return 0;
 }

 void iterpimas(medis*& saknis) {
  int skaicius;
  cout<<"Iveskite skaiciu: ";
  cin>>skaicius;

  medis* naujas = naujas_elementas(skaicius);

  if (saknis ==NULL) {
   saknis = naujas;
   return;
  }

  medis* dabartinis = saknis;
  medis* tevas = NULL;

  while (dabartinis != NULL) {

   tevas = dabartinis;
   if (skaicius < dabartinis->data) {
    dabartinis = dabartinis->kaire;
   } else {
    dabartinis = dabartinis->desine;
   }
  }

  if (skaicius < tevas->data) {
   tevas->kaire = naujas;
  } else {
   tevas->desine = naujas;
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
   cout<<"Jokiu skaiciu dar nebuvo ivesta."<<endl;
   return;
  }

  medis* dabartinis = saknis;

  while (dabartinis != NULL) {

   if (ieskSk == dabartinis->data) {
    cout << "Skaicius yra rastas!" << endl;
    return;
   }

   if (ieskSk < dabartinis -> data) {
    dabartinis = dabartinis -> kaire;
   } else {
    dabartinis = dabartinis -> desine;
   }
  }

  cout<<"Skaiciaus nera."<<endl;
 }

void salinimas (medis*& saknis) {
  if (saknis == NULL) {
   cout<<"Jokiu skaiciu dar nebuvo ivesta."<<endl;
   return;
  }

  medis* dabartinis = saknis;
  medis* tevas = NULL;

  while (dabartinis != NULL) {
   if (pasalintiSk == dabartinis->data) {
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
     cout<<"Skaicius buvo pasalintas!"<<endl;
     return;
    }

    //jeigu yra bent vienas vaikas
    else if (dabartinis->kaire == NULL || dabartinis->desine == NULL) {

     //paaiskinimas: condition ? expression_if_true : expression_if_false;
     medis* temp = (dabartinis->kaire != NULL) ? dabartinis->kaire : dabartinis->desine;

     if (dabartinis == saknis) {
      saknis = temp;
     } else if (tevas->kaire == dabartinis) {
      tevas->kaire = temp;
     } else {
      tevas->desine = temp;
     }
     delete dabartinis;
     cout << "Skaicius buvo pasalintas!" << endl;
     return;
    }

    //jeigu elementas turi du vaikus
    else {
     medis* maxKaireje = rasti_max(dabartinis->kaire);
     int temp = maxKaireje->data;

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

     cout<<"Skaicius buvo pasalintas!"<<endl;
     return;
    }
   }

   tevas = dabartinis;
   if (pasalintiSk < dabartinis -> data) {
    dabartinis = dabartinis -> kaire;
   } else {
    dabartinis = dabartinis -> desine;
   }
  }
  cout << "Tokio skaiciaus nera medyje." << endl;
 }

void irasymasIEile (medis* saknis, eile*& q) {
  if (saknis ==NULL) {
   return;
  }

  irasymasIEile(saknis->kaire, q);
  if (saknis->data >= a && saknis->data <= b) {
   elem* naujas = new elem;
   naujas->data = saknis->data;
   naujas->kitas = NULL;

   if (q == NULL) {
    q = new eile;
    q->pradzia = naujas;
    q->pabaiga = naujas;
   } else {
    q->pabaiga->kitas = naujas;
    q->pabaiga = naujas;
   }
  }
  irasymasIEile(saknis->desine, q);
 }

void spausdintiEile (eile* q) {
  elem* temp = q->pradzia;
  while (temp != NULL) {
   cout << temp->data << " ";
   temp = temp->kitas;
  }
  cout << endl;
 }
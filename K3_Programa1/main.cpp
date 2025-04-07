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

struct dekas {
 int data;
 dekas *kitas;
};
dekas* pradzia = NULL, *pabaiga = NULL;

medis* iterpimas(medis* saknis, int skaicius) {
 if (saknis == NULL) {
  return naujas_elementas(skaicius);
 }
 if (skaicius < saknis->data) {
  saknis->kaire = iterpimas(saknis->kaire, skaicius);
 } else {
  saknis->desine = iterpimas(saknis->desine, skaicius);
 }
 return saknis;
}

medis* panaikinti(medis *saknis, int x) {
 if (saknis==NULL) {
  return NULL;
 }
 if (x>saknis -> data) {
  saknis->desine = panaikinti(saknis -> desine, x);
 } else if (x<saknis -> data) {
  saknis->kaire = panaikinti(saknis -> kaire, x);
 } else {
  if (saknis -> kaire==NULL && saknis -> desine==NULL) {
   free(saknis);
   return NULL;
  } else if (saknis->kaire==NULL || saknis -> desine==NULL) {
   medis *temp;
   if (saknis -> kaire==NULL) {
    temp = saknis -> desine;
   } else {
    temp = saknis -> kaire;
   }
   free(saknis);
   return temp;

   //tuo atveju kai elementas yra kazkur viduryje
  } else {
   medis *temp = rasti_max(saknis->kaire);
   saknis->data = temp->data;
   saknis->kaire = panaikinti(saknis -> kaire, temp->data);
  }
 }
 return saknis;
}
 void paieska (medis *saknis);
 void spausdinimas (medis *saknis);
 void irasymasIEile (medis *saknis, eile*& q);
 void spausdintiEile (eile* q);
 void perrasymasIDekoPradzia (medis*& saknis, dekas*& pradzia, dekas*& pabaiga);
 void perrasymasIDekoPabaiga (medis*& saknis, dekas*& pradzia, dekas*& pabaiga);
 void salintiIntervala(medis*& saknis, int nuo, int iki);
 void spausdintiDeka (dekas* pradzia);

int skaicius;
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
   cout<<"6. Intervalo [0; a] elementu perrasymas is medzio i deko pradzia"<<endl;
   cout<<"7. Intervalo [b; c] elementu perrasymas is medzio i deko pabaiga"<<endl;
   cout<<"8. Spausdinti eile"<<endl;
   cout<<"9. Spausdinti deka"<<endl;
   cout<<"10. Iseiti"<<endl;
   cin>>pasirinkimas;

   switch (pasirinkimas) {
    case 1:
           int medzioDydis;
           cout<<"Kiek skaiciu norite ivesti? "<<endl;
           cin>>medzioDydis;
           cout<<"Iveskite visus skaicius (per tarpa): "<<endl;
           for (int i = 0; i < medzioDydis; i++) {
           cin>>skaicius;
           saknis = iterpimas(saknis, skaicius);
           }
           cout<<"Skaiciai buvo irasyti i medi."<<endl;
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
             saknis = panaikinti(saknis, pasalintiSk);
             cout<<"Skaicius buvo pasalintas."<<endl;
    break;

    case 5: cout<<"Iveskite intervala [a; b] - visi jam priklausantys skaiciai bus irasyti i eile"<<endl;
            cin>>a >> b;
            irasymasIEile(saknis, q);
    break;

    case 6:
            cout<<"Iveskite intevalo [0; a] a: "<<endl;
            cin>>a;
            cout<<endl;
            perrasymasIDekoPradzia(saknis, pradzia, pabaiga);
            salintiIntervala(saknis, 0, a);
    break;

    case 7: cout<<"Iveskite intevala [b; c] "<<endl;
            cin>>b>>c;
            perrasymasIDekoPabaiga(saknis, pradzia, pabaiga);
            salintiIntervala(saknis, b, c);
    break;

    case 8: spausdintiEile(q);
    break;

    case 9: spausdintiDeka(pradzia);
    break;

    case 10: cout<<"Jus isejote is meniu. Viso gero!"<<endl;
    break;

    default: cout<<"Tokio pasirinkimo nera."<<endl;
   }
  }
  return 0;
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
  cout<<"Tokio skaiciaus medyje nera."<<endl;
 }

void spausdinimas(medis *saknis) {
  if (saknis != NULL) {
   spausdinimas(saknis->kaire);
   cout<<saknis->data<<endl;
   spausdinimas(saknis->desine);
  }
 }

void irasymasIEile (medis* saknis, eile*& q) {
  if (saknis == NULL) {
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

void perrasymasIDekoPradzia (medis*& saknis, dekas*& pradzia, dekas*& pabaiga) {
  if (saknis ==nullptr) {
   return;
  }

  perrasymasIDekoPradzia(saknis->kaire, pradzia, pabaiga);

  if (saknis->data >= 0 && saknis->data <= a) {
   dekas* naujas = new dekas;
   naujas->data = saknis->data;
   naujas->kitas = pradzia;

   if (pradzia == nullptr) {
    pabaiga = naujas;
   }
   pradzia = naujas;
  }

  perrasymasIDekoPradzia(saknis->desine, pradzia, pabaiga);
 }


void perrasymasIDekoPabaiga (medis*& saknis, dekas*& pradzia, dekas*& pabaiga) {
  if (saknis ==nullptr) {
   return;
  }

  perrasymasIDekoPabaiga(saknis->kaire, pradzia, pabaiga);

  if (saknis->data >= b && saknis->data <= c) {
   dekas* naujas = new dekas;
   naujas->data = saknis->data;
   naujas->kitas = nullptr;

   if (pabaiga == nullptr) {
    pradzia = pabaiga = naujas;
   } else {
    pabaiga->kitas = naujas;
    pabaiga = naujas;
   }
  }
  perrasymasIDekoPabaiga(saknis->desine, pradzia, pabaiga);
 }

void salintiIntervala(medis*& saknis, int nuo, int iki) {
  if (saknis == nullptr) {
   return;
  }

  salintiIntervala(saknis->kaire, nuo, iki);
  salintiIntervala(saknis->desine, nuo, iki);

  if (saknis->data >= nuo && saknis->data <= iki) {
   saknis = panaikinti(saknis, saknis->data);
  }
 }

void spausdintiDeka (dekas* pradzia) {
  cout << "Deko elementai:" << endl;
  dekas* temp = pradzia;
  while (temp != NULL) {
   cout << temp->data << " ";
   temp = temp->kitas;
  }
  cout << endl;
 }
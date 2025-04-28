/*
Sukurti dinaminį AVL medį, realizuojant elemento įterpimo, pašalinimo, spausdinimo
bei paieškos funkcijas. Perkelti to sąrašo visus elementus į dvikryptį sąrašą,
realizuojant jį kaip eilę. Atspausdinti visus dvikrypčio sąrašo elementus.
*/

#include <iostream>
using namespace std;

struct medis {
    int key;
    medis *kaire;
    medis *desine;
    int dydis;
};

medis *naujasElementas (int key) {
    medis *medis1=new medis;
    medis1->key=key;
    medis1->kaire=NULL;
    medis1->desine=NULL;
    medis1->dydis=1;
    return medis1;
}

int rastiDydi (medis *N) {
    if (N==NULL) {
        return 0;
    }
    return N->dydis;
}

int max(int a, int b) {
    return (a>b)?a:b;
}

int balansinisKoef(medis *N) {
    if (N==NULL) {
        return 0;
    }
    return rastiDydi(N->kaire)-rastiDydi(N->desine);
}

medis *desinePosukis (medis *y) {
    medis *x = y->kaire;
    medis *T2=x->desine;

    x->desine = y;
    y->kaire = T2;

    y->dydis = max(rastiDydi (y->kaire), rastiDydi (y->desine))+1;
    x->dydis = max(rastiDydi(x->kaire), rastiDydi(x->desine))+1;

    return x;
}

medis *kairePosukis (medis *x) {
   medis *y = x->desine;
    medis *T2=y->kaire;

    y->kaire = x;
    x->desine = T2;

    x->dydis = max(rastiDydi(x->kaire), rastiDydi(x->desine))+1;
    y->dydis = max(rastiDydi(y->kaire), rastiDydi(y->desine))+1;

    return y;
}

medis *iterpimas(medis *medis, int key) {
    if (medis==NULL) {
        return naujasElementas(key);
    }

    if (key < medis->key) {
        medis->kaire = iterpimas(medis->kaire, key);
    } else if (key > medis->key) {
        medis->desine = iterpimas(medis->desine, key);
    } else {
        return medis;
    }

    medis->dydis = 1 + max(rastiDydi(medis->kaire), rastiDydi(medis->desine));
    int balansas = balansinisKoef(medis);

    if (balansas > 1 && key < medis->kaire->key) {
        return desinePosukis(medis);
    }
    if (balansas < 1 && key > medis->desine->key) {
        return kairePosukis(medis);
    }
    if (balansas > 1 && key > medis->kaire->key) {
        medis->kaire = kairePosukis(medis->kaire);
        return desinePosukis(medis);
    }
    if (balansas < -1 && key < medis->desine->key) {
        medis->desine = desinePosukis(medis->desine);
        return kairePosukis(medis);
    }
    return medis;
}

medis *minimumas(medis *medis) {
    struct medis *dabartinis = medis;

    while (dabartinis->kaire != NULL) {
        dabartinis = dabartinis->kaire;
    }
    return dabartinis;
}

medis *salinimas(medis *saknis, int key) {
    if (saknis==NULL) {
        return saknis;
    }

    if (key < saknis->key) {
        saknis->kaire = salinimas(saknis->kaire, key);
    } else if (key> saknis->key) {
        saknis->desine = salinimas(saknis->desine, key);
    } else {
        if (saknis->kaire == NULL || saknis->desine == NULL) {
            medis *temp = saknis->kaire ? saknis->kaire : saknis->desine;
            if (temp == NULL) {
                temp = saknis;
                saknis = NULL;
            } else {
                *saknis = *temp;
                free(temp);
            }
        } else {
            medis *temp = minimumas(saknis->desine);
            saknis->key = temp -> key;
            saknis->desine = salinimas(saknis->desine, temp -> key);
        }
    }

    if (saknis==NULL) {
        return saknis;
    }

    saknis->dydis = 1 + max(rastiDydi(saknis->kaire), rastiDydi(saknis->desine));
    int balansas = balansinisKoef(saknis);

    if (balansas > 1 && balansinisKoef(saknis->kaire) >=0) {
        return desinePosukis(saknis);
    }
    if (balansas > 1 && balansinisKoef(saknis->kaire) < 0) {
        saknis->kaire = kairePosukis(saknis->kaire);
        return desinePosukis(saknis);
    }
    if (balansas < -1 && balansinisKoef(saknis->desine) <=0) {
        return kairePosukis(saknis);
    }
    if (balansas < -1 && balansinisKoef(saknis->desine) > 0) {
        saknis->desine = desinePosukis(saknis->desine);
        return kairePosukis(saknis);
    }
    return saknis;
}

void spausdinimas(medis *saknis) {
    if (saknis==NULL) {
        cout<<"Elementu nera."<<endl;
    }

    if (saknis != NULL) {
        spausdinimas(saknis->kaire);
        cout<<saknis->key<<" ";
        spausdinimas(saknis->desine);
    }
}

int main() {

    return 0;
}
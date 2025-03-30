#include <iostream>
using namespace std;

struct medis {
    int data;
    medis *desine;
    medis *kaire;
};

medis *naujas_elementas(int x) {
    medis *p;
    p = new medis;
    p -> data = x;
    p -> desine = NULL;
    p -> kaire = NULL;
    return p;
}

medis* iterpti(medis *saknis, int x) {
    if (saknis==NULL) {
        return naujas_elementas(x);
    } else {
        if (x>saknis -> data) {
            saknis -> desine = iterpti(saknis -> desine, x);
        } else {
            saknis->kaire = iterpti(saknis -> kaire, x);
        }
        return saknis;
    }
}

medis* paieska(medis *saknis, int x) {
    if (saknis==NULL || saknis -> data==x) {
        return saknis;
    } else if (x>saknis -> data) {
        return paieska(saknis -> desine, x);
    } else {
        return paieska(saknis -> kaire, x);
    }
}

//atspausdins nuo maz iki didz elemento
void spausdinti(medis *saknis) {
    if (saknis!=NULL) {
        spausdinti(saknis -> kaire);
        cout << saknis -> data;
        spausdinti(saknis -> desine);
    }
}

medis *rasti_max(medis *saknis) {
    if (saknis==NULL) {
        return NULL;
    } else if (saknis -> desine!=NULL) {
        return rasti_max(saknis -> desine);
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

int main() {

    return 0;
}
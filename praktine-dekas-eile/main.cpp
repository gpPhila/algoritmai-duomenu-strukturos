#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define MAX 7

using namespace std;

struct stekas {
    int duom;
    stekas *kitas;
};
stekas *pradziaStekas;

struct elem
{
    int duom;
    elem *kitas;
};

struct eile
{
    int dydis;
    elem *pradzia;
    elem *pabaiga;
};
eile q = {0, nullptr, nullptr};

int dekas_mas[MAX];
int pradzia=-1;
int pabaiga=-1;

void iterpti_pradzioje(int item);
void iterpti_pabaigoje(int item);
int panaikinti_pradzioje();
int panaikinti_pabaigoje();
void display();
bool isEmpty();
bool isFull();

void salintiIsDekoDetiIEile(eile *q);
void printEile(eile *q);
void salintiIsDekoDetiIStacka(stekas *&pradziaStekas);
void printStekas(stekas *pradziaStekas);

int main()
{
    /*
    iterpti_pabaigoje(10);
    iterpti_pabaigoje(20);
    iterpti_pradzioje(5);
    display(); // Isveda: 5 10 20

    panaikinti_pradzioje();
    display(); // Isveda: 10 20

    panaikinti_pabaigoje();
    display(); // Isveda: 10
    */

    iterpti_pabaigoje(1);
    iterpti_pradzioje(2);
    iterpti_pabaigoje(3);
    iterpti_pradzioje(4);
    iterpti_pabaigoje(5);
    iterpti_pradzioje(6);
    display();
    //6 4 2 1 3 5

    salintiIsDekoDetiIEile(&q);
    salintiIsDekoDetiIEile(&q);
    printEile(&q);
    cout<<"Like deko elementai:"<<endl;
    display();

    salintiIsDekoDetiIStacka(pradziaStekas);
    salintiIsDekoDetiIStacka(pradziaStekas);
    cout<<"Steko elementai:"<<endl;
    printStekas(pradziaStekas);
    cout<<"Like deko elementai:"<<endl;
    display();

    return 0;
}

bool isEmpty() {
    return pradzia == -1;
}

bool isFull() {
    return (pabaiga + 1) % MAX == pradzia;
}

void iterpti_pradzioje(int item) {
    if (isFull()) {
        cout << "Dekas yra pilnas" << endl;
        return;
    }
    if (isEmpty()) {
        pradzia = pabaiga = 0;
    } else {
        pradzia = (pradzia - 1 + MAX) % MAX;
    }
    dekas_mas[pradzia] = item;
}

void iterpti_pabaigoje(int item) {
    if (isFull()) {
        cout << "Dekas yra pilnas" << endl;
        return;
    }
    if (isEmpty()) {
        pradzia = pabaiga = 0;
    } else {
        pabaiga = (pabaiga + 1) % MAX;
    }
    dekas_mas[pabaiga] = item;
}

int panaikinti_pradzioje() {
    if (isEmpty()) {
        cout << "Dekas yra tuscias" << endl;
        return -1;
    }
    int item = dekas_mas[pradzia];
    if (pradzia == pabaiga) {
        pradzia = pabaiga = -1;
    } else {
        pradzia = (pradzia + 1) % MAX;
    }
    return item;
}

int panaikinti_pabaigoje() {
    if (isEmpty()) {
        cout << "Dekas yra tuscias" << endl;
        return -1;
    }
    int item = dekas_mas[pabaiga];
    if (pradzia == pabaiga) {
        pradzia = pabaiga = -1;
    } else {
        pabaiga = (pabaiga - 1 + MAX) % MAX;
    }
    return item;
}

void display() {
    if (isEmpty()) {
        cout << "Dekas yra tuscias" << endl;
        return;
    }
    int i = pradzia;
    while (true) {
        cout << dekas_mas[i] << " ";
        if (i == pabaiga) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

void salintiIsDekoDetiIEile(eile *q) {

    int duom = panaikinti_pradzioje(); // Salina is deko

    // Prideda i eile
    elem *naujas = new elem{duom, nullptr};
    if (q->pabaiga == nullptr) {
        q->pradzia = q->pabaiga = naujas;
    } else {
        q->pabaiga->kitas = naujas;
        q->pabaiga = naujas;
    }
    q->dydis++;
}

void printEile(eile *q) {

    elem *temp = q->pradzia;
    cout << "Eiles elementai: ";
    while (temp) {
        cout << temp->duom << " ";
        temp = temp->kitas;
    }
    cout << endl;
}

void salintiIsDekoDetiIStacka(stekas *&pradziaStekas) {
    int duom = panaikinti_pabaigoje(); // panaikina is deko

    // Prideda i steka
    stekas *naujas = new stekas{duom, pradziaStekas}; // Sukuria nauja steko elementa
    pradziaStekas = naujas;
}

void printStekas(stekas *pradziaStekas) {
    stekas *temp = pradziaStekas;
    while (temp) {
        cout << temp->duom << " ";
        temp = temp->kitas;
    }
    cout << endl;
}
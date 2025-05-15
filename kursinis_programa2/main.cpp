#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void quickSort(int arr[ ], int left, int right) {
    int i = left, j = right;       int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {  // partition
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {  tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    ofstream failas("data.txt");

    if (!failas) {
        cout << "Failo nera!" << endl;
        return 1;
    }
    int COUNT = 100000;

    srand(time(0));
    for (int i = 0; i < COUNT; ++i) {
        int number = rand(); //%1000000
        failas << number << endl;
    }
    failas.close();

    int pasirinkimas;
    while (pasirinkimas !=2) {
        cout<<"1. Greitasis rikiavimas."<<endl;
        cout<<"2. Baigti."<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                cout<<"Pasirinkimas: greitasis rikiavimas."<<endl;
                int kiekis;
                cout << "Kiek skaiciu nuskaityti is failo? ";
                cin >> kiekis;

                int masyvas[100000];
                failas.open("data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas >> masyvas[i];
                }
                failas.close();

                clock_t start = clock();
                Bubble_Sort(masyvas, kiekis);
                clock_t end = clock();
                cout << "Rikiavimo laikas: " << double(end - start) / CLOCKS_PER_SEC << " sek." << endl;
            break;


            case 2: cout<<"Baigta."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    return 0;
}
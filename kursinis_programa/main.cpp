#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void Bubble_Sort (int array[ ], int length)
{  int i, j, flag = 1;
    int temp;
    for(i = 0; (i < length-1 ) && flag; i++)
    {flag = 0;
        for (j=0; j < (length -i -1); j++)
        {if (array [j+1] < array[j])
        { temp = array [j];// elementų sukeitimas
            array [j] = array [j+1];
            array [j+1] = temp;
            flag = 1;// Ar buvo nors vienas sukeitimas?
        }
        }
    }
}

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
    while (pasirinkimas !=3) {
        cout<<"Pasirinkti rikiavima: "<<endl;
        cout<<"1. Burbulo rikiavimas."<<endl;
        cout<<"2. Greitasis rikiavimas."<<endl;
        cout<<"3. Baigti."<<endl;

        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                cout<<"Pasirinkimas: burbulo rikiavimas."<<endl;
                int kiekis;
                cout << "Kiek skaiciu nuskaityti is failo? ";
                cin >> kiekis;

                int masyvas[100000];
                ifstream failas("data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas >> masyvas[i];
                }
                failas.close();

                clock_t start = clock();
                Bubble_Sort(masyvas, kiekis);
                clock_t end = clock();
                cout << "Rikiavimo laikas: " << double(end - start) / CLOCKS_PER_SEC << " sek." << endl;

                ofstream isvedimas("surusiuota_data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    isvedimas << masyvas[i] << endl;
                }
                isvedimas.close();

            break;

            case 3: cout<<"Baigta."<<endl;
            break;

            default: cout<<"Tokio pasirinkimo nera."<<endl;
        }
    }
    return 0;
}
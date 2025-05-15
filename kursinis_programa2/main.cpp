#include <iostream>
#include <fstream>
#include <ctime>
//#include <chrono>
using namespace std;

void quickSort(int arr[ ], int left, int right, long long& swaps) {
    int i = left, j = right;
    int tmp;
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
            swaps++;
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(arr, left, j, swaps);
    }
    if (i < right) {
        quickSort(arr, i, right, swaps);
    }
}

void quickSort_atv(int arr[ ], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {  // partition
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
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
        quickSort_atv(arr, left, j);
    }
    if (i < right) {
        quickSort_atv(arr, i, right);
    }
}

int main() {

    //random skaiciai-----------------------------------------------------------
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
    cout << "Atsitiktiniai duomenys buvo ivesti." << endl;

    //atvirksciai surikiuoti tie pat random skaiciai----------------------------
    int masyvasATV[100000];
    ifstream duomenys("data.txt");
    for (int i = 0; i < 100000; ++i) {
        duomenys >> masyvasATV[i];
    }
    duomenys.close();
    quickSort_atv(masyvasATV, 0, 99999);
    ofstream isvedimasAtv("atv_surus_data.txt");
    for (int i = 0; i < 100000; ++i) {
        isvedimasAtv << masyvasATV[i] << endl;
    }
    isvedimasAtv.close();
    cout << "Atvirksciai surikiuoti duomenys buvo ivesti." << endl;

    //IS anksto Surikiuoti skaiciai----------------------------------------
    long long swaps1 = 0;
    int masyvasSur[100000];
    ifstream data("data.txt");
    for (int i = 0; i < 100000; ++i) {
        data >> masyvasSur[i];
    }
    data.close();
    quickSort(masyvasSur, 0, 99999, swaps1);
    ofstream isvedimasSur("surusiuota_data.txt");
    for (int i = 0; i < 100000; ++i) {
        isvedimasSur << masyvasSur[i] << endl;
    }
    isvedimasSur.close();
    cout << "Surikiuoti duomenys buvo ivesti." << endl;

    int pasirinkimas;
    while (pasirinkimas !=2) {
        cout<<"Greitasis rikiavimas: "<<endl;
        cout<<"1. Testi."<<endl;
        cout<<"2. Baigti."<<endl;

        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                int kiekis;
                int masyvas1[100000];
                int masyvas2[100000];
                int masyvas3[100000];
                cout << "Kiek skaiciu nuskaityti is failo? ";
                cin >> kiekis;

                ifstream failas1("data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas1 >> masyvas1[i];
                }
                failas1.close();

                //paprastas random duomenu rikiavimas----------------------------------

                clock_t start = clock();
                quickSort(masyvas1,0, kiekis-1, swaps1);
                clock_t end = clock();
                cout << "Rikiavimo laikas (nesurusiuoti duomenys): " << double(end - start) / CLOCKS_PER_SEC << " sek." << endl;
                cout << "Elementu suketimo vietomis skaicius (nesurusiuoti duomenys): " << swaps1 << endl;

                ofstream isvedimas1("tarpinis_rezultatas.txt");
                for (int i = 0; i < kiekis; ++i) {
                    isvedimas1 << masyvas1[i] << endl;
                }
                isvedimas1.close();

                //atvirksciai surikiuotu duomenu rikiavimas---------------------------

                long long swaps2 = 0;
                ifstream failas2("atv_surus_data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas2 >> masyvas2[i];
                }
                failas2.close();


                clock_t start2 = clock();
                quickSort(masyvas2,0, kiekis-1, swaps2);
                clock_t end2 = clock();
                cout << "Rikiavimo laikas (atvirksciai surusiuoti duomenys): " << double(end2 - start2) / CLOCKS_PER_SEC << " sek." << endl;
                cout << "Elementu suketimo vietomis skaicius (atvirksciai surusiuoti duomenys): " << swaps2 << endl;

                ofstream isvedimas2("tarpinis_rezultatas2.txt");
                for (int i = 0; i < kiekis; ++i) {
                    isvedimas2 << masyvas2[i] << endl;
                }
                isvedimas2.close();

                //is anksto surikiuotu duomenu rikiavimas-----------------------------------

                long long swaps3 = 0;
                ifstream failas3("surusiuota_data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas3 >> masyvas3[i];
                }
                failas3.close();


                clock_t start3 = clock();
                quickSort(masyvas3,0, kiekis-1, swaps3);
                clock_t end3 = clock();
                cout << "Rikiavimo laikas (is anksto surusiuoti duomenys): " << double(end3 - start3) / CLOCKS_PER_SEC << " sek." << endl;
                cout << "Elementu suketimo vietomis skaicius (is anksto surusiuoti duomenys): " << swaps3 << endl;

                ofstream isvedimas3("tarpinis_rezultatas3.txt");
                for (int i = 0; i < kiekis; ++i) {
                    isvedimas3 << masyvas3[i] << endl;
                }
                isvedimas3.close();

                break;
            }
            case 2: {
                cout<<"Baigta."<<endl;

                break;
            }
            default: {
                cout<<"Tokio pasirinkimo nera."<<endl;
            }
        }
    }
    return 0;
}
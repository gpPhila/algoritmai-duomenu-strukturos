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

void Bubble_Sort_atv (int array[ ], int length)
{  int i, j, flag = 1;
    int temp;
    for(i = 0; (i < length-1 ) && flag; i++)
    {flag = 0;
        for (j=0; j < (length -i -1); j++)
        {if (array [j+1] > array[j])
        { temp = array [j];// elementų sukeitimas
            array [j] = array [j+1];
            array [j+1] = temp;
            flag = 1;// Ar buvo nors vienas sukeitimas?
        }
        }
    }
}
/*
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
*/

void rikiavimas1();
void rikiavimas2();
void rikiavimas3();

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
    cout << "Random duomenys buvo ivesti." << endl;

    //atvirksciai surikiuoti tie pat random skaiciai----------------------------
    int masyvasATV[100000];
    ifstream duomenys("data.txt");
    for (int i = 0; i < 100000; ++i) {
        duomenys >> masyvasATV[i];
    }
    duomenys.close();
    Bubble_Sort_atv(masyvasATV, 100000);
    ofstream isvedimasAtv("atv_surus_data.txt");
    for (int i = 0; i < 100000; ++i) {
        isvedimasAtv << masyvasATV[i] << endl;
    }
    isvedimasAtv.close();
    cout << "Atvirksciai surikiuoti duomenys buvo ivesti." << endl;

    //IS anksto Surikiuoti skaiciai----------------------------------------
    int masyvasSur[100000];
    ifstream data("data.txt");
    for (int i = 0; i < 100000; ++i) {
        data >> masyvasSur[i];
    }
    data.close();
    Bubble_Sort(masyvasSur, 100000);
    ofstream isvedimasSur("surusiuota_data.txt");
    for (int i = 0; i < 100000; ++i) {
        isvedimasSur << masyvasSur[i] << endl;
    }
    isvedimasSur.close();
    cout << "Surikiuoti duomenys buvo ivesti." << endl;

    int pasirinkimas;
    while (pasirinkimas !=2) {
        cout<<"Burbulo rikiavimas: "<<endl;
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
                Bubble_Sort(masyvas1, kiekis);
                clock_t end = clock();
                cout << "Rikiavimo laikas (nesurusiuoti duomenys): " << double(end - start) / CLOCKS_PER_SEC << " sek." << endl;

                double duration_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
                cout << "Rikiavimo laikas (nesurusiuoti duomenys): " << duration_ms << " ms."<<endl;
                ofstream isvedimas1("tarpinis_rezultatas.txt");
                for (int i = 0; i < kiekis; ++i) {
                    isvedimas1 << masyvas1[i] << endl;
                }
                isvedimas1.close();

                //atvirksciai surikiuotu duomenu rikiavimas---------------------------

                ifstream failas2("atv_surus_data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas2 >> masyvas2[i];
                }
                failas2.close();

                clock_t start2 = clock();
                Bubble_Sort(masyvas2, kiekis);
                clock_t end2 = clock();
                cout << "Rikiavimo laikas (atvirksciai surusiuoti duomenys): " << double(end2 - start2) / CLOCKS_PER_SEC << " sek." << endl;

                double duration_ms1 = 1000.0 * (end2 - start2) / CLOCKS_PER_SEC;
                cout << "Rikiavimo laikas (atvirksciai surusiuoti duomenys): " << duration_ms1 << " ms."<<endl;
                ofstream isvedimas2("t_r2.txt");
                for (int i = 0; i < kiekis; ++i) {
                    isvedimas2 << masyvas2[i] << endl;
                }
                isvedimas2.close();

                //is anksto surikiuotu duomenu rikiavimas-----------------------------------

                ifstream failas3("surusiuota_data.txt");
                for (int i = 0; i < kiekis; ++i) {
                    failas3 >> masyvas3[i];
                }
                failas3.close();

                clock_t start3 = clock();
                Bubble_Sort(masyvas3, kiekis);
                clock_t end3 = clock();
                cout << "Rikiavimo laikas (is anksto surusiuoti duomenys): " << double(end3 - start3) / CLOCKS_PER_SEC << " sek." << endl;

                double duration_ms2 = 1000.0 * (end3 - start3) / CLOCKS_PER_SEC;
                cout << "Rikiavimo laikas (is anksto surusiuoti duomenys): " << duration_ms2 << " ms."<<endl;
                ofstream isvedimas3("t_r3.txt");
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
#include <iostream>
#include <fstream>
#include <ctime>
//#include <chrono>
using namespace std;

void Bubble_Sort (int array[ ], int length, long long& swap_count)
{  int i, j, flag = 1;
    int temp;
    swap_count = 0;
    for(i = 0; (i < length-1 ) && flag; i++)
    {flag = 0;
        for (j=0; j < (length -i -1); j++)
        {if (array [j+1] < array[j])
        { temp = array [j];// elementų sukeitimas
            array [j] = array [j+1];
            array [j+1] = temp;
            swap_count++;
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
        { temp = array [j];
            array [j] = array [j+1];
            array [j+1] = temp;
            flag = 1;
        }
        }
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
    Bubble_Sort_atv(masyvasATV, 100000);
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
    Bubble_Sort(masyvasSur, 100000, swaps1);
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
                Bubble_Sort(masyvas1, kiekis, swaps1);
                clock_t end = clock();
                cout << "Rikiavimo laikas (nesurusiuoti duomenys): " << double(end - start) / CLOCKS_PER_SEC << " sek." << endl;
                cout << "Elementu suketimo vietomis skaicius (nesurusiuoti duomenys): " << swaps1 << endl;

                /*
                auto start = chrono::high_resolution_clock::now();
                Bubble_Sort(masyvas1, kiekis);
                auto end = chrono::high_resolution_clock::now();

                auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                double seconds = duration.count() / 1000.0;
                cout << "Rikiavimo laikas (nesurusiuoti duomenys): " << seconds << " sek." << std::endl;
                */
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
                Bubble_Sort(masyvas2, kiekis, swaps2);
                clock_t end2 = clock();
                cout << "Rikiavimo laikas (atvirksciai surusiuoti duomenys): " << double(end2 - start2) / CLOCKS_PER_SEC << " sek." << endl;
                cout << "Elementu suketimo vietomis skaicius (atvirksciai surusiuoti duomenys): " << swaps2 << endl;

                /*
                auto start2 = chrono::high_resolution_clock::now();
                Bubble_Sort(masyvas2, kiekis);
                auto end2 = chrono::high_resolution_clock::now();

                auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
                double seconds2 = duration2.count() / 1000.0;
                cout << "Rikiavimo laikas (atvirksciai surusiuoti duomenys): " << seconds2 << " sek." << std::endl;
                */
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
                Bubble_Sort(masyvas3, kiekis, swaps3);
                clock_t end3 = clock();
                cout << "Rikiavimo laikas (is anksto surusiuoti duomenys): " << double(end3 - start3) / CLOCKS_PER_SEC << " sek." << endl;
                cout << "Elementu suketimo vietomis skaicius (is anksto surusiuoti duomenys): " << swaps3 << endl;

                /*
                auto start3 = chrono::high_resolution_clock::now();
                Bubble_Sort(masyvas3, kiekis);
                auto end3 = chrono::high_resolution_clock::now();

                auto duration3 = chrono::duration_cast<chrono::milliseconds>(end3 - start3);
                double seconds3 = duration3.count() / 1000.0;
                cout << "Rikiavimo laikas (is anksto surusiuoti duomenys): " << seconds3 << " sek." << std::endl;
                */
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
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <chrono>
#include <limits>

#include "SitoTredovi.h"
#include "NZD.h"

using namespace std;
using namespace chrono;

int main()
{
    int opcija;
    unsigned long long int n;
    cout << "Izaberite opciju:" << endl;
    cout << "Da li je uneti broj prost      |1|" << endl;
    cout << "Svi prosti brojevi do n        |2|" << endl;
    cin >> opcija;
    unsigned long long int brojProstih = 0;
    if (opcija == 1)
    {

        cout << "Unesite broj: ";
        cin >> n;
        NZD v1;

        if (v1.dalijeprost(n))
        {
            cout << "Broj " << n << " je prost" << endl;
        }
        else
        {
            cout << "Broj " << n << " nije prost" << endl;
            cout << "Broj delilaca: " << v1.Delioci(n).size() << endl;
            cout << "Delioci: ";

            for (int d : v1.Delioci(n))
            {
                cout << d << " ";
            }
            cout << endl;
        }
    }
    else if (opcija == 2)
    {
        ofstream ofs("izlaz.txt", ios::out | ios::trunc);
        ofs.close();
        cout << "Unesite broj N: ";
        cin >> n;
        int brojtredova;
        cout << "Broj thredova koji ce program da koristi: ";
        cin >> brojtredova;
        if (n < 10000000)
        {
            cout << "Ispis preko:\n";
            cout << "Konzole                            |1|\n";
            cout << ".txt fajl (dosta brzi od koznole)  |2|\n";
            int opcija4;
            cin >> opcija4;
            SitoTredovi v2;
            vector<bool> prost = v2.eratostenovoSito(n, brojtredova);
            if (opcija4 == 1)
            {

                auto start = high_resolution_clock::now();
                for (unsigned long long int i = 2; i <= n; i++)
                {
                    if (prost[i])
                    {
                        cout << i;
                        brojProstih++;
                    }
                }
                auto stop = high_resolution_clock::now();
                auto trajanje = duration_cast<milliseconds>(stop - start);
                cout << "Za izvrsavanje programa potrebno je bilo: " << trajanje.count();
                if (trajanje.count()>4)
                {
                    cout << " milisekundi\n";
                }
                else
                {
                    cout << " milisekunde\n";
                }
                cout << "Broj prostih brojeva:" << brojProstih << endl;
            }
            else if (opcija4 == 2)
            {
                auto start = high_resolution_clock::now();
                ofstream outputFile("izlaz.txt");
                for (unsigned long long int i = 2; i <= n; i++)
                {
                    if (prost[i])
                    {
                        outputFile << i << endl;
                        brojProstih++;
                    }
                }
                outputFile.close();
                cout << "Program je zavrsio sa radom\n";
                auto stop = high_resolution_clock::now();
                auto trajanje = duration_cast<milliseconds>(stop - start);
                cout << "Za izvrsavanje programa potrebno je bilo: " << trajanje.count();
                if (trajanje.count() > 4)
                {
                    cout << " milisekundi\n";
                }
                else
                {
                    cout << " milisekunde\n";
                }
                cout << "Broj prostih brojeva:" << brojProstih << endl;
            }
        }
        else
        {
            cout << endl;
            cout << "Brojevi veci od 10 miliona mogu zablokirati kompjuter\n";
            cout << "Da li zelis da nastavis?\n";
            cout << "DA |1|\n";
            cout << "NE |2|\n";
            int opcija3;
            cin >> opcija3;
            cout << endl;
            SitoTredovi v2;
            if (opcija3 == 1)
            {
                cout << "Ispis preko:\n";
                cout << "Konzole                            |1|\n";
                cout << ".txt fajl (dosta brzi od koznole)  |2|\n";
                int opcija2;
                cin >> opcija2;
                vector<bool> prost = v2.eratostenovoSito(n, brojtredova);
                if (opcija2 == 1)
                {
                    auto start = high_resolution_clock::now();
                    for (unsigned long long int i = 2; i <= n; i++)
                    {
                        if (prost[i])
                        {
                            cout << i;
                            brojProstih++;
                        }
                    }
                    auto stop = high_resolution_clock::now();
                    auto trajanje = duration_cast<milliseconds>(stop - start);
                    cout << "Za izvrsavanje programa potrebno je bilo: " << trajanje.count();
                    if (trajanje.count() > 4)
                    {
                        cout << " milisekundi\n";
                    }
                    else
                    {
                        cout << " milisekunde\n";
                    }
                    cout << "Broj prostih brojeva:" << brojProstih << endl;
                }
                else if (opcija2 == 2)
                {
                    auto start = high_resolution_clock::now();
                    ofstream outputFile("izlaz.txt");
                    for (unsigned long long int i = 2; i <= n; i++)
                    {
                        if (prost[i])
                        {
                            outputFile << i << endl;
                            brojProstih++;
                        }
                    }
                    outputFile.close();
                    cout << "Program je zavrsio sa radom\n";
                    auto stop = high_resolution_clock::now();
                    auto trajanje = duration_cast<milliseconds>(stop - start);
                    cout << "Za izvrsavanje programa potrebno je bilo: " << trajanje.count();
                    if (trajanje.count() > 4)
                    {
                        cout << " milisekundi\n";
                    }
                    else
                    {
                        cout << " milisekunde\n";
                    }
                    cout << "Broj prostih brojeva:" << brojProstih << endl;
                }
            }
        }
    }
    return 0;
}

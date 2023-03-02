#pragma once 
#include <vector>  
#include <cmath>   
#include <thread>  

using namespace std;

class SitoTredovi
{
public:

    vector<bool> eratostenovoSito(long long int n, int brojTredova)
    {
        vector<bool> prost(n + 1, true);
        prost[0] = prost[1] = false;
        int velicinaGrupe = sqrt(n) / brojTredova;
        vector<thread> tredovi;
        for (int i = 0; i < brojTredova; i++)
        {
            int pocetak = i * velicinaGrupe + 2;
            int kraj = (i == brojTredova - 1) ? sqrt(n) + 1 : (i + 1) * velicinaGrupe + 1;
            tredovi.emplace_back(&SitoTredovi::sito, this, pocetak, kraj, ref(prost));
        }
        for (auto& t : tredovi)
        {
            t.join();
        }
        return prost;
    }

private:

    void sito(int pocetak, int kraj, vector<bool>& prost)
    {
        for (int i = 2; i * i <= kraj; i++)
        {
            if (prost[i])
            {
                int Pocetak = ((pocetak + i - 1) / i) * i;
                for (int j = Pocetak; j <= kraj; j += i)
                {
                    prost[j] = false;
                }
                if (Pocetak == i)
                {
                    prost[i] = true;
                }
            }
        }
    }
};

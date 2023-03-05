#pragma once 
#include <vector>  
#include <cmath>
#include <thread>
#include <iostream>

using namespace std;

class SitoTredovi
{
public:

    vector<bool> eratostenovoSito(unsigned long long int n, int brojTredova)
    {
        vector<bool> prost(n + 1, true);
        prost[0] = prost[1] = false;

        vector<thread> threads(brojTredova);

        for (int t = 0; t < brojTredova; t++) 
        {
            threads[t] = thread([&, t]() 
            {
                for (int i = 2 + t; i <= sqrt(n); i += brojTredova) 
                {
                    if (prost[i]) 
                    {
                        for (int j = i * i; j <= n; j += i) 
                        {
                            prost[j] = false;
                        }
                    }
                }
            });
        }

        for (int t = 0; t < brojTredova; t++) 
        {
            threads[t].join();
        }

        return prost;
    }
};

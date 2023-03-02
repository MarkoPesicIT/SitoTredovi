#pragma once
#include <iostream>
#include <vector>

using namespace std;

class NZD
{
public:

    vector<int> Delioci(int n)
    {
        vector<int> delioci;
        for (int i = 2; i <= std::sqrt(n); i++)
        {
            while (n % i == 0)
            {
                delioci.push_back(i);
                n /= i;
            }
        }
        if (n > 1)
        {
            delioci.push_back(n);
        }
        return delioci;
    }

    bool dalijeprost(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
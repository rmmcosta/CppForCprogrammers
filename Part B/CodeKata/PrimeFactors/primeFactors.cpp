#include "primeFactors.hpp"
#include <iostream>

vector<int> calcPrimeFactors(int x)
{
     vector<int> temp;
     for (int divisor = 2; x > 1; divisor++)
          for (; x % divisor == 0; x /= divisor)
               temp.push_back(divisor);
     return temp;
}

string stringResult(bool result)
{
     return (result == 1 ? "passed" : "failed");
}

void printPrimeFactors(const vector<int> &primes)
{
     for (auto iter = primes.begin(); iter != primes.end(); iter++)
          cout << *iter << "\t";
     cout << endl;
}
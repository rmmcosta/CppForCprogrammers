#include "cppunit.hpp"
#include <iostream>
#include <string>

vector<int> primeFactors(int);
string stringResult(bool);

int main()
{
    bool result = assertThat(primeFactors(0), {});
    cout << "assertThat(primeFactors(0), {})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(1), {});
    cout << "assertThat(primeFactors(1), {})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(2), {2});
    cout << "assertThat(primeFactors(2), {2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(3), {3});
    cout << "assertThat(primeFactors(3), {3})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(4), {2, 2});
    cout << "assertThat(primeFactors(4), {2,2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(5), {5});
    cout << "assertThat(primeFactors(5), {5})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(6), {2, 3});
    cout << "assertThat(primeFactors(6), {2,3})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(7), {7});
    cout << "assertThat(primeFactors(7), {7})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(8), {2, 2, 2});
    cout << "assertThat(primeFactors(8), {2,2,2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(primeFactors(9), {3, 3});
    cout << "assertThat(primeFactors(9), {3,3})"
         << " -> " << stringResult(result) << endl;
    return 0;
}

vector<int> primeFactors(int x)
{
    vector<int> temp;
    if (x < 2)
        return temp;
    while (x % 2 == 0)
    {
        temp.push_back(2);
        x /= 2;
    }
    if (x > 1)
        temp.push_back(x);
    return temp;
}

string stringResult(bool result)
{
    return (result == 1 ? "passed" : "failed");
}
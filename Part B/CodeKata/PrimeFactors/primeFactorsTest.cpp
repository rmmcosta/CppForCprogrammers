#include "primeFactors.hpp"
#include <iostream>

void runTests();

int main()
{
    int option = 0;
    while (option < 1 || option > 2)
    {
        cout << "What do you want to do:\n1-input a number\n2-run tests\n";
        cin >> option;
    }
    if (option == 2)
        runTests();
    if (option == 1)
    {
        cout << "What is the number: ";
        int number;
        cin >> number;
        const vector<int> primes = calcPrimeFactors(number);
        printPrimeFactors(primes);
    }

    return 0;
}

void runTests()
{
    bool result = assertThat(calcPrimeFactors(0), {});
    cout << "assertThat(calcPrimeFactors(0), {})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(1), {});
    cout << "assertThat(calcPrimeFactors(1), {})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(2), {2});
    cout << "assertThat(calcPrimeFactors(2), {2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(3), {3});
    cout << "assertThat(calcPrimeFactors(3), {3})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(4), {2, 2});
    cout << "assertThat(calcPrimeFactors(4), {2,2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(5), {5});
    cout << "assertThat(calcPrimeFactors(5), {5})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(6), {2, 3});
    cout << "assertThat(calcPrimeFactors(6), {2,3})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(7), {7});
    cout << "assertThat(calcPrimeFactors(7), {7})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(8), {2, 2, 2});
    cout << "assertThat(calcPrimeFactors(8), {2,2,2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(9), {3, 3});
    cout << "assertThat(calcPrimeFactors(9), {3,3})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(10), {2, 5});
    cout << "assertThat(calcPrimeFactors(10), {2,5})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(11), {11});
    cout << "assertThat(calcPrimeFactors(11), {11})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(12), {2, 2, 3});
    cout << "assertThat(calcPrimeFactors(12), {2,2,3})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(13), {13});
    cout << "assertThat(calcPrimeFactors(13), {13})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(14), {2, 7});
    cout << "assertThat(calcPrimeFactors(14), {2,7})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(15), {3, 5});
    cout << "assertThat(calcPrimeFactors(15), {3,5})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(16), {2, 2, 2, 2});
    cout << "assertThat(calcPrimeFactors(16), {2,2,2,2})"
         << " -> " << stringResult(result) << endl;
    result = assertThat(calcPrimeFactors(2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23), {2, 3, 5, 7, 11, 13, 17, 19, 23});
    cout << "assertThat(calcPrimeFactors(2*3*5*7*11*13*17*19*23), {2,3,5,7,11,13,17,19,23})"
         << " -> " << stringResult(result) << endl;
}
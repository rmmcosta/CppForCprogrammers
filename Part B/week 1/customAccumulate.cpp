#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    double values[] = {1.0,2.0,3.0,4.0,5.5};
    double acc = accumulate(begin(values), end(values), 0.0);
    cout << "accumulate starting at 0.0 -> " << acc << endl;
    acc = accumulate(begin(values), end(values), 10.0);
    cout << "accumulate starting at 10.0 -> " << acc << endl;
    acc = accumulate(begin(values), end(values), 1.0, multiplies<double>());
    cout << "accumulate using a binary operator and starting at 1.0 -> " << acc << endl;
    acc = accumulate(begin(values), end(values), 10.0, minus<double>());
    cout << "accumulate using a binary operator and starting at 10.0 -> " << acc << endl;
    acc = accumulate(begin(values), end(values), 20.0, divides<double>());
    cout << "accumulate using a binary operator and starting at 20.0 -> " << acc << endl;
    return 0;
}
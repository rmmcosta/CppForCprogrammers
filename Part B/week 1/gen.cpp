#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Gen
{
public:
    Gen(double init, double inc) : curr(init), inc(inc){};
    double operator()()
    {
        curr += inc;
        return curr * curr;
    }

private:
    double curr, inc;
};

double integrate(Gen g, int n)
{
    vector<double> fx(n);
    generate(fx.begin(), fx.end(), g);
    return (accumulate(fx.begin(), fx.end(), 0.0)/n);
}

int main()
{
    Gen g1(0,1);
    for (int i = 0; i < 5; i++)
    {
        cout << g1() << "\t";
    }
    cout << endl;
    Gen g2(10.0, 5.0);
    for (int i = 0; i < 5; i++)
    {
        cout << g2() << "\t";
    }
    cout << endl;
    const int n = 10000;
    Gen g3(0.0,1.0/n);
    double integ = integrate(g3, n);
    cout << integ << endl;
    return 0;
}
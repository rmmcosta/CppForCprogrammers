#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void incr(int &v)
{
    static int x = 0;
    v = ++x;
};
void outvec(const int v)
{
    cout << v << endl;
};

int main()
{
    int values[] = {1, 2, 3};
    auto print = [](const int n) { cout << "n: " << n << endl; };
    for_each(begin(values), end(values), print);
    auto twice = [](int &n) { n *= 2; };
    for_each(begin(values), end(values), twice);
    for_each(begin(values), end(values), print);
    vector<int> v(6);
    for_each(v.begin(), v.end(), outvec);
    for_each(v.begin(), v.end(), incr);
    for_each(v.begin(), v.end(), outvec);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

template <typename FwdIter>
inline void myPrint(FwdIter start, FwdIter end, const char *title)
{
    cout << title << endl;
    while (start != end)
        cout << *start++ << "\t";
    cout << endl;
}

int main()
{
    vector<int> v(5,1);
    myPrint(v.begin(), v.end(), "all ones");
    int data[3] = {9,10,11};
    myPrint(data, data+3, "Original values");
    transform(data, data+3, data, bind2nd(multiplies<int>(), 2));
    myPrint(data, data+3, "New values");
    return 0;
}
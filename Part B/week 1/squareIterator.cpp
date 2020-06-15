#include <iostream>
#include <vector>
using namespace std;

template <typename squareIterator>
void rangeSquare(squareIterator start, squareIterator end)
{
    for (; start != end; start++)
    {
        *start = (*start) * (*start);
    }
}

template <typename T>
void printVector(const vector<T> &values)
{
    for (T v : values)
    {
        cout << v << "\t";
    }
    cout << endl;
}

template <typename T>
void rangeDouble(vector<T> &values)
{
    for (auto v = values.begin(); v != values.end(); v++)
    {
        *v = *v * 2;
    }
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    printVector(data);
    rangeSquare(data.begin(), data.end());
    printVector(data);
    rangeDouble(data);
    printVector(data);
    return 0;
}
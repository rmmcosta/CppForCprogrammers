#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline void printSeq(const vector<int> &seq)
{
    for (auto i : seq)
    {
        cout << i << "\t";
    }
    cout << endl;
}

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename bidirectional>
void myReverse(bidirectional begin, bidirectional end)
{
    --end; //because the end points to a non-value after the last value
    while (begin < end)
    {
        swap(*begin, *end);
        begin++;
        end--;
    }
}

int main()
{
    const int kMax = 5;
    vector<int> seq(kMax);
    for (int i = 0; i < kMax; i++)
    {
        seq[i] = i * 5;
    }
    printSeq(seq);
    reverse(seq.begin(), seq.end());
    printSeq(seq);
    myReverse(seq.begin(), seq.end());
    printSeq(seq);
    return 0;
}
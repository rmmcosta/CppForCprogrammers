#include <iostream>
#include "hoareQuickSort.cpp"
#include <algorithm>
#include <chrono>
using namespace std;
const int kNums = 10000000;

inline int getRandomInt()
{
    return rand();
}

int main()
{
    vector<int> values(kNums);
    for (int i = 0; i < kNums; i++)
    {
        values[i] = getRandomInt();
    }
    cout << "before stl sort" << endl;
    //printVector(values);
    auto t1 = chrono::high_resolution_clock::now();
    sort(values.begin(), values.end());
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "after stl sort with a duration of " << duration << endl;
    for (int i = 0; i < kNums; i++)
    {
        values[i] = getRandomInt();
    }
    cout << "before my sort" << endl;
    t1 = chrono::high_resolution_clock::now();
    hoareSort(values.begin(), values.end());
    t2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "after my sort with a duration of " << duration << endl;
    for (int i = 0; i < kNums; i++)
    {
        values[i] = getRandomInt();
    }
    cout << "before stl sort" << endl;
    //printVector(values);
    t1 = chrono::high_resolution_clock::now();
    sort(values.begin(), values.end());
    t2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "after stl sort with a duration of " << duration << endl;
    for (int i = 0; i < kNums; i++)
    {
        values[i] = getRandomInt();
    }
    cout << "before my sort" << endl;
    t1 = chrono::high_resolution_clock::now();
    hoareSort(values.begin(), values.end());
    t2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "after my sort with a duration of " << duration << endl;
    //printVector(values);
    return 0;
}
//  This is the converted C++ program
//  uses io
//  uses one line comments
//  uses constants const instead of define
//  uses vector<> instead of array
//  inlines short functions

using namespace std;
#include <iostream>
#include <vector>
const int N = 20;

inline void sumConsec(int *accum, int init, vector<int> nums)
{
    *accum = init;
    for (int i = 0; i < N; i++)
    {
        *accum += nums[i];
    }
}

int main()
{
    int init = 0;
    cout << "What is the initial value? ";
    cin >> init;
    // array time, or should I say vector<>
    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++)
    {
        nums[i] = i;
    }
    int accum = 0;
    sumConsec(&accum, init, nums);
    cout << "accumulated value -> " << accum << endl;
}
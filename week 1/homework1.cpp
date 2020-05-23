// This program is the result of the coversion of a C program
// stdio was changed to C++ io
// multiline comments were changed to one line comments
// defines of constants were changed to const
// the array was changed to vector<>
// inline was used for short function

#include <iostream>
#include <vector>
using namespace std; //by using the std namespace we don't need to use the std:: scope

const int N = 40;

//given the total of values (integers) that function needs to sum,
//given the numeric values,
//the sum result will be put in the given memory address
inline void sum(int &sumResult, int totalValues, vector<int> numValues)
{
    sumResult = 0;
    for (int i = 0; i < totalValues; ++i)
    {
        sumResult += numValues[i];
    }
}

int main()
{
    int accum = 0;
    vector<int> data(N, 0);
    //initialize data
    for (int i = 0; i < N; ++i)
    {
        data[i] = i;
    }
    sum(accum, N, data);
    cout << "The sum result is " << accum << endl;
    return 0;
}
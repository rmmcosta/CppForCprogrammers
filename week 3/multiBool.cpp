#include <iostream>
#include <ctime>
using namespace std;

float prob(int i)
{
    srand(time(0) + i);
    float prob = (float)rand() / RAND_MAX;
    return prob;
}

void fillMulti(bool *ptr, int size, float density)
{
    for (int i = 0; i < size * size; i++)
    {
        *(ptr + i) = prob(i) < density;
    }
}

int main()
{
    const int size = 5;
    bool multi[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "address: " << &multi[i][j] << endl;
        }
    }

    fillMulti((bool*)multi, size, 0.19);
    bool *multiPtr = (bool*)multi;
    for (int i = 0; i < size * size; i++)
    {
        cout << "value: " << *(multiPtr + i) << endl;
    }
    return 0;
}
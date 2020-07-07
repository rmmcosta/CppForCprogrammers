#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

bool isTrue()
{
    double x = (double)rand()*6 / RAND_MAX;
    return x < 1;
}

int main()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        cout << isTrue() << endl;
    }

    return 0;
}
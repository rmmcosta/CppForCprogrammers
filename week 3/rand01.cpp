#include <iostream>
#include <cstdlib>
using namespace std;

bool rand01() {
    return rand()%2;
}

int main() {
    for (int i = 0; i < 100; i++)
    {
        cout << rand01() << endl;
    }
    
}
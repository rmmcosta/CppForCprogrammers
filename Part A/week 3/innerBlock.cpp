#include <iostream>
using namespace std;

int main() {
    int i=2,j=3;
    cout << "i:" << i << "j:" << j << endl;
    {
        int i=j+2;
        cout << "block i:" << i << endl;
    }
}
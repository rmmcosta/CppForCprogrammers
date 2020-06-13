#include "unitTestFramework.hpp"
#include <iostream>

using namespace std;

template <class T>
inline int length(T theArray[]) {
    return sizeof(theArray)/sizeof(T);
}

/*int main() {
    int nums[] = {1,3,4,5};
    cout << "test passed: " << assertTrue(4, length(nums));
}*/
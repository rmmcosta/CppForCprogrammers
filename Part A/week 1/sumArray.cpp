#include <iostream>

inline int sumArrayInt(int nums[], int arrSize)
{
    int accum=0;
    int size = arrSize/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        accum+=nums[i];
    }
    return accum;
}

template <class T>
inline T sumArray(T values[], int arrSize) {
    T accum = 0;
    int size = arrSize/sizeof(T);
    for (int i = 0; i < size; i++)
    {
        accum+=values[i];
    }
    return accum;    
}

int main() {
    int myArr[] = {1,2,3,4,5};
    int accum = sumArrayInt(myArr, sizeof(myArr));
    std::cout << "accum int -> " << accum << std::endl;
    accum = sumArray(myArr, sizeof(myArr));
    std::cout << "accum -> " << accum << std::endl;
    double myArrD[] = {1.1,2.2,3.3,4.4,5.5};
    double accumD = sumArray(myArrD, sizeof(myArrD));
    std::cout << "accum double -> " << accumD << std::endl;
    char myArrC[] = {'a','e','i','o','u'};
    int accumC = sumArray(myArrC, sizeof(myArrC));
    std::cout << "accum char -> " << accumC << std::endl;
    std::cout << "test -> " << myArrC[0]+myArrC[1] << std::endl;
}
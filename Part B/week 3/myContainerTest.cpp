#include "myContainer.hpp"
#include <iostream>
using namespace std;

int main()
{
    MyContainer<char, 3> chars;
    cout << "size " << chars.getSize() << endl;
    chars[0] = 'A';
    chars[1] = 'n';
    chars[2] = 'a';
    cout << "chars " << chars << endl;
    MyContainer<char, 3> chars2(chars); //in order to this work fine
    //we need to define the copy constructor. If we don't do it
    //a copy constructor will be auto generated and only the private pointer will be assigned
    cout << chars2 << endl;
    char myName[7] = {'R', 'i', 'c', 'a', 'r', 'd', 'o'};
    cout << "char array myName " << myName << endl;
    MyContainer<char, 5> chars3(myName);
    cout << "chars3 " << chars3 << endl;
    MyContainer<char, 3> chars4;
    chars4 = move(chars); //uses the move constructor
    cout << "chars4 " << chars4 << endl;
    //cout << chars << endl;//chars doesn't exist anymore
    MyContainer<char, 3> aei;
    aei[0] = 'a';
    aei[1] = 'e';
    aei[2] = 'i';
    MyContainer<char, 3> oua;
    oua[0] = 'o';
    oua[1] = 'u';
    oua[2] = 'a';
    cout << "aei " << aei << endl;
    cout << "oua " << oua << endl;
    aei.swap(oua);
    cout << "aei " << aei << endl;
    cout << "oua " << oua << endl;
    for (auto iter = aei.begin(); iter != aei.end(); iter++)
    {
        cout << "inside iter " << *iter << endl;
    }

    return 0;
}
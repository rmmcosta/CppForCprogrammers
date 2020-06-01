#include "myList.hpp"
#include <iostream>
using namespace std;
using namespace MyList;

int main()
{
    List *list;
    {
        List tempList;
        tempList.print();
        tempList.prepend(5);
        cout << "getElement: " << tempList.getElement() << endl;
        tempList.prepend(14);
        tempList.prepend(3);
        tempList.print();
        list = &tempList;
    }
    list->print();
    return 0;
}
#include "myList.hpp"
#include <iostream>
using namespace std;
using namespace MyList;

int List::getElement()
{
    cout << "inside get element" << endl;
    return cursor->getData();
}

void List::prepend(int data)
{
    cursor = head = new ListElement(data, head);
}

void List::advance()
{
    cursor = cursor->getNext();
}

void List::print()
{
    if (head == nullptr)
    {
        cout << "empty list" << endl;
    }
    else
    {
        ListElement *printCursor = cursor;
        cout << printCursor->getData();
        printCursor = printCursor->getNext();
        while (printCursor)
        {
            cout << ", " << printCursor->getData();
            printCursor = printCursor->getNext();
        }
        cout << endl;
    }
}

List::~List()
{
    cout << "destructor called" << endl;
    //make sure the cursor is pointing to the head
    cursor = head;
    while (cursor)
    {
        cursor = head->getNext();
        delete head;
        head = cursor;
    }
}
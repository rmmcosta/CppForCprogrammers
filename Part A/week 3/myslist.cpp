#include <iostream>
using namespace std;

struct MySListElem
{
    char data;
    MySListElem *next;
};

class MySList
{
public:
    MySList() : head(0) {}
    ~MySList();
    void prepend(char c);
    void print();
    void del();

private:
    MySListElem *head; //head of the list
};

void MySList::prepend(char c)
{
    MySListElem *temp = new MySListElem;
    temp->data = c;
    temp->next = head; //points to the previous head
    head = temp;       //now becomes the head
}

void MySList::print()
{
    MySListElem *temp = head;
    if(!temp) { //empty list
        cout << "empty list";
    }
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl
         << "-----------" << endl;
}

void MySList::del()
{
    //move the head
    MySListElem *temp = head;
    head = head->next;
    //delete the previous head
    delete temp;
}

MySList::~MySList()
{
    cout << "destructor invoked" << endl;
    while (head)
    {
        del();
    }
}

int main()
{
    MySList *p;
    {
        MySList w;

        w.prepend('A');
        w.prepend('B');
        w.print();
        w.del();
        w.print();
        w.prepend('C');
        w.prepend('D');
        w.prepend('E');
        w.print();
        p = &w;
        p->print();
        cout << "exiting inner block" << endl;
    }
    //after this point list is empty
    p->print(); //gives system dependent behavior
    cout << "exiting outer block" << endl;
}
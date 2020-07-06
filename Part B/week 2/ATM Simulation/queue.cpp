#include "queue.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int kMaxDuration = 5;

int getRandDuration();

Queue::~Queue()
{
    delete front;
    delete back;
}

bool Queue::enqueue(int now)
{
    if (isFull)
    {
        cout << "The queue is full" << endl;
        return false;
    }
    if (isEmpty)
    {
        front = new Customer(now, getRandDuration());
        back = front;
    }
    Customer *temp = new Customer(now, getRandDuration());
    back->setNext(temp);
    back = temp;
    currSize++;
}

Customer &Queue::dequeue(int now)
{
    if (currSize == 0)
    {
        cout << "No one in the queue." << endl;
        return;
    }
    Customer temp = *front;
    front = &temp.getNext();
    front->setTurn(now);
    front->setNext(nullptr);
    currSize--;
    return temp;
}

bool Queue::isFull()
{
    return currSize == kMaxSize;
}

bool Queue::isEmpty()
{
    return currSize == 0;
}

ostream &operator<<(ostream &out, Queue &q)
{
    if(q.isEmpty())
    {
        cout << "No one in the queue" << endl;
        return out;
    }
    Customer *i = q.front;
    while(i!=nullptr)
    {
        cout << *i << endl;
    }
}

int getRandDuration()
{
    srand(time(0));
    return rand() % 5;
}
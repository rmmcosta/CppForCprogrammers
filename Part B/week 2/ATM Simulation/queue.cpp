#include "queue.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int kMaxDuration = 5;

int getRandDuration();

Queue::~Queue()
{
    Customer *temp;
    while (front != back)
    {
        temp = front;
        delete front;
        front = &(temp->getNext());
    }
    delete back;
}

bool Queue::enqueue(int now)
{
    if (isFull())
    {
        cout << "The queue is full" << endl;
        return false;
    }
    if (isEmpty())
    {
        front = new Customer(now, getRandDuration());
        back = front;
    }
    Customer *temp = new Customer(now, getRandDuration());
    back->setNext(temp);
    back = temp;
    currSize++;
    return true;
}

void Queue::dequeue(int now, Customer &customer)
{
    if (currSize == 0)
    {
        cout << "No one in the queue." << endl;
        return;
    }
    if(!front->isDone(now))
    {
        cout << "Not done yet" << endl;
        return;
    }
    customer = *front;
    front = &customer.getNext();
    front->setTurn(now);
    front->setNext(nullptr);
    currSize--;
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
    if (q.isEmpty())
    {
        cout << "No one in the queue" << endl;
        return out;
    }
    Customer *i = q.front;
    while (i != nullptr)
    {
        cout << *i << endl;
    }
    return out;
}

int getRandDuration()
{
    srand(time(0));
    return rand() % 5;
}
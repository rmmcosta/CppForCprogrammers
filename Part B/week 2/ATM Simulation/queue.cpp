#include "queue.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int kMaxDuration = 5;

int getRandDuration(int);

Queue::~Queue()
{
    //cout << "begin ~Queue" << endl;
    Customer *temp;
    while (front != back)
    {
        temp = front;
        delete front;
        front = temp->getNext();
    }
    delete back;
    //cout << "end ~Queue" << endl;
}

bool Queue::enqueue(int now)
{
    //cout << "enqueue " << now << endl;
    if (isFull())
    {
        //cout << "The queue is full" << endl;
        return false;
    }
    if (isEmpty())
    {
        //cout << "queue is empty to enqueue" << endl;
        front = new Customer(now, getRandDuration(now));
        front->setTurn(now);
        back = front;
        currSize++;
        //cout << "end enqueue was empty" << endl;
        return true;
    }
    Customer *temp = new Customer(now, getRandDuration(now));
    back->setNext(temp);
    back = temp;
    currSize++;
    //cout << "end enqueue" << endl;
    return true;
}

bool Queue::dequeue(int now, Customer &customer)
{
    if (currSize == 0)
    {
        //cout << "No one in the queue." << endl;
        return false;
    }
    if (!front->isDone(now))
    {
        //cout << "Not done yet" << endl;
        return false;
    }
    //cout << "start dequeue" << endl;
    customer = *front;
    if (customer.getNext() != nullptr)
    {
        front = customer.getNext();
        front->setTurn(now);
    }
    currSize--;
    //cout << "end dequeue" << endl;
    return true;
}

bool Queue::isFull()
{
    return currSize == kMaxSize;
}

bool Queue::isEmpty()
{
    return currSize == 0;
}

int Queue::getSize()
{
    //cout << "get size" << endl;
    return currSize;
}

ostream &operator<<(ostream &out, Queue &q)
{
    if (q.isEmpty())
    {
        cout << "No one in the queue" << endl;
        return out;
    }
    cout << "---------- queue -----------" << endl;
    Customer *i = q.front;
    while (i != nullptr)
    {
        cout << *i << endl;
        i = i->getNext();
    }
    return out;
}

int getRandDuration(int now)
{
    srand(time(0) / (now+1));
    return rand() % 5;
}
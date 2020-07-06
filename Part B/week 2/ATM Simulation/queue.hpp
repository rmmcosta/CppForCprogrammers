#include "customer.hpp"
#include <iostream>
using namespace std;

#ifndef QUEUE_HPP
#define QUEUE_HPP
const int kDefaultSize = 10;
class Queue
{
private:
    const int kMaxSize;
    Customer *front;
    Customer *back;
    int currSize;

public:
    Queue(int size = kDefaultSize) : kMaxSize(size), front(0), back(0), currSize(0){};
    ~Queue();
    bool enqueue(int);
    Customer &dequeue(int);
    bool isFull();
    bool isEmpty();
    friend ostream &operator<<(ostream &, Queue &);
};
#endif
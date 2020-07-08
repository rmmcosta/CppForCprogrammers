#include "customer.hpp"

Customer::~Customer()
{
    //cout << "begin ~Customer" << endl;
    //delete next;
    //cout << "end ~Customer" << endl;
}

void Customer::setTurn(int num)
{
    turn = num;
}

void Customer::setNext(Customer *nextCustomer)
{
    next = nextCustomer;
}

bool Customer::isDone(int num)
{
    return num >= (turn + took);
}

int Customer::getWait()
{
    return turn - arrive;
}

Customer *Customer::getNext() const
{
    return next;
}

ostream &operator<<(ostream &out, Customer &customer)
{
    out << "Customer arrived at " << customer.arrive
        << " and will take " << customer.took << " and is turn was at "
        << customer.turn << endl;
    return out;
}
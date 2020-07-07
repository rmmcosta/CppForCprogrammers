#include "customer.hpp"

Customer::~Customer()
{
    delete next;
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
Customer &Customer::getNext() const
{
    return *next;
}
ostream &operator<<(ostream &out, Customer &customer)
{
    out << "Customer arrived at " << customer.arrive << " and will take " << customer.took << endl;
    return out;
}
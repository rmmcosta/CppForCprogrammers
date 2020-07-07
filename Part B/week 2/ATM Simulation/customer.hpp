#include <iostream>
using namespace std;

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
class Customer
{
private:
    int arrive; //it's an int because it will be the number of cycles that passed when this customer arrived
    int turn;   //it's an int because it will be the number of cycles that passed when was this customer turn to use the ATM
    int took;   //...it's an because it will be the number of cycles that this Customer took in his turn at the Atm.
    Customer *next;

public:
    //given the current cycle and the task duration in number of cycles, creates a customer
    Customer(int now = 0, int taskDuration = 0) : arrive(now), took(taskDuration){};
    ~Customer();
    void setTurn(int);
    void setNext(Customer *);
    bool isDone(int); //given the number of cycles returns true if is done
    Customer &getNext() const;
    friend ostream &operator<<(ostream &, Customer &);
};
#endif
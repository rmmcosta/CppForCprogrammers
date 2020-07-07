#include "queue.hpp"
#include <vector>

const int kCycleDuration = 1; //duration in minutes

bool newCustomer(double);

int main()
{
    Queue q1;
    cout << q1;
    cout << "How many hours do you want to simulate? ";
    int hours;
    cin >> hours;
    cout << "How many customers per hour? ";
    double customerPerHour;
    cin >> customerPerHour;
    int cycles = hours * 60 / kCycleDuration;
    double minPerHour = 60 / customerPerHour;
    srand(time(0));
    int total = 0;
    Customer *temp = new Customer();
    vector<Customer *> customers;
    for (int i = 0; i < cycles; i += kCycleDuration)
    {
        if (newCustomer(minPerHour))
        {
            q1.enqueue(i);
            total++;
        }
        q1.dequeue(i, *temp);
        if (temp->isDone(i))
        {
            customers.push_back(temp);
            delete temp;
            temp = new Customer();
        }
    }
    cout << total << endl;
    cout << "atm customers " << customers.size() << endl;
    for (auto iter = customers.begin(); iter!= customers.end(); iter++)
    {
        cout << *(*iter) << endl;
    }
    return 0;
}

bool newCustomer(double minPerHour)
{
    return rand() * minPerHour / RAND_MAX < 1;
}
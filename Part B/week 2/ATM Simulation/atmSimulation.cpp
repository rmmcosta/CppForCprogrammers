#include "queue.hpp"
#include <cmath>
#include <vector>

const int kCycleDuration = 1; //duration in minutes

bool newCustomer(double);
double getAvgWaits(const vector<int> &);

int main()
{
    cout << "What will be the queue size? ";
    int queueSize;
    cin >> queueSize;
    Queue q1(queueSize);
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
    int served = 0;
    int turnaways = 0;
    double sumSizes = 0.0;
    Customer temp;
    vector<Customer> customers;
    vector<int> waits;
    for (int i = 0; i < cycles; i += kCycleDuration)
    {
        //cout << "i " << i << endl;
        sumSizes += q1.getSize();
        if (newCustomer(minPerHour))
        {
            if (q1.enqueue(i))
            {
                served++;
            }
            else
            {
                turnaways++;
            }
        }
        if (q1.dequeue(i, temp))
        {
            customers.push_back(temp);
            waits.push_back(temp.getWait());
        }
    }
    cout << "customers accepted " << served << endl;
    cout << "customers served " << customers.size() << endl;
    cout << "turnaways " << turnaways << endl;
    cout << "average waits " << getAvgWaits(waits) << endl;
    cout << "average sizes " << sumSizes / cycles << endl;
    // for (auto iter = customers.begin(); iter != customers.end(); iter++)
    // {
    //     cout << *iter << endl;
    // }
    customers.clear();
    waits.clear();
    return 0;
}

double getAvgWaits(const vector<int> &waits)
{
    double sum = 0.0;
    for (auto iter = waits.begin(); iter != waits.end(); iter++)
    {
        sum += *iter;
    }
    return sum / waits.size();
}

bool newCustomer(double minPerHour)
{
    //cout << "inside new customer " << minPerHour << endl;
    double res = rand() * minPerHour / RAND_MAX;
    //cout << "res " << res << endl;
    bool temp = res < 1;
    //cout << "temp " << temp << endl;
    return temp;
}
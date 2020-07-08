#include "queue.hpp"

int main()
{
    Queue q1;
    cout << "begin" << endl;
    cout << q1;
    cout << "enqueue" << endl;
    int i = 1;
    q1.enqueue(i);
    cout << q1;
    i++;
    q1.enqueue(i);
    i++;
    q1.enqueue(i);
    Customer c;
    cout << "dequeue" << endl;
    while (!q1.dequeue(i, c))
    {
        i++;
    };
    cout << "dequeue with " << i << endl;
    cout << q1;
    cout << "dispatched customer " << endl;
    cout << c;
    cout << "end" << endl;
    ;
    return 0;
}
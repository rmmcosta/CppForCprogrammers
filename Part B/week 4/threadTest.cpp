#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx;

void message1();
void multi(int &);

int main(int argc, char **argv)
{
    //thread with anonymous function
    thread foo([]() { cout << "inside the anonymous function" << endl; });
    thread th1(message1);
    th1.join();
    foo.join();
    int x = 1;
    cout << "value of x before threading:" << x << endl;
    int numThreads = 10;
    if (argc > 1)
        numThreads = atoi(argv[1]);
    cout << "number of threads:" << numThreads << endl;
    vector<thread> threads(numThreads);
    for (auto &t : threads)
        t = thread(multi, ref(x));
    for (auto &t : threads)
        t.join();
    cout << "value of x after threading:" << x << endl;
    return 0;
}

void message1()
{
    cout << "Write a message..." << endl;
}

void multi(int &x)
{
    //cout << "x:" << x << endl;
    mtx.lock();
    x += 10;
    mtx.unlock();
    //if we don't use lock unlock we will get different final values each time 
    //we run the program
}
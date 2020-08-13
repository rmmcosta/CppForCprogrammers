#include <thread>
#include <array>
#include <iostream>

using namespace std;

void myfunction()
{
    cout << "thread started" << endl;
}

int main()
{
    array<thread, 4> threads;

    for (auto & t : threads)
    {
        t = thread(myfunction);
    }

    cout << "waiting..." << endl;

    for (auto & t : threads)
    {
        t.join();
    }

    cout << "Done." << endl;
}
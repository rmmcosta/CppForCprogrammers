using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    const int MAX_VALUE = 13;
    int outcomes[MAX_VALUE];
    for (int i = 0; i < MAX_VALUE; i++)
    {
        outcomes[i] = 0;
    }
    cout << "How many throws do you want to consider? ";
    int throws;
    cin >> throws;
    srand(clock()); //initialize the seed for random numbers
    int outcome;
    for (int i = 0; i < throws; i++)
    {
        outcome = (rand() % 6 + 1) + (rand() % 6 + 1);
        outcomes[outcome]++;
    }
    double total = 0.0;
    double probability = 0.0;
    for (int i = 0; i < MAX_VALUE; i++)
    {
        probability = (double)outcomes[i] / throws * 100;
        total+=probability;
        if (outcomes[i] > 0)
        {
            cout << "Probability for " << i << " -> " << probability << endl;
        }
    }
    cout << total << endl;
}
#include <iostream>
#include "randGraph.hpp"
using namespace std;
using namespace myRandGraph;

void printGraph(bool *graph, int size)
{
    cout << "\t";
    for (int i = 0; i < size; i++)
    {
        cout << i << "\t";
    }
    cout << endl
         << endl;
    cout << 0 << "\t";
    for (int i = 0; i < size * size; i++)
    {
        cout << *(graph + i) << "\t";
        if (i > 0 && (i + 1) % size == 0) //change line
        {

            cout << endl
                 << endl;
            if ((i + 1) < size * size) //print line
            {
                //calc line
                int line = size - ((size * size - (i + 1)) / size);
                cout << line << "\t";
            }
        }
    }
}

int main()
{
    int size = 5;
    double prob = 0.19;
    bool graph[size][size];
    generateGraph(size, prob, (bool *)graph);
    printGraph((bool *)graph, size);
}
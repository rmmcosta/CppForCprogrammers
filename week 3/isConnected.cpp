//use the notion of open set and closed set
//to find out which nodes are connected
//to the open set goes the nodes that can be reached
//from node 0
//and to the closed set goes the nodes that were already
//reached
#include <iostream>
#include "randGraph.hpp"
#include <vector>
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

void printSet(bool *set, int size, string setName)
{
    cout << "---- " << setName << " ----" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "node: " << i << ", value: " << *(set + i) << endl;
    }
}

bool isConnected(bool *graph, int size)
{
    bool *closedSet = new bool[size];
    bool *openSet = new bool[size];
    for (int i = 0; i < size; i++)
    {
        *(closedSet + i) = *(openSet + i) = 0;
    }
    printSet(openSet, size, "open set");
    printSet(closedSet, size, "closed set");
    *openSet = 1;
    //nodes closed will be the id of the node (0,1,2,3,...,size)
    int nodesClosed = 0;
    while (nodesClosed < size)
    {
        //always start in the beginning of the line of the matrix
        for (int i = nodesClosed * size; i < nodesClosed * size + size; i++)
        {
            if (*(graph + i))
            {
                //calc column
                int col = i - nodesClosed * size;
                *(openSet + col) = 1;
            }
        }
        *(closedSet + nodesClosed) = 1;
        ++nodesClosed;
    }
    printSet(openSet, size, "open set");
    printSet(closedSet, size, "closed set");
    return 0;
}

int main()
{
    int size = 5;
    double prob = 0.19;
    bool graph[size][size];
    bool *const graphPtr = reinterpret_cast<bool *>(graph);
    generateGraph(size, prob, graphPtr);
    printGraph(graphPtr, size);
    isConnected(graphPtr, size);
}
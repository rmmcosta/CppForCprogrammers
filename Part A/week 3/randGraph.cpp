#include <cstdlib>
#include <ctime>
#include "randGraph.hpp"
using namespace std;
using namespace myRandGraph;

float myRandGraph::prob(int i)
{
    srand(time(0) + i);
    float prob = (float)rand() / RAND_MAX;
    return prob;
}

void myRandGraph::generateGraph(const int size, const double density, bool *graph)
{
    for (int i = 0; i < size * size; i++)
    {
        if (i % 2 != 0) //it's not the same node
            *(graph + i) = prob(i) < density;
        else
            *(graph + i) = 0;
    }
}
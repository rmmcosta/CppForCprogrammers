#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float prob()
{
    srand(time(0));
    float prob = (float)rand()/RAND_MAX;
    //cout << "prob: " << prob;
    return prob;
}

void generateGraph(int size, double density)
{
    bool **graph;
    graph = new bool *[size];
    for (int i = 0; i < size; i++)
    {
        graph[i] = new bool[size];
    }
    for (int i = 0; i < size; i++)
    {
        //cout << graph[i] << endl;
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                graph[i][j] = prob() < density;
            }
            cout << graph[i][j] << "\t";
        }
        cout << endl
             << endl;
    }
}

int main()
{
    int size = 5;
    double prob = 0.19;
    generateGraph(size, prob);
}
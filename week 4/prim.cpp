#include "randomGraph.hpp"
#include <iostream>
#include <algorithm>

const int kInfinity = 9999;

class MST
{
public:
    MST(int size, double density)
    {
        graph = new Graph(size, density);
        this->size = size;
    }
    int runPrim();
    ~MST();

private:
    int size;
    Graph *graph;
    vector<int> vertexes;
    vector<int> distances;
};

int MST::runPrim()
{
    graph->generateGraph();
    while (vertexes.size() < size)
    {
        vertexes.push_back(0);
        int finalDistance = kInfinity;
        int finalNum = -1;
        for (vector<int>::iterator itVertexes = vertexes.begin(); itVertexes != vertexes.end(); itVertexes++)
        {
            vector<Edge *> currEdges = graph->getEdges(*itVertexes);
            for (vector<Edge *>::iterator itEdges = currEdges.begin(); itEdges != currEdges.end(); itEdges++)
            {
                //check if this edge was reached yet. If so, jump to the next one.
                int edgeNum = (*itEdges)->getNum();
                if (count(vertexes.begin(), vertexes.end(), edgeNum))
                {
                    continue;
                }
                int edgeDistance = (*itEdges)->getDistance();
                if (edgeDistance < finalDistance)
                {
                    finalDistance = edgeDistance;
                    finalNum = edgeNum;
                }
            }
        }
        if (finalDistance == kInfinity) //connection not found
        {
            return -1;
        }
        vertexes.push_back(finalNum);
        distances.push_back(finalDistance);
    }
    int sum = 0;
    for (int i = 0; i < distances.size(); i++)
    {
        sum += distances[i];
    }
    return sum;
}

MST::~MST()
{
    delete graph;
    vertexes.clear();
    distances.clear();
}

int main()
{
    MST *mst = new MST(10, 0.8);
    int result = mst->runPrim();
    cout << "result:" << result << endl;
    delete mst;
    return 0;
}
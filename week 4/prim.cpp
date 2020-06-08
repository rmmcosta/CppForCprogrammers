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
	void printGraph();
    ~MST();

private:
    int size;
    Graph *graph;
    vector<int> vertexes;
    vector<int> distances;
	void printVertexes();
	void printDistances();
};

int MST::runPrim()
{
    graph->generateGraph();
	vertexes.push_back(0);        
    while (vertexes.size() < size)
    {
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

void MST::printGraph() 
{
	graph->printGraph();
	printVertexes();
	printDistances();
}

void MST::printVertexes()
{
	cout << endl << "Vertexes: " << vertexes[0];	
	for(int i=1; i<vertexes.size();i++)
	{
		cout << ", " << vertexes[i];
	}
	cout << endl;
}

void MST::printDistances()
{
	cout << endl << "Distances: " << distances[0];	
	for(int i=1; i<distances.size();i++)
	{
		cout << ", " << distances[i];
	}
	cout << endl;
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
	mst->printGraph();
    cout << "result:" << result << endl;
    delete mst;
    return 0;
}

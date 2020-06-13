#include "randomGraph.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <fstream>
#include <iterator>

const int kInfinity = 9999;

class MST
{
public:
    MST(){};
    MST(int size, double density = 0)
    {
        graph = new Graph(size, density);
        this->size = size;
    }
    int runPrim();
    void insertEdge(int, int, int);
    void insertFromFile(string);
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
    return accumulate(distances.begin(), distances.end(), 0);
}

void MST::insertEdge(int nodeOrigin, int nodeDestin, int distance)
{
    graph->insertEdge(nodeOrigin, nodeDestin, distance);
}

void MST::insertFromFile(string fileName)
{
    ifstream fin(fileName);
    istream_iterator<int> start(fin), end;
    //the first integer will give us the size
    vector<int> data(start, end);
    graph = new Graph(data[0], 0);
    this->size = data[0];
    for (int i = 1; i < data.size(); i+=3)
    {
        int nodeOrigin=data[i], nodeDestin=data[i+1], cost=data[i+2];
        insertEdge(nodeOrigin, nodeDestin, cost);
    }
}

void MST::printGraph()
{
    graph->printGraph();
    printVertexes();
    printDistances();
}

void MST::printVertexes()
{
    cout << endl
         << "Vertexes: " << vertexes[0];
    for (int i = 1; i < vertexes.size(); i++)
    {
        cout << ", " << vertexes[i];
    }
    cout << endl;
}

void MST::printDistances()
{
    cout << endl
         << "Distances: " << distances[0];
    for (int i = 1; i < distances.size(); i++)
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
    int size;
    double density;
    cout << "First let's test it with a random graph." << endl;
    cout << "Please tell us the size of the graph:";
    cin >> size;
    cout << "and the density:";
    cin >> density;
    MST *mst = new MST(size, density);
    int result = mst->runPrim();
    mst->printGraph();
    cout << "result:" << result << endl;
    delete mst;
    //MST *mst1 = new MST(9);
    //0-a, 1-b, 2-c, 3-d, 4-e, 5-f, 6-g, 7-h, 8-i
    // mst1->insertEdge(0, 1, 4);
    // mst1->insertEdge(0, 7, 8);
    // mst1->insertEdge(1, 0, 4);
    // mst1->insertEdge(1, 7, 11);
    // mst1->insertEdge(1, 2, 8);
    // mst1->insertEdge(2, 1, 8);
    // mst1->insertEdge(2, 3, 7);
    // mst1->insertEdge(2, 8, 2);
    // mst1->insertEdge(2, 5, 4);
    // mst1->insertEdge(3, 2, 7);
    // mst1->insertEdge(3, 4, 9);
    // mst1->insertEdge(3, 5, 14);
    // mst1->insertEdge(4, 3, 9);
    // mst1->insertEdge(4, 5, 10);
    // mst1->insertEdge(5, 6, 2);
    // mst1->insertEdge(5, 2, 4);
    // mst1->insertEdge(5, 4, 10);
    // mst1->insertEdge(5, 3, 14);
    // mst1->insertEdge(6, 7, 1);
    // mst1->insertEdge(6, 8, 6);
    // mst1->insertEdge(6, 5, 2);
    // mst1->insertEdge(7, 6, 1);
    // mst1->insertEdge(7, 0, 8);
    // mst1->insertEdge(7, 8, 7);
    // mst1->insertEdge(8, 7, 7);
    // mst1->insertEdge(8, 2, 2);
    // mst1->insertEdge(8, 6, 6);
    //---with file instead
    string fileName;
    cout << "Now you can input your own graph." << endl;
    cout << "what's the file name:";
    cin >> fileName;
    MST *mst1 = new MST();
    mst1->insertFromFile(fileName);
    int result1 = mst1->runPrim();
    mst1->printGraph();
    cout << "result1:" << result1 << endl;
    return 0;
}

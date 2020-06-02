//Possible solution for the average shortest path
//when computing a set of randomly generated graphs.
//there are 2 possible data structures to represent graphs:
//        - connectivity matrix (also distances)
//            - dense graphs
//        - edge list representation
//            - sparse graphs (the majority of problems)
//        - there are advantages and disadvantages:
//           - the choice depends on:
//                - how much data do you want to store
//                - how efficient do you need the algorithm to be
//for those reasons, here we will choose edge list representation

#include <iostream>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

class Edge
{
public:
    Edge(int num = 0, int distance = 0) : num(num), distance(distance) {}

private:
    int num;
    int distance;
};

class Graph
{
public:
    Graph(int size, double density, int distMin = 1, int distMax = 10) : size(size), density(density), distMin(distMin), distMax(distMax) {}
    void generateGraph();
    int runDijkstra();
    void print();
    ~Graph();

private:
    int size;
    double density;
    int distMin, distMax;
    map<int, vector<Edge *>> edges;
};

double prob(int i, int j)
{
    srand(time(0) + i + j);
    double prob = static_cast<double>(rand() / RAND_MAX);
    return prob;
}

int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void Graph::generateGraph()
{
    vector<Edge *> adjacents;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && prob(i, j) <= density) //it's not the same node
                adjacents.push_back(new Edge(j, getRandom(distMin, distMax)));
        }
        edges.insert(pair<int, vector<Edge *>>(i, adjacents));
        adjacents.clear();
    }
}

void Graph::print() {
    for (map<int, vector<Edge *>>::iterator it = edges.begin(); it != edges.end(); ++it)
    {
        cout << "key:" << it->first << " ->{";
        for (int i = 0; i < it->second.size(); i++)
        {
            if(i>0) {
                cout << ",";
            }
            cout << it->second[i];
        }
        cout << "}" << endl;        
    }
}

Graph::~Graph()
{
    //clear each adjacent
    for (map<int, vector<Edge *>>::iterator it = edges.begin(); it != edges.end(); ++it)
    {
        it->second.clear();
    }
    //clear map
    edges.clear();
}

class Average
{
public:
    void append(int path);

private:
    vector<int> paths;
};

int main()
{
    Graph *g1 = new Graph(10,0.1);
    g1->generateGraph();
    g1->print();
    return 0;
}
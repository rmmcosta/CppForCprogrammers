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
#include <algorithm>
using namespace std;

class Edge
{
public:
    Edge(int num = 0, int distance = 0) : num(num), distance(distance) {}
    int getNum()
    {
        return num;
    }
    int getDistance()
    {
        return distance;
    }

private:
    int num;
    int distance;
};

class Graph
{
public:
    Graph(int size, double density, int distMin = 1, int distMax = 10) : size(size), density(density), distMin(distMin), distMax(distMax) {}
    void generateGraph();
    void runDijkstra();
    double calcAverage();
    void printGraph();
    void printResult();
    void printAverage();
    ~Graph();

private:
    int size;
    double density;
    int distMin, distMax;
    map<int, vector<Edge *>> edges;
    map<int, int> distances;
};

float prob(int i, int j)
{
    srand(time(0) + i + j);
    float prob = static_cast<float>(rand()) / RAND_MAX;
    //cout << "prob:" << prob << "rand max:" << RAND_MAX << endl;
    return prob;
}

int getRandom(int min, int max, int i, int j)
{
    srand(time(0) + i + j);
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
                adjacents.push_back(new Edge(j, getRandom(distMin, distMax, i, j)));
        }
        edges.insert(pair<int, vector<Edge *>>(i, adjacents));
        adjacents.clear();
    }
}

void Graph::runDijkstra()
{
    //we need 2 vectors
    //one for the nodes in the graph Q
    //another for the nodes already visited
    //we also need a map with distances from
    //the source node s to each node in the graph
    //Q here will be called nodes
    vector<int> nodes(size);
    //S here will be called nodesVisited
    vector<int> nodesVisited;
    //dist here will be called distances
    //While Q is not empty,
    //pop the node v, that is not already in S,
    //from Q with the smallest dist (v).

    //initializes
    const int INFINITY = 99;
    //insert origin node
    distances.insert(pair<int, int>(0, 0));
    nodes[0] = 0;
    for (int i = 1; i < size; i++)
    {
        nodes[i] = i;
        distances.insert(pair<int, int>(i, INFINITY));
    }

    while (!nodes.empty())
    {
        int finalNode;
        int finalDist = INFINITY;
        // cout << "-----------" << endl
        //      << "num of nodes: " << size << endl;
        for (int i = 0; i < size; i++)
        {
            int currNode = nodes[i];
            //cout << "current node: " << currNode << endl;
            //check if the current node was already visited
            if (count(nodesVisited.begin(), nodesVisited.end(), currNode))
            {
                //go to the next node
                continue;
            }
            //retrieve the distance to the current node
            int currDist = distances.find(currNode)->second;
            if (currDist <= finalDist)
            {
                finalDist = currDist;
                finalNode = currNode;
            }
        }
        nodesVisited.push_back(finalNode);
        //update all adjacent nodes (u), current node = v
        //dist(u) = dist(v) + weight(u,v)
        //get the adjacent nodes
        vector<Edge *> adjacentNodes = edges.find(finalNode)->second;
        for (Edge *adjacent : adjacentNodes)
        {
            // cout << "current node: " << finalNode << "adjacent node: " << adjacent->getNum() << endl;
            int currDistance = distances.find(adjacent->getNum())->second;
            int newDistance = finalDist + adjacent->getDistance();
            if (newDistance < currDistance)
            {
                distances.find(adjacent->getNum())->second = newDistance;
            }
        }
        adjacentNodes.clear();
        nodes.erase(remove(nodes.begin(), nodes.end(), finalNode), nodes.end());
    }
    nodesVisited.clear();
    nodes.clear();
}

double Graph::calcAverage()
{
    double sum = 0.0;
    for (map<int, int>::iterator it = distances.begin(); it != distances.end(); ++it)
    {
        sum += it->second;
    }
    return sum / size;
}

void Graph::printGraph()
{
    for (map<int, vector<Edge *>>::iterator it = edges.begin(); it != edges.end(); ++it)
    {
        cout << "key:" << it->first << " ->{";
        for (int i = 0; i < it->second.size(); i++)
        {
            if (i > 0)
            {
                cout << ",";
            }
            cout << "num:" << it->second[i]->getNum() << " distance:" << it->second[i]->getDistance();
        }
        cout << "}" << endl;
    }
}

void Graph::printResult()
{
    for (map<int, int>::iterator it = distances.begin(); it != distances.end(); ++it)
    {
        cout << "key:" << it->first << " distance: " << it->second << endl;
    }
}

void Graph::printAverage()
{
    cout << "For a graph with "
         << size << " nodes, a density of "
         << density << ", a max distance of "
         << distMax << " and a min distance of "
         << distMin << " the average distance to the computed nodes is "
         << calcAverage() << endl;
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

int main()
{
    Graph *g1 = new Graph(50, 0.2);
    g1->generateGraph();
    // g1->printGraph();
    g1->runDijkstra();
    // g1->printResult();
    // cout << g1->calcAverage() << endl;
    g1->printAverage();
    delete g1;
    Graph *g2 = new Graph(50, 0.4);
    g2->generateGraph();
    // g2->printGraph();
    g2->runDijkstra();
    // g2->printResult();
    // cout << g2->calcAverage() << endl;
    g2->printAverage();
    delete g2;
    return 0;
}
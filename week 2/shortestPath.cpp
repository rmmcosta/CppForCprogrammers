//given a set of nodes try to find the shortest
//path between one node and the other
//allow the user to input the nodes
//the start and the destination

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//Lets represent the infinity as the number 99
const int INFINITY = 99;

//class used to represent and adjacent node
class Adjacent
{
public:
    char node;
    int weight;
    Adjacent(char n, int w)
    {
        node = n;
        weight = w;
    }
};

vector<char> defineNodes()
{
    return {'S', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'T'};
}

//initialize distances -> 0 for start and "infinity" for the rest
void initializeDistances(map<char, int> &distances)
{
    distances.insert(pair<char, int>('S', 0));
    distances.insert(pair<char, int>('A', INFINITY));
    distances.insert(pair<char, int>('B', INFINITY));
    distances.insert(pair<char, int>('C', INFINITY));
    distances.insert(pair<char, int>('D', INFINITY));
    distances.insert(pair<char, int>('E', INFINITY));
    distances.insert(pair<char, int>('F', INFINITY));
    distances.insert(pair<char, int>('G', INFINITY));
    distances.insert(pair<char, int>('T', INFINITY));
}

//defines the adjacents for each node
void defineAdjacents(map<char, vector<Adjacent>> &adjacents)
{
    adjacents.insert(pair<char, vector<Adjacent>>('S', {*new Adjacent('A', 4), *new Adjacent('B', 3)}));
    adjacents.insert(pair<char, vector<Adjacent>>('A', {*new Adjacent('C', 1)}));
    adjacents.insert(pair<char, vector<Adjacent>>('B', {*new Adjacent('S', 3), *new Adjacent('D', 4)}));
    adjacents.insert(pair<char, vector<Adjacent>>('C', {*new Adjacent('D', 3), *new Adjacent('E', 1)}));
    adjacents.insert(pair<char, vector<Adjacent>>('D', {*new Adjacent('E', 1), *new Adjacent('F', 5), *new Adjacent('T', 3)}));
    adjacents.insert(pair<char, vector<Adjacent>>('E', {*new Adjacent('G', 2), *new Adjacent('T', 4)}));
    adjacents.insert(pair<char, vector<Adjacent>>('F', {}));
    adjacents.insert(pair<char, vector<Adjacent>>('G', {*new Adjacent('E', 2), *new Adjacent('T', 3)}));
    adjacents.insert(pair<char, vector<Adjacent>>('T', {*new Adjacent('F', 5)}));
}

//prints the final result
void printShortestPaths(map<char, int> &distances)
{
    for (pair<char, int> nodePair : distances)
    {
        cout << nodePair.first << " : " << nodePair.second << endl;
    }
}

//runs the dijkstra algorithm
void runDijkstra(vector<char> &nodes, vector<char> &nodesVisited, map<char, int> &distances, map<char, vector<Adjacent>> &adjacents)
{
    //While Q is not empty,
    //pop the node v, that is not already in S,
    //from Q with the smallest dist (v).
    while (!nodes.empty())
    {
        char finalNode;
        int finalDist = INFINITY;
        int nodesQty = nodes.size();
        cout << "-----------" << endl
             << "num of nodes: " << nodesQty << endl;
        for (int i = 0; i < nodesQty; i++)
        {
            char currNode = nodes[i];
            cout << "current node: " << currNode << endl;
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
        vector<Adjacent> adjacentNodes = adjacents.find(finalNode)->second;
        for (Adjacent adjacent : adjacentNodes)
        {
            int currDistance = distances.find(adjacent.node)->second;
            int newDistance = finalDist + adjacent.weight;
            if (newDistance < currDistance)
            {
                distances.find(adjacent.node)->second = newDistance;
            }
        }
        adjacentNodes.clear();
        nodes.erase(remove(nodes.begin(), nodes.end(), finalNode), nodes.end());
    }
}

int main()
{
    //we need 2 vectors
    //one for the nodes in the graph
    //another for the nodes already visited
    //we also need a map with distances from
    //the source node s to each node in the graph
    //Q here will be called nodes
    vector<char> nodes = defineNodes();
    //S here will be called nodesVisited
    vector<char> nodesVisited;
    //dist here will be called distances
    map<char, int> distances;
    //initialize distances
    initializeDistances(distances);
    //adjacent nodes and weights
    map<char, vector<Adjacent>> adjacents;
    defineAdjacents(adjacents);
    runDijkstra(nodes, nodesVisited, distances, adjacents);
    printShortestPaths(distances);
    nodes.clear();
    nodesVisited.clear();
    distances.clear();
    adjacents.clear();
    return 0;
}
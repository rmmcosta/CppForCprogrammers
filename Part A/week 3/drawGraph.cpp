#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_COST = 10;
const int MAX_NODES = 20;
const int MIN_NODES = 2;

struct Node
{
    int node;
    map<int, int> paths;
    void printPaths();
};

void Node::printPaths()
{
    map<int, int>::iterator it = paths.begin();
    while (it != paths.end())
    {
        if (it->second > 0)
            cout << "path to node: " << it->first << " with cost: " << it->second << endl;
        it++;
    }
}

inline void printNode(Node *node)
{
    cout << "node " << node->node << endl;
    node->printPaths();
}

class Graph
{
private:
    vector<Node *> nodes;
    int qty;

public:
    Graph()
    {
        srand((int)time(0));
        qty = rand() % MAX_NODES + MIN_NODES;
    } //afterwards if we want to generate a random number -> rand()%(max-min+1)+min;
    void generate();
    void print() const;
    ~Graph();
};

inline void deleteNode(Node *node)
{
    node->paths.clear();
}

Graph::~Graph()
{
    cout << "destructor called" << endl;
    for_each(nodes.begin(), nodes.end(), deleteNode);
    nodes.clear();
}

void Graph::generate()
{
    //fill the vector of nodes
    cout << "nodes: " << qty << endl;
    for (int i = 0; i < qty; i++)
    {
        cout << "i:" << i << endl;
        Node *currNode = new Node;
        currNode->node = i;
        for (int j = 0; j < qty; j++)
        {
            cout << "j: " << j << endl;
            bool hasPath = rand() % 2; // random 0 and 1
            if (hasPath && i != j)
            {
                int cost = rand() % MAX_COST + 1; //cost min 1
                cout << "cost: " << cost << endl;
                (currNode->paths).insert(pair<int, int>(j, cost));
            }
        }
        nodes.push_back(currNode);
    }
    //now we need to say which nodes have access to each other nodes
    //we can use a random between 0 and 1 while we are iterating the nodes
}

void Graph::print() const
{
    for_each(nodes.begin(), nodes.end(), printNode);
}

int main()
{
    Graph *myGraph = new Graph;
    myGraph->generate();
    myGraph->print();
    delete myGraph;
    return 0;
}
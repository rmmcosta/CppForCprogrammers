#include <iostream>
#include <map>
#include <vector>
#include <random>
using namespace std;

struct Node {
    int node;
    map<int, int> paths;
};

class Graph {
private:
    vector<Node*> nodes;
    int qty;
public:
    Graph():qty(qty){} //afterwards if we want to generate a random number -> rand()%(max-min+1)+min;
    void generate();
};

void Graph::generate() {
    //fill the vector of nodes
    for (int i = 0; i < qty; i++)
    {
        Node *currNode = new Node;
        currNode -> node = i;
        for (int i = 0; i < qty; i++)
        {

        }
        nodes.push_back(currNode);
    }
    //now we need to say which nodes have access to each other nodes
    //we can use a random between 0 and 1 while we are iterating the nodes
}
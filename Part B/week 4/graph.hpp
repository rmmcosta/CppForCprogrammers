#include <vector>
using namespace std;
#ifndef GRAPH_HPP
#define GRAPH_HPP

class Edge
{

};

class Graph
{
public:
    Graph(int hsize); //1 is 1x1, 11 is 11x11
    int who_won(); //special path algorithm (Special Dijkstra or the union find)
private:
    vector<vector<Edge>> g; //this will be used to define the graph
    //position 0 connects to certain edges, position 1 the same thing and so far and so forth
    int size;
    vector<int> stone; //0,1,2 -> 0 is empty
    //this int can be an enumerator
};

#endif
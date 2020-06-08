#include <vector>
#include <map>
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
    Graph(int, double);
    void generateGraph();
    void printGraph();
    vector<Edge *> getEdges(int node);
	void insertEdge(int, int, int);
    ~Graph();

private:
    int size;
    double density;
    int distMin, distMax;
    map<int, vector<Edge *>> edges;
};

#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include "randomGraph.hpp"
using namespace std;

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

Graph::Graph(int size, double density)
{
    this->size = size;
    this->density = density;
    this->distMin = 1;
    this->distMax = 10;
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

vector<Edge *> Graph::getEdges(int node)
{
    return edges.at(node);
}

void Graph::printGraph()
{
    cout << "--------";
    cout << " Graph ";
    cout << "--------";
    cout << endl;
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

void Graph::insertEdge(int nodeOrigin, int nodeDestin, int distance)
{
	//first let's see if the nodeOrigin is already in the edges map
	if(edges.find(nodeOrigin)!=edges.end())
	{
		edges.find(nodeOrigin)->second.push_back(new Edge(nodeDestin, distance));
	}
	else
	{
		edges.insert(pair<int, vector<Edge*>>(nodeOrigin, {new Edge(nodeDestin, distance)}));
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

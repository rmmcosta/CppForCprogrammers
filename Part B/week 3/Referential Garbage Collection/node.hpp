
#pragma once
#include "tree.hpp"
#include <iostream>
using namespace std;

class Node
{
    friend class Tree;
    friend ostream &operator<<(ostream &, const Tree &);
    int use;

protected:
    Node() { use = 1; }
    virtual void print(ostream &) = 0;
    virtual ~Node() {}
    virtual int eval() = 0;
};
#pragma once
#include "node.hpp"
class Tree
{
    friend class Node;
    friend ostream &operator<<(ostream &, const Tree &);
    Node *p;

public:
    Tree(int);
    Tree(char);
    Tree(char *, Tree);
    Tree(char *, Tree, Tree);
    Tree(const Tree &t)
    {
        p = t.p;
        ++p->use;
    }
    ~Tree()
    {
        if (--p->use == 0)
            delete p;
    }
    void operator=(const Tree &t);
    int eval() { return p->eval(); }
};

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

class LeafNode : public Node
{
    friend class Tree;
    void print(ostream &) = 0;
    virtual int eval() = 0;
};

class IntNode : public LeafNode
{
    friend class Tree;
    int n;
    void print(ostream &out) { out << n; };
    IntNode(int k) : n(k) {}

public:
    int eval() { return n; }
};

class IdNode : public LeafNode
{
    friend class Tree;
    char name;
    void print(ostream &out) { out << name; }
    IdNode(char id) : name(id) {}

public:
    int eval() { vatltab[name]; }
};

class UnaryNode : public Node
{
    friend class Tree;
    char *op;
    Tree opnd;
    UnaryNode(char *a, Tree b) : op(a), opnd(b) {}
    void print(ostream &out) { out << "(" << op << opnd << ")"; }

public:
    int eval();
};

class BinaryNode : public Node
{
    friend class Tree;
    char *op;
    Tree left;
    Tree right;
    BinaryNode(char *a, Tree b, Tree c) : op(a), left(b), right(c) {}
    void print(ostream &out) { out << "(" << left << op << right << ")"; }

public:
    int eval();
};
#pragma once
#include <iostream>
#include <string>
using namespace std;

extern int valtab[127];

class Tree;

class Node
{
    friend class Tree;
    friend ostream &operator<<(ostream &, const Tree &);
    int use;

protected:
    Node() {
        use = 1;
    }
    virtual void print(ostream &) = 0;
    virtual ~Node() {}
    virtual int eval() = 0;
};

class Tree
{
    friend class Node;
    friend ostream &operator<<(ostream &, const Tree &);
    Node *p;

public:
    Tree(int);
    Tree(char);
    Tree(string, Tree);
    Tree(string, Tree, Tree);
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
    int eval() {
        return p->eval();
    }
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
    void print(ostream &out) {
        out << n;
    };
    IntNode(int k) : n(k) {}

public:
    int eval() {
        return n;
    }
};

class IdNode : public LeafNode
{
    friend class Tree;
    char name;
    void print(ostream &out) {
        out << name;
    }
    IdNode(char id) : name(id) {}

public:
    int eval() {
        return valtab[name];
    }
};

class UnaryNode : public Node
{
    friend class Tree;
    string op;
    Tree opnd;
    UnaryNode(string a, Tree b) : op(a), opnd(b) {}
    void print(ostream &out) {
        out << "(" << op << opnd << ")";
    }

public:
    int eval();
};

class BinaryNode : public Node
{
    friend class Tree;
    string op;
    Tree left;
    Tree right;
    BinaryNode(string a, Tree b, Tree c) : op(a), left(b), right(c) {}
    void print(ostream &out) {
        out << "(" << left << op << right << ")";
    }

public:
    int eval();
};
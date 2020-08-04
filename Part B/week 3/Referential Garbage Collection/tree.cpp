#include "tree.hpp"

ostream &operator<<(ostream &out, const Tree &t)
{
    t.p->print(out);
    return out;
}

Tree::Tree(int n)
{
    p = new IntNode(n);
}

Tree::Tree(char c)
{
    p = new IdNode(c);
}

Tree::Tree(char *op, Tree t)
{
    p = new UnaryNode(op, t);
}

Tree::Tree(char *op, Tree l, Tree r)
{
    p = new BinaryNode(op, l, r);
}
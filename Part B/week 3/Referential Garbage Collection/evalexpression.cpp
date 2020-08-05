#include "evalexpression.hpp"

int UnaryNode::eval()
{
    switch (op[0])
    {
    case '-':
        return -opnd.eval();
    case '+':
        return +opnd.eval();
    default:
        cerr << "no valid operand" << endl
             << endl;
        return 0;
    }
}

int BinaryNode::eval()
{
    switch (op[0])
    {
    case '+':
        return left.eval() + right.eval();
    case '-':
        return left.eval() - right.eval();
    case '*':
        return left.eval() * right.eval();
    case '/':
        return left.eval() / right.eval();
    case '%':
        return left.eval() % right.eval();
    default:
        cerr << "no valid operator" << endl
             << endl;
        return 0;
    }
}

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

Tree::Tree(string op, Tree t)
{
    p = new UnaryNode(op, t);
}

Tree::Tree(string op, Tree l, Tree r)
{
    p = new BinaryNode(op, l, r);
}
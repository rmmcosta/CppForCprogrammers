#include "node.hpp"

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
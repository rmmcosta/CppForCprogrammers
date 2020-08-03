#include "tictactoe.hpp"

Symbol evaluateDiagonals(Board &);
Symbol evaluateDiagonal00(Board &);
Symbol evaluateDiagonal20(Board &);
Symbol evaluateLines(Board &);
Symbol evaluateColumns(Board &);

ostream &operator<<(ostream &out, Symbol &s)
{
    if (s == Symbol::O)
        out << "o";
    if (s == Symbol::X)
        out << "x";
    if (s == Symbol::None)
        out << " ";
    return out;
}

ostream &operator<<(ostream &out, Player &p)
{
    out << p.symbol;
    return out;
}

ostream &operator<<(ostream &out, Board &b)
{
    for (int j = 0; j < b.size; j++)
    {
        out << "----";
    }
    out << "-" << endl;
    for (int i = 0; i < b.size; i++)
    {
        out << "| ";
        for (int j = 0; j < b.size; j++)
        {
            Player p = b.getPlayer_forPosition(i, j);
            out << p << (j == b.size - 1 ? " |" : " | ");
        }
        out << endl;
        for (int j = 0; j < b.size; j++)
        {
            out << "----";
        }
        out << "-" << endl;
    }
    return out;
}

Player Board::getPlayer_forPosition(int x, int y)
{
    string position = to_string(x) + "," + to_string(y);
    if (moves.find(position) != moves.end())
        return *(moves.find(position)->second);
    Player none;
    return none;
}

void Board::makeMove(int x, int y)
{
    if (turn == nullptr || p1 == nullptr || p2 == nullptr)
        cout << "Please define the players!" << endl;
    if (isOver)
    {
        cout << "Game is over!" << endl;
        evaluate();
    }
    string position = to_string(x) + "," + to_string(y);
    moves.insert(pair<string, Player *>(position, turn));
    if (turn == p1)
        turn = p2;
    else
        turn = p1;
}

void Board::definePlayers(Player *first, Player *second)
{
    turn = first;
    p1 = first;
    p2 = second;
}

void Board::evaluate()
{
    if (moves.size() == 0)
    {
        cout << "New game" << endl;
        return;
    }
    //not enough moves to win
    if (moves.size() < 2 * size - 1)
        return;
    //brute force algorithm
    //diagonals, lines and columns
    Symbol s = evaluateDiagonals(*this);
    if (s == Symbol::None)
        s = evaluateColumns(*this);
    if (s == Symbol::None)
        s = evaluateLines(*this);
    if (s != Symbol::None)
    {
        cout << "Player " << s << " Won!" << endl;
        isOver = true;
        return;
    }
    //draw
    if (moves.size() == size * size)
    {
        cout << "It's a draw" << endl;
        isOver = true;
    }
}

Symbol evaluateDiagonals(Board &b)
{
    Symbol s = evaluateDiagonal00(b);
    if (s != Symbol::None)
        return s;
    s = evaluateDiagonal20(b);
    return s;
}

Symbol evaluateDiagonal00(Board &b)
{
    cout << "diagonal 00" << endl;
    //0,0-1,1-2,2
    int i = 0, j = 0;
    Symbol s = Symbol::None;
    while (i < b.getSize() && j < b.getSize())
    {
        if (b.getPlayer_forPosition(i, j).getSymbol() == Symbol::None)
            return Symbol::None;
        if (s == Symbol::None)
        {
            s = b.getPlayer_forPosition(i, j).getSymbol();
            i++;
            j++;
            continue;
        }
        if (s != b.getPlayer_forPosition(i, j).getSymbol())
        {
            return Symbol::None;
        }
        i++;
        j++;
    }
    return s;
}

Symbol evaluateDiagonal20(Board &b)
{
    //2,0-1,1-0,2
    cout << "diagonal 20" << endl;
    int i = 2, j = 0;
    Symbol s = Symbol::None;
    while (i >= 0 && j < b.getSize())
    {
        if (b.getPlayer_forPosition(i, j).getSymbol() == Symbol::None)
            return Symbol::None;
        if (s == Symbol::None)
        {
            s = b.getPlayer_forPosition(i, j).getSymbol();
            i--;
            j++;
            continue;
        }
        if (s != b.getPlayer_forPosition(i, j).getSymbol())
        {
            return Symbol::None;
        }
        i--;
        j++;
    }
    return s;
}

Symbol evaluateLines(Board &b)
{
    cout << "Lines" << endl;
    Symbol s = Symbol::None;
    //i is the line and j the column
    for (int i = 0; i < b.getSize(); i++)
    {
        for (int j = 0; j < b.getSize(); j++)
        {
            if (b.getPlayer_forPosition(i, j).getSymbol() == Symbol::None)
            {
                s = Symbol::None;
                break;
            }
            if (s == Symbol::None)
            {
                s = b.getPlayer_forPosition(i, j).getSymbol();
                continue;
            }
            if (s != b.getPlayer_forPosition(i, j).getSymbol())
            {
                s = Symbol::None;
                break;
            }
        }
        if (s != Symbol::None)
            return s;
    }
    return s;
}

Symbol evaluateColumns(Board &b)
{
    cout << "columns" << endl;
    Symbol s = Symbol::None;
    //i is the column and j the line
    for (int i = 0; i < b.getSize(); i++)
    {
        for (int j = 0; j < b.getSize(); j++)
        {
            if (b.getPlayer_forPosition(j, i).getSymbol() == Symbol::None)
            {
                s = Symbol::None;
                break;
            }
            if (s == Symbol::None)
            {
                s = b.getPlayer_forPosition(j, i).getSymbol();
                continue;
            }
            if (s != b.getPlayer_forPosition(j, i).getSymbol())
            {
                s = Symbol::None;
                break;
            }
        }
        if (s != Symbol::None)
            return s;
    }
    return s;
}
#include "tictactoe.hpp"

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
#include <iostream>
#include <map>
using namespace std;

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

enum class Symbol
{
    O,
    X,
    None
};

ostream &operator<<(ostream &, Symbol &);

class Player
{
private:
    Symbol symbol;

public:
    Player(Symbol s = Symbol::None) : symbol(s) {}
    friend ostream &operator<<(ostream &, Player &);
};

class Board
{
private:
    int size;
    map<string, Player *> moves;
    Player *turn;
    Player *p1, *p2;

public:
    Board(int s = 3) : size(s) {}
    friend ostream &operator<<(ostream &, Board &);
    Player getPlayer_forPosition(int, int);
    void definePlayers(Player *, Player *);
    void makeMove(int, int);
};
#endif
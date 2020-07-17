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
    bool isComputer;

public:
    Player(Symbol s = Symbol::None, bool isComputer = false) : symbol(s), isComputer(isComputer) {}
    friend ostream &operator<<(ostream &, Player &);
    Symbol getSymbol() const { return symbol; }
};

class Board
{
private:
    const int size;
    map<string, Player *> moves;
    Player *turn;
    Player *p1, *p2;
    bool isOver;

public:
    Board(int s = 3) : size(s) {}
    friend ostream &operator<<(ostream &, Board &);
    Player getPlayer_forPosition(int, int);
    void definePlayers(Player *, Player *);
    void makeMove(int, int);
    void evaluate();
    int getHowManyMoves() { return moves.size(); }
    int getSize() const { return size; }
    Player *getTurn();
    void makeAutoMove();
};
#endif
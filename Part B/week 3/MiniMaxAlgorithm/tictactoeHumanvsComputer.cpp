#include "tictactoe.hpp"

int main()
{
    Board b;
    Player *p1 = new Player(Symbol::O);
    Player *p2 = new Player(Symbol::X, true);
    b.definePlayers(p1, p2);
}
#include "tictactoe.hpp"

int main()
{
    Board b;
    cout << b;
    Player *p1 = new Player(Symbol::O);
    Player *p2 = new Player(Symbol::X);
    b.definePlayers(p1, p2);
    b.makeMove(0, 0);
    cout << b;
    b.makeMove(1, 1);
    cout << b;
    return 0;
}
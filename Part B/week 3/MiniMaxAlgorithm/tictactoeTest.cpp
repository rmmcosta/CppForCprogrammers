#include "tictactoe.hpp"

void winPO();
void winPX();
void draw();

int main()
{
    draw();
    winPO();
    winPX();
    return 0;
}

void winPO()
{
    Board b;
    cout << b;
    Player *p1 = new Player(Symbol::O);
    Player *p2 = new Player(Symbol::X);
    b.definePlayers(p1, p2);
    b.evaluate();
    //p1
    b.makeMove(0, 0);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 0);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(0, 1);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 1);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(0, 2);
    cout << b;
    b.evaluate(); //pO wins
}

void winPX()
{
    Board b;
    cout << b;
    Player *p1 = new Player(Symbol::O);
    Player *p2 = new Player(Symbol::X);
    b.definePlayers(p1, p2);
    b.evaluate();
    //p1
    b.makeMove(0, 0);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 1);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(0, 1);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(0, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(1, 2);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(2, 0);
    cout << b;
    b.evaluate(); //pX wins
}

void draw()
{
    Board b;
    cout << b;
    Player *p1 = new Player(Symbol::O);
    Player *p2 = new Player(Symbol::X);
    b.definePlayers(p1, p2);
    b.evaluate();
    //p1
    b.makeMove(0, 0);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(0, 1);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(1, 0);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(2, 0);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(1, 1);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(2, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(0, 2);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(2, 1);
    cout << b;
    b.evaluate(); //it's a draw
}
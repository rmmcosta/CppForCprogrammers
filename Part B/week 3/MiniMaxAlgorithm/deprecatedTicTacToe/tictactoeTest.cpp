#include "tictactoe.hpp"

void winPOLine();
void winPOColumn();
void winPODiagonal00();
void winPXLine();
void winPXColumn();
void winPXDiagonal20();
void draw();

int main()
{
    draw();
    winPOLine();
    winPOColumn();
    winPODiagonal00();
    winPXLine();
    winPXColumn();
    winPXDiagonal20();
    return 0;
}

void winPOColumn()
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
    b.makeMove(1, 0);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(2, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(2, 0);
    cout << b;
    b.evaluate(); //pO wins
}

void winPXColumn()
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
    b.makeMove(0, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(1, 1);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(2, 0);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(2, 2);
    cout << b;
    b.evaluate(); //px wins
}

void winPOLine()
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

void winPXLine()
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
    b.makeMove(2, 1);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 1);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(0, 2);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(1, 2);
    cout << b;
    b.evaluate(); //px wins
}

void winPXDiagonal20()
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

void winPODiagonal00()
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
    b.makeMove(1, 1);
    cout << b;
    b.evaluate();
    //p2
    b.makeMove(0, 2);
    cout << b;
    b.evaluate();
    //p1
    b.makeMove(2, 2);
    cout << b;
    b.evaluate();//pO wins
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
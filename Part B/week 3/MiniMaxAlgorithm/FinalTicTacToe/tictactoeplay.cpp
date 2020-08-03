#include "tictactoe.hpp"

int main()
{
	Board* b = new Board();
	b->showBoard();
	b->start();
	b->play();
	return 0;
}
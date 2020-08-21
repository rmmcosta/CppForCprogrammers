#include "board.hpp"

int main()
{
    Board b(11);
    b.print();
    b.setup();
    b.play();
    return 0;
}
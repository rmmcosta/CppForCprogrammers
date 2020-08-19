#include "board.hpp"

int main()
{
    Board b(3);
    b.print();
    b.setup();
    b.play();
    return 0;
}
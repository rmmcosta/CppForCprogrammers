#include "motifScrollBar.hpp"
#include <iostream>

void MotifScrollBar::scrollDown(int x)
{
    if (position - x >= 0)
    {
        position -= x;
        std::cout << "scrolled down " << x << std::endl;
    }
    else
    {
        std::cout << "can't scroll down " << x
                  << " because current position is " << position << std::endl;
    }
}

void MotifScrollBar::scrollUp(int x)
{
    position += x;
    std::cout << "scrolled up " << x << " new position is " << position << std::endl;
}
#include "pmScrollBar.hpp"
#include <iostream>

void PMScrollBar::scrollUp(int x)
{
    if (position + x <= 1000)
    {
        position += x;
        std::cout << "pm scroll up. the position is now " << position << std::endl;
    }
    else
        std::cout << "pm scroll up reached the max " << position << std::endl;
}

void PMScrollBar::scrollDown(int x)
{
    if (position - x >= 0)
    {
        position -= x;
        std::cout << "pm scroll down. the position is now " << position << std::endl;
    }
    else
        std::cout << "pm scroll down reached the min " << position << std::endl;
}
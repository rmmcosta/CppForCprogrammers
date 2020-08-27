#include "pmWindow.hpp"
#include <iostream>

void PMWindow::open()
{
    if (isOpen)
        std::cout << "pm window already open" << std::endl;
    else
    {
        isOpen = true;
        std::cout << "pm window is now open" << std::endl;
    }
}

void PMWindow::close()
{
    if (!isOpen)
        std::cout << "pm window already close" << std::endl;
    else
    {
        isOpen = false;
        std::cout << "pm window is now close" << std::endl;
    }
}
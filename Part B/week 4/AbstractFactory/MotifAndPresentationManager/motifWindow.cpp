#include "motifWindow.hpp"
#include <iostream>

void MotifWindow::open()
{
    if (isOpen)
        std::cout << "Motif Window is already open" << std::endl;
    else
    {
        isOpen = true;
        std::cout << "Motif Window open" << std::endl;
    }
}

void MotifWindow::close()
{
    if (!isOpen)
        std::cout << "Motif window is already close" << std::endl;
    else
    {
        isOpen = false;
        std::cout << "Motif window close" << std::endl;
    }
}
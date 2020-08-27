#include "motifWidgetFactory.hpp"
#include "motifWindow.hpp"
#include "motifScrollBar.hpp"
#include <iostream>

MotifWindow *MotifWidgetFactory::createWindow()
{
    std::cout << "create new motif window" << std::endl;
    return new MotifWindow;
}

MotifScrollBar *MotifWidgetFactory::createScrollBar()
{
    std::cout << "create new motif scroll bar" << std::endl;
    return new MotifScrollBar;
}
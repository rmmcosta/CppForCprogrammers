#include "pmWidgetFactory.hpp"
#include "pmWindow.hpp"
#include "pmScrollBar.hpp"
#include <iostream>

PMWindow *PMWidgetFactory::createWindow()
{
    std::cout << "create new pm window" << std::endl;
    return new PMWindow;
}

PMScrollBar *PMWidgetFactory::createScrollBar()
{
    std::cout << "create new pm scroll bar" << std::endl;
    return new PMScrollBar;
}
#ifndef WIDGETFACT_HPP
#define WIDGETFACT_HPP
#include "window.hpp"
#include "scrollBar.hpp"

class WidgetFactory
{
public:
    virtual Window* createWindow()=0;
    virtual ScrollBar* createScrollBar()=0;
};
#endif
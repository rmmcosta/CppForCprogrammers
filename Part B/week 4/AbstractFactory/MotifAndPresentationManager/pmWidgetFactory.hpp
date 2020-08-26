#ifndef PMWIDGETFACT_HPP
#define PMWIDGETFACT_HPP
#include "widgetFactory.hpp"
#include "pmWindow.hpp"
#include "pmScrollBar.hpp"
class PMWidgetFactory : public WidgetFactory
{
public:
    PMWindow *createWindow();
    PMScrollBar *createScrollBar();
};
#endif
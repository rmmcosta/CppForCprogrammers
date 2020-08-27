#ifndef MAKEFACTORY_HPP
#define MAKEFACTORY_HPP
#include "widgetFactory.hpp"
#include "scrollBar.hpp"
#include "window.hpp"
class MakeFactory
{
public:
    MakeFactory() = delete;
    MakeFactory(WidgetFactory &factory);
    void doOperation();

private:
    WidgetFactory *factory;
    ScrollBar *scrollBar;
    Window *window;
};
#endif
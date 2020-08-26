#ifndef MOTIFWIDGETFACT_HPP
#define MOTIFWIDGETFACT_HPP
#include "widgetFactory.hpp"
#include "motifScrollBar.hpp"
#include "motifWindow.hpp"
class MotifWidgetFactory : public WidgetFactory
{
public:
    MotifWindow *createWindow();
    MotifScrollBar *createScrollBar();
};
#endif
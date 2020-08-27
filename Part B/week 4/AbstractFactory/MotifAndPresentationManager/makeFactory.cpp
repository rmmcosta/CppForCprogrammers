#include "makeFactory.hpp"

MakeFactory::MakeFactory(WidgetFactory &factory)
{
    this->factory = &factory;
    this->scrollBar = this->factory->createScrollBar();
    this->window = this->factory->createWindow();
}

void MakeFactory::doOperation()
{

    scrollBar->scrollUp(10);
    scrollBar->scrollDown(10);
    window->open();
    window->close();
}
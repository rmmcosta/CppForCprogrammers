#ifndef PMWINDOW_HPP
#define PMWINDOW_HPP
#include "window.hpp"
class PMWindow : public Window
{
public:
    void open();
    void close();

private:
    bool isOpen = true;
};
#endif
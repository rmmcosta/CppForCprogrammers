#ifndef MOTIFWINDOW_HPP
#define MOTIFWINDOW_HPP
#include "window.hpp"
class MotifWindow : public Window
{
public:
    void open();
    void close();

private:
    bool isOpen = false;
};
#endif
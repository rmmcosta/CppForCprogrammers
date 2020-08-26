#ifndef MOTIFSCROLLBAR_HPP
#define MOTIFSCROLLBAR_HPP
#include "scrollBar.hpp"
class MotifScrollBar : public ScrollBar
{
public:
    void scrollUp(int);
    void scrollDown(int);

private:
    int position = 50;
};
#endif
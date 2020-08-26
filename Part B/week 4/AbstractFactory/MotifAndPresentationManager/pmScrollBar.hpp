#ifndef PMSCROLLBAR_HPP
#define PMSCROLLBAR_HPP
#include "scrollBar.hpp"
class PMScrollBar : public ScrollBar
{
public:
    void scrollUp(int);
    void scrollDown(int);

private:
    int position = 0;
};
#endif
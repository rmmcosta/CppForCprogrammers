#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP
class ScrollBar
{
public:
    virtual void scrollUp(int) = 0;
    virtual void scrollDown(int) = 0;
};
#endif
#include "makeFactory.hpp"
#include "pmWidgetFactory.hpp"
#include "motifWidgetFactory.hpp"

int main()
{
    PMWidgetFactory pmFactory;
    MakeFactory mf1(pmFactory);
    mf1.doOperation();
    MotifWidgetFactory mFactory;
    MakeFactory mf2(mFactory);
    mf2.doOperation();
    return 0;
}
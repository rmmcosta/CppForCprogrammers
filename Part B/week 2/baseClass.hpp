#ifndef BASE_HPP
#define BASE_HPP
class Base
{
    public:
        Base(); //this is the base constructor that is always called by default for every derived constructor.
        //unless we specify a different one
        Base(int);
};
#endif
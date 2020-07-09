#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP
template <typename T, int n>
class MyContainer
{
public:
    MyContainer() { a = new T[n]; }
    ~MyContainer() { delete[] a; }
    int getSize() const;

private:
    T *a;
};
#endif
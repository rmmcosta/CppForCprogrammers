#include <iostream>
using namespace std;
#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP
template <typename T, int n>
class MyContainer
{
public:
    MyContainer() { a = new T[n]; }
    explicit MyContainer(T *b) : MyContainer()
    {
        cout << "explicit constructor" << endl;
        for (int i = 0; i < n; i++)
            a[i] = b[i];
    } //with explicit we don't have conversions
    MyContainer(const MyContainer &arr) : MyContainer()
    {
        cout << "copy constructor" << endl;
        for (int i = 0; i < n; i++)
        {
            a[i] = arr[i];
        }

    } //copy constructor
    MyContainer(MyContainer &&b) noexcept
    {
        a = b.a;
        b.a = nullptr;
    } //move constructor (we also need to overload the assignment)
    ~MyContainer() { delete[] a; }
    int getSize() const { return n; };

    void swap(MyContainer &b)
    {
        MyContainer temp = move(b); //uses the overridden op= defined for move semantics
        b = move(*this);
        *this = move(temp);
    } //efficient swap -> o(1)

    T *begin()
    {
        return a;
    }

    T *end()
    {
        return a + n;
    }

    T &operator[](int i) { return a[i]; };
    T operator[](int i) const { return a[i]; }; //we need this for instance for the copy constructor
    //it's the read only cousin of the previous one
    MyContainer &operator=(MyContainer &&b) noexcept
    {
        a = b.a;
        b.a = nullptr;
        return *this; //we need to return the object itself not a pointer
    }

    friend ostream &operator<<(ostream &out, MyContainer &arr)
    {
        for (int i = 0; i < n; i++)
        {
            out << (arr[i] == '\0' ? '-' : arr[i]) << " ";
        }
        return out;
    }

private:
    T *a;
};
#endif
#include <type_traits>
#include <iostream>
using namespace std;

template <typename T>
void mySwap(T &, T &);

template <typename T>
void print2(const T &, const T &);

class MyReal
{
private:
    int real, imaginary;

public:
    MyReal(int real, int imaginary) : real(real), imaginary(imaginary) {}
    friend ostream &operator<<(ostream &, const MyReal &);
};

ostream &operator<<(ostream &out, const MyReal &mr)
{
    out << mr.real << "+" << mr.imaginary << "i";
    return out;
}

class MyNoCopy
{
public:
    MyNoCopy() = default;
    MyNoCopy(int x, int y) : x(x), y(y) {}
    MyNoCopy(const MyNoCopy &) = delete; //disallow swap
    void print() const
    {
        cout << x << ", " << y << endl;
    }

private:
    int x, y;
};

int main()
{
    int a = 2, b = 4;
    print2(a, b);
    mySwap(a, b);
    print2(a, b);
    MyReal r1(3, 2);
    MyReal r2(1, 5);
    print2(r1, r2);
    mySwap(r1, r2);
    print2(r1, r2);
    MyNoCopy mnc1(4, 4);
    mnc1.print();
    MyNoCopy mnc2(3, 3);
    mnc2.print();
    //swap(mnc1, mnc2);
    mnc1.print();
    mnc2.print();
}

template <typename T>
void print2(const T &a, const T &b)
{
    std::cout << a << ", " << b << std::endl;
}

template <typename T>
void mySwap(T &a, T &b)
{
    static_assert(std::is_copy_constructible<T>::value, "The objects you are passing must have a copy constructor!");
    auto temp = a;
    a = b;
    b = temp;
}
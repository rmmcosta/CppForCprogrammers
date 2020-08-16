#include <cstring>
#include <iostream>
using namespace std;

class MyString
{
public:
    MyString() = default;
    MyString(const char *s)
    {
        cout << "created!" << endl;
        size = strlen(s);
        data = new char[size];
        memcpy(data, s, size);
    }
    MyString(const MyString &ms)
    {
        cout << "copied!" << endl;
        size = ms.size;
        data = new char[size];
        memcpy(data, ms.data, size);
    }
    //move constructor
    MyString(MyString &&otherms)
    {
        cout << "moved!" << endl;
        size = otherms.size;
        data = move(otherms.data);

        otherms.size = 0;
        otherms.data = nullptr;
    }
    void printString() const
    {
        cout << data << endl;
    }
    MyString &operator=(MyString &&otherms)
    {
        cout << "assign move" << endl;
        size = otherms.size;
        data = move(otherms.data);

        otherms.size = 0;
        otherms.data = nullptr;
        return *this;
    }
    ~MyString()
    {
        cout << "destroyed!";
        if (size > 0)
        {
            cout << data;
            delete data;
        }
        cout << endl;
    }

private:
    char *data = nullptr;
    int size = 0;
};

class MyCenas
{
public:
    MyCenas() = default;
    MyCenas(const MyString &ms) : ms(ms) {}
    MyCenas(MyString &&otherms) : ms(move(otherms)) {}
    void print() { ms.printString(); }

private:
    MyString ms;
};

int main()
{
    MyString *ms = new MyString("Ricardo");
    ms->printString();
    MyString ms2(*ms);
    ms2.printString();
    MyString ms1; //only possible because of MyString() = default;
    MyString ms3("Manuel");
    ms3.printString();
    ms1 = move(ms3);
    ms1.printString();
    MyString ms4 = "Machado";
    ms4.printString();
    MyCenas mc("Costa");
    mc.print();
    cout << "-----------------" << endl
         << endl;
    MyCenas mc1("ricardo"); //using implicit MyString constructor. equivalent to MyCenas mc(MyString("ricardo"));
    mc1.print();
    MyCenas mc2;
    mc2 = move(mc1);
    mc2.print();
    return 0;
}
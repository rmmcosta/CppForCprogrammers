#include <iostream>
using namespace std;

class MyException : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "My Exception was thrown";
    }
} myex;

int main()
{
    try
    {
        throw myex;
    }
    catch (const MyException &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
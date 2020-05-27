#include <iostream>
using namespace std;

class Xpto
{
private:
    int coiso;
    char tal;

public:
    Xpto() : coiso(0), tal(' ') {}
    Xpto(int x, char c): coiso(x), tal(c) {}

    int getCoiso() {
        return coiso;
    }
    char getTal() {
        return tal;
    }
};

ostream &operator<<(ostream &out, Xpto x) {
    out << "coiso: " << x.getCoiso() << ", tal: " << x.getTal() << endl;
    return out;
}

int main()
{
    Xpto x{1, 'A'};
    Xpto y;
    cout << x;
    cout << y;
}
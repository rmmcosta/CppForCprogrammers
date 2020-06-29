#ifndef HEX_HPP
#define HEX_HPP
#include <map>
#include <string>
using namespace std;

enum class Color
{
    kBlue,
    kRed,
    kNone
};

class Board
{
public:
    Board(int);
    void start();
    bool play();
    friend ostream &operator<<(ostream &out, Board &b);
    void changeTurn();

private:
    map<string, Color> plays;
    int kSize;
    Color turn;
};
#endif
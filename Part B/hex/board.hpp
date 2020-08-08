#include <map>
#include <string>
using namespace std;
#ifndef BOARD_HPP
#define BOARD_HPP
enum class Choice {
    kNONE=0, kRED=1, kBLUE=2
};
class Board
{
private:
    map<string, Choice> moves;
    int size;
    void printMove(int, int);
    void printLineSeparator(int);
    void printColumnSeparator();
    void printIdent(int);
    string getTextPos(int, int);
    bool posFree(string pos);
    Choice turn;
    bool finish();
    Choice computer;
    void makeComputerMove();
    void printMoves();
public:
    Board(int size=11) :size(size) {}
    void setup();
    void play();
    void print();
    void makeMove(int, int);
};
#endif
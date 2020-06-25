#ifndef HEX_HPP
#define HEX_HPP
#include <map>
#include <string>
using namespace std;

const int kSize = 11;

enum class Color{kBlue, kRed};

class Board
{
    public:
        void print();
    private:
        map<string,Color> plays;
};
#endif
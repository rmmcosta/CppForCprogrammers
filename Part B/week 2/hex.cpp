#include <iostream>
#include "hex.hpp"
using namespace std;

Board::Board(int size = 11)
{
    kSize = size;
    turn = Color::kNone;
    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            plays.insert(pair<string, Color>(to_string(i) + "," + to_string(j), Color::kNone));
        }
    }
}

void Board::start()
{
    do
    {
        cout << "Red(r) or Blue(b). Please choose your color: ";
        char c;
        cin >> c;
        switch (c)
        {
        case 'b':
        case 'B':
            turn = Color::kBlue;
            break;
        case 'r':
        case 'R':
            turn = Color::kRed;
            break;
        default:
            turn = Color::kNone;
            break;
        }
    } while (turn == Color::kNone);
}

bool Board::play()
{
    if (turn == Color::kNone)
    {
        cout << "Please choose your turn." << endl;
        return false;
    }
    int i, j;
    cout << "i: ";
    cin >> i;
    cout << endl
         << "j: ";
    cin >> j;
    auto position = plays.find(to_string(i) + "," + to_string(j));
    cout << "key find " << position->first << endl;
    if (position == plays.end())
    {
        cout << "Invalid play." << endl;
        return false;
    }
    if(position->second != Color::kNone)
    {
        cout << "position already taken" << endl;
        play();
    }
    position->second = turn;
    changeTurn();
    return true;
}

void Board::changeTurn()
{
    switch (turn)
    {
    case Color::kBlue:
        turn = Color::kRed;
        break;
    case Color::kRed:
        turn = Color::kBlue;
        break;
    default:
        break;
    }
}

ostream &operator<<(ostream &out, Board &b)
{
    cout << endl
         << "-> Board" << endl;
    cout << endl;
    for (int i = 0; i < b.kSize; i++)
    {
        for (int j = 0; j < b.kSize; j++)
        {
            auto play = b.plays.find(to_string(i) + "," + to_string(j))->second;
            cout << (play == Color::kNone ? " " : (play == Color::kBlue ? "X" : "O"));
            cout << "|";
        }
        cout << endl;
        for (int x = 0; x < b.kSize; x++)
        {
            cout << "--";
        }
        cout << endl;
    }
    return out;
}

int main()
{
    Board *b = new Board();
    cout << *b;
    b->start();
    while(true)
    {
        b->play();
        cout << *b;
    }
    return 0;
}
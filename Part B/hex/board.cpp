#include "board.hpp"
#include <iostream>

void Board::print()
{
    for (int i = 0; i < size; i++)
    {
        printIdent(i*2);
        for (int j = 0; j < size; j++)
        {
            printMove(i, j);
            if (j<size-1)
                printColumnSeparator();
        }
        cout << endl;
        if (i<size-1)
            printLineSeparator(i);
    }

}

void Board::printMove(int i, int j)
{
    if (j>0)
        cout << " ";
    string pos = getTextPos(i, j);
    if (posFree(pos))
        cout << ".";
    else
    {
        if (moves.find(getTextPos(i, j))->second==Choice::kBLUE)
            cout << "X";
        if (moves.find(getTextPos(i, j))->second==Choice::kRED)
            cout << "O";
    }
    if (j<size-1)
        cout << " ";
}

string Board::getTextPos(int i, int j)
{
    return to_string(i)+","+to_string(j);
}

bool Board::posFree(string pos)
{
    return moves.find(pos)==moves.end();
}

void Board::printLineSeparator(int line)
{
    printIdent(line*2);
    for (int i = 0; i < size; i++)
    {
        if (i==0)
            cout << " ";
        cout << "\\";
        if (i<size-1)
            cout << " / ";
    }
    cout << endl;
}

void Board::printColumnSeparator()
{
    cout << "-";
}

void Board::printIdent(int identSize)
{
    for (int i = 0; i < identSize; i++)
    {
        cout << " ";
    }
}

void Board::setup()
{
    int option = 0;
    while (option < 1 || option > 2)
    {
        cout << "X - Starts first" << endl;
        cout << "O - goes next" << endl;
        cout << "Which one do you want:" << endl;
        cout << " 1 - start first" << endl;
        cout << " 2 - goes next" << endl;
        cin >> option;
    }
    if (option==1)
        computer = Choice::kRED;
    else
        computer = Choice::kBLUE;
    turn = Choice::kBLUE;
}

void Board::makeMove(int i, int j)
{
    if (moves.find(getTextPos(i, j))==moves.end())
    {
        moves.insert(pair<string, Choice>(getTextPos(i, j), turn));
        turn = turn==Choice::kBLUE?Choice::kRED:Choice::kBLUE;
    }
    else
    {
        cout << "Move already taken!" << endl;
    }
}

void Board::play()
{
    while (!finish())
    {
        if (turn != computer)
        {
            cout << "make your move" << endl;
            cout << "i: " << endl;
            int i;
            cin >> i;
            cout << "j: " << endl;
            int j;
            cin >> j;
            makeMove(i, j);
        }
        else
        {
            makeComputerMove();
        }
        print();
    }
}

void Board::makeComputerMove()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (posFree(getTextPos(i, j)))
            {
                makeMove(i, j);
                printMoves();
                return;
            }
        }
    }
}

ostream& operator<<(ostream& out, Choice& c)
{
    switch (c)
    {
    case Choice::kBLUE:
        out << "X";
        break;
    case Choice::kRED:
        out << "O";
        break;
    default:
        out << ".";
        break;
    }
    return out;
}

void Board::printMoves()
{
    cout << "moves:" << endl;
    for (auto it = moves.begin(); it !=moves.end();it++)
    {
        cout << it->first << ", " << it->second << endl;
    }
}

bool Board::finish()
{
    return moves.size() == size*size;
}
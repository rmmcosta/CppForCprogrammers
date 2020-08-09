#include "board.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random> 
#include <chrono>

const int kTrials = 100;

int getSimulatedWins(Board, string, Choice);

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

void Board::makeMove(string textPos)
{
    if (moves.find(textPos)==moves.end())
    {
        moves.insert(pair<string, Choice>(textPos, turn));
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
            makeMove(getTextPos(i, j));
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
    vector<string> freeMoves;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            string textPos = getTextPos(i, j);
            if (posFree(textPos))
            {
                freeMoves.push_back(textPos);
            }
        }
    }
    string bestMove;
    int bestWin = 0;
    int evaluatedMoves = 0;
    while (evaluatedMoves < freeMoves.size())
    {
        int wins = getSimulatedWins(*this, freeMoves[evaluatedMoves], this->turn);
        if (wins>bestWin)
        {
            bestWin = wins;
            bestMove=freeMoves[evaluatedMoves];
        }
        evaluatedMoves++;
    }
    this->makeMove(bestMove);
}

int getSimulatedWins(Board b, string firstMove, Choice turn)
{
    int numWins = 0;
    int numTrials = 0;
    b.insertMove(firstMove, turn);
    Choice nextTurn = turn==Choice::kRED?Choice::kBLUE:Choice::kRED;
    vector<string> freeMoves;
    for (int i = 0; i < b.getSize(); i++)
    {
        for (int j = 0; j < b.getSize(); j++)
        {
            string textPos = Board::getTextPos(i, j);
            if (b.posFree(textPos))
            {
                freeMoves.push_back(textPos);
            }
        }
    }
    while (numTrials<kTrials)
    {
        Board tempBoard = b;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle(freeMoves.begin(), freeMoves.end(), std::default_random_engine(seed));
        int movesLeft = freeMoves.size();
        for (int i = 0; i < movesLeft; i++)
        {
            if (i<=movesLeft/2)
                tempBoard.insertMove(freeMoves[i], nextTurn);
            else
                tempBoard.insertMove(freeMoves[i], nextTurn==Choice::kRED?Choice::kBLUE:Choice::kRED);
        }
        if (tempBoard.whoWon()==turn)
            numWins++;
        numTrials++;
    }
    return numWins;
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

void Board::insertMove(string s, Choice c)
{
    moves.insert(pair<string, Choice>(s, c));
}

Choice Board::whoWon()
{
    return turn;
}
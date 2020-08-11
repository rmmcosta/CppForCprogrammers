#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random> 
#include <chrono>

const int kTrials = 1000;

int getSimulatedWins(Board, string, Choice);
bool isPresentInVector(vector<string>, string);

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
        Choice c = whoWon();
        if (c==computer)
        {
            cout << "Computer wins"<< endl;
            break;
        }
        if (c!=Choice::kNONE)
        {
            cout << "you win"<< endl;
            break;
        }
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
        unsigned seed = chrono::system_clock::now().time_since_epoch().count()+numTrials;

        shuffle(freeMoves.begin(), freeMoves.end(), default_random_engine(seed));
        int movesLeft = freeMoves.size();
        for (int i = 0; i < movesLeft; i++)
        {
            if (i<movesLeft/2)
                tempBoard.insertMove(freeMoves[i], nextTurn);
            else
                tempBoard.insertMove(freeMoves[i], nextTurn==Choice::kRED?Choice::kBLUE:Choice::kRED);
        }
        //tempBoard.print();
        if (tempBoard.whoWon()==turn)
            numWins++;
        numTrials++;
    }
    //cout << "finished trials" << endl;
    //cout << "num wins" << numWins << endl;
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

void Board::buildConnections()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            vector<string> paths;
            //vertices with 2 paths
            if (i==0 && j==0)
            {
                paths.push_back(getTextPos(i, j+1));
                paths.push_back(getTextPos(i+1, j));
            }
            if (i==size-1 && j==size-1)
            {
                paths.push_back(getTextPos(i, j-1));
                paths.push_back(getTextPos(i-1, j));
            }
            //vertices with 3 paths
            if (i==0 && j==size-1)
            {
                paths.push_back(getTextPos(i, j-1));
                paths.push_back(getTextPos(i+1, j));
                paths.push_back(getTextPos(i+1, j-1));
            }
            if (i==size-1 && j==0)
            {
                paths.push_back(getTextPos(i-1, j));
                paths.push_back(getTextPos(i-1, j+1));
                paths.push_back(getTextPos(i, j+1));
            }
            //line nodes with 4 paths
            if (i==0 && j>0 && j<size-1)
            {
                paths.push_back(getTextPos(i, j-1));
                paths.push_back(getTextPos(i, j+1));
                paths.push_back(getTextPos(i+1, j-1));
                paths.push_back(getTextPos(i+1, j));
            }
            if (i==size-1 && j>0 && j<size-1)
            {
                paths.push_back(getTextPos(i, j-1));
                paths.push_back(getTextPos(i, j+1));
                paths.push_back(getTextPos(i-1, j+1));
                paths.push_back(getTextPos(i-1, j));
            }
            //column nodes with 4 paths
            if (j==0 && i>0 && i<size-1)
            {
                paths.push_back(getTextPos(i-1, j+1));
                paths.push_back(getTextPos(i, j+1));
                paths.push_back(getTextPos(i-1, j));
                paths.push_back(getTextPos(i+1, j));
            }
            if (j==size-1 && i>0 && i<size-1)
            {
                paths.push_back(getTextPos(i-1, j));
                paths.push_back(getTextPos(i+1, j));
                paths.push_back(getTextPos(i, j-1));
                paths.push_back(getTextPos(i+1, j-1));
            }
            //all the other node (6 paths)
            if (i>0 && i<size-1 && j>0 && j<size-1)
            {
                paths.push_back(getTextPos(i, j-1));
                paths.push_back(getTextPos(i, j+1));
                paths.push_back(getTextPos(i-1, j));
                paths.push_back(getTextPos(i-1, j+1));
                paths.push_back(getTextPos(i+1, j-1));
                paths.push_back(getTextPos(i+1, j));
            }
            connections.insert(pair<string, vector<string>>(getTextPos(i, j), paths));
        }
    }
    printConnections();
}

void Board::printConnections()
{
    for (auto it=connections.begin();it!=connections.end();it++)
    {
        cout << it->first << ": ";
        for (auto it2=it->second.begin();it2!=it->second.end();it2++)
            cout << *it2 << "\t";
        cout << endl;
    }
}

Choice Board::whoWon()
{
    //check blue path (Top-Bottom)
        //see if there's a connection between the first line and the last
    if (redWon())
        return Choice::kRED;
    //check red path (Left-Right)
        //see if there's a connection between the first column and the last
    if (blueWon())
        return Choice::kBLUE;
    return Choice::kNONE;
}

bool Board::redWon()
{
    bool result;
    for (int j = 0; j < size; j++)
    {
        vector<string> dummyVector;
        result = findWinPath(getTextPos(0, j), Choice::kRED, dummyVector);
        if (result)
            break;
    }
    //cout << "final red" << endl;
    return result;
}

bool Board::blueWon()
{
    bool result;
    for (int i = 0; i < size; i++)
    {
        vector<string> dummyVector;
        result = findWinPath(getTextPos(i, 0), Choice::kBLUE, dummyVector);
        if (result)
            break;
    }
    //cout << "final blue" << endl;
    return result;
}

bool Board::findWinPath(string pos, Choice c, vector<string> alreadyChecked)
{
    //cout << "find win path " << pos << endl;
    //cout << alreadyChecked.size() << endl;
    if (!isPresentInVector(alreadyChecked, pos))
        alreadyChecked.push_back(pos);
    if (moves.find(pos)->second!=c)
        return false;
    if (isFinalPosition(pos, c))
        return true;
    vector<string> possiblePaths = connections.find(pos)->second;
    bool result;
    for (auto it = possiblePaths.begin();it!=possiblePaths.end();it++)
    {
        while (it!=possiblePaths.end() && isPresentInVector(alreadyChecked, *it))
            it++;
        if (it==possiblePaths.end())
            break;
        //cout << "check result " << *it << endl;
        result = findWinPath(*it, c, alreadyChecked);
        //cout << "result " << result << endl;
        if (result)
            break;
    }
    //cout << "final result" << endl;
    return result;
}

bool Board::isFinalPosition(string pos, Choice c)
{
    //cout << "is final position" << endl;
    if (c==Choice::kRED) {
        int i = stoi(pos.substr(0, pos.find(",")));
        if (i==size-1)
            return true;
        else
            return false;
    }
    else {
        int j = stoi(pos.substr(pos.find(",")+1, string::npos));
        if (j==size-1)
            return true;
        else
            return false;
    }
}

bool isPresentInVector(vector<string> values, string value)
{
    //cout << "is present in vector " << value << endl;
    for (auto it = values.begin(); it != values.end(); it++)
    {
        if (*it==value)
            return true;
    }
    return false;
}

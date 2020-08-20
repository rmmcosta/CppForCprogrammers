#ifndef BOARD_HPP
#define BOARD_HPP
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <future>
#include <mutex>

const int kTrials = 1000;

using namespace std;

enum class Choice
{
    kNONE = 0,
    kRED = 1,
    kBLUE = 2
};

class Board
{
private:
    unordered_map<string, Choice> moves;
    unordered_map<string, vector<string>> connections;
    int size;
    void printMove(int, int);
    void printLineSeparator(int);
    void printColumnSeparator();
    void printIdent(int);
    Choice turn;
    bool finish();
    Choice computer;
    void buildConnections();
    void printConnections();
    bool blueWon();
    bool redWon();
    bool isFinalPosition(string, Choice);

public:
    Board(int size = 11) : size(size)
    {
        buildConnections();
    }
    ~Board();
    void setup();
    void manualSetup(Choice comp, Choice t)
    {
        computer = comp;
        turn = t;
    };
    void play();
    void print();
    void makeMove(string);
    void insertMove(string, Choice);
    int getSize()
    {
        return size;
    }
    static string getTextPos(int, int);
    bool posFree(string pos);
    Choice whoWon();
    bool findWinPath(string, Choice, vector<string> &);
    void printMoves();
    int getNumPlayedMoves() { return moves.size(); }
    vector<string> getFreeMoves();
    void makeComputerMove();
};

void getSimulatedWins(Board, const string &, Choice, int &, string &);
bool isPresentInVector(const vector<string> &, const string &);
void executeTrial(Board, vector<string>, Choice, Choice, int, int &);
void insertRandomMoves(Board &, vector<string>, Choice, Choice, int);

#endif
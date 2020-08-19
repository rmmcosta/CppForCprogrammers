#include "board.hpp"
#include <gtest/gtest.h>

TEST(BoardTest, SimulateWins)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("2,1", Choice::kRED);
    b->manualSetup(Choice::kBLUE, Choice::kBLUE);
    string firstMove = "0,2";
    int wins = 0;
    string bestMove;
    getSimulatedWins(*b, firstMove, Choice::kBLUE, wins, bestMove);
    ASSERT_EQ(wins, kTrials);
    ASSERT_EQ(firstMove, bestMove);
}

TEST(BoardTest, WhoWon)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("2,1", Choice::kRED);
    b->insertMove("0,2", Choice::kBLUE);
    ASSERT_EQ(Choice::kBLUE, b->whoWon());
}

TEST(BoardTest, FindWinPath)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("2,1", Choice::kRED);
    b->insertMove("0,2", Choice::kBLUE);
    vector<string> dummyVector;
    bool finalResult;
    b->findWinPath("0,0", Choice::kBLUE, dummyVector, finalResult);
    ASSERT_EQ(true, finalResult);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*bool isPresentInVector(const vector<string> &, const string &);
void executeTrial(Board, vector<string>, Choice, Choice, int, int &);*/
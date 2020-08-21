#include "board.hpp"
#include <gtest/gtest.h>

TEST(BoardTest, MakeComputerMove)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    int freeMoves = b->getFreeMoves().size();
    try
    {
        b->makeComputerMove();
        ASSERT_EQ(freeMoves - 1, b->getFreeMoves().size());
    }
    catch (...)
    {
        ASSERT_FALSE(true);
    }
}

TEST(BoardTest, SimulateWins)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("1,2", Choice::kRED);
    b->manualSetup(Choice::kBLUE, Choice::kBLUE);
    string firstMove = "0,2";
    int wins = 0;
    string bestMove;
    try
    {
        getSimulatedWins(*b, firstMove, Choice::kBLUE, wins, bestMove);
        ASSERT_GT(wins, 0);
        ASSERT_EQ(firstMove, bestMove);
    }
    catch (...)
    {
        ASSERT_FALSE(true);
    }
}

TEST(BoardTest, ExecuteTrial)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("1,2", Choice::kRED);
    b->insertMove("0,2", Choice::kBLUE);
    int numWins = 0;
    executeTrial(*b, b->getFreeMoves(), Choice::kRED, Choice::kBLUE, 1, numWins);
    ASSERT_EQ(0, numWins);
}

TEST(BoardTest, GetFreeMoves)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("1,2", Choice::kRED);
    b->insertMove("0,2", Choice::kBLUE);
    vector<string> freeMoves = b->getFreeMoves();
    vector<string> expectedFreeMoves(4);
    ASSERT_EQ(expectedFreeMoves.size(), freeMoves.size());
    expectedFreeMoves[0] = "1,0";
    expectedFreeMoves[1] = "1,1";
    expectedFreeMoves[2] = "2,0";
    expectedFreeMoves[3] = "2,1";
    sort(expectedFreeMoves.begin(), expectedFreeMoves.end());
    sort(freeMoves.begin(), freeMoves.end());
    ASSERT_EQ(expectedFreeMoves, freeMoves);
}

TEST(BoardTest, InsertRandomMoves)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("1,2", Choice::kRED);
    b->insertMove("0,2", Choice::kBLUE);
    vector<string> freeMoves = b->getFreeMoves();
    int numTrials = 0;
    while (numTrials < kTrials)
    {
        Board tempBoard = *b;
        insertRandomMoves(tempBoard, freeMoves, Choice::kRED, Choice::kBLUE, numTrials);
        ASSERT_EQ(0, tempBoard.getFreeMoves().size());
        ASSERT_EQ(Choice::kBLUE, tempBoard.whoWon());
        numTrials++;
    }
}

TEST(BoardTest, WhoWon)
{
    try
    {
        Board *b = new Board(3);
        b->insertMove("0,0", Choice::kBLUE);
        b->insertMove("2,2", Choice::kRED);
        b->insertMove("0,1", Choice::kBLUE);
        b->insertMove("1,2", Choice::kRED);
        b->insertMove("0,2", Choice::kBLUE);
        ASSERT_EQ(Choice::kBLUE, b->whoWon());
        Board *b1 = new Board(3);
        ASSERT_EQ(Choice::kNONE, b1->whoWon());
        b1->insertMove("0,0", Choice::kBLUE);
        ASSERT_EQ(Choice::kNONE, b1->whoWon());
    }
    catch (...)
    {
        ASSERT_FALSE(true);
    }
}

TEST(BoardTest, FindWinPath)
{
    Board *b = new Board(3);
    b->insertMove("0,0", Choice::kBLUE);
    b->insertMove("2,2", Choice::kRED);
    b->insertMove("0,1", Choice::kBLUE);
    b->insertMove("1,2", Choice::kRED);
    b->insertMove("0,2", Choice::kBLUE);
    vector<string> dummyVector;
    bool finalResult = b->findWinPath("0,0", Choice::kBLUE, dummyVector);
    ASSERT_EQ(true, finalResult);
    Board *b1 = new Board(3);
    dummyVector.clear();
    ASSERT_EQ(false, b1->findWinPath("0,0", Choice::kBLUE, dummyVector));
    b1->insertMove("0,0", Choice::kBLUE);
    dummyVector.clear();
    ASSERT_EQ(false, b1->findWinPath("0,0", Choice::kBLUE, dummyVector));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
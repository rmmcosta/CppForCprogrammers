#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;

const int kSuits = 4;
const int kRanks = 13;
const int kDeal = 5;
const int kTrials = 2;

enum class Suit
{
    kClubs,
    kDiamonds,
    kHearts,
    kSpades
};

Suit &operator++(Suit &s)
{
    switch (s)
    {
    case Suit::kClubs:
        s = Suit::kDiamonds;
        break;
    case Suit::kDiamonds:
        s = Suit::kHearts;
        break;
    case Suit::kHearts:
        s = Suit::kSpades;
        break;
    case Suit::kSpades:
        s = Suit::kClubs;
        break;
    default:
        s = Suit::kClubs;
        break;
    }
    return s;
}

ostream &operator<<(ostream &out, Suit s)
{
    switch (s)
    {
    case Suit::kClubs:
        out << "Clubs";
        break;
    case Suit::kDiamonds:
        out << "Diamonds";
        break;
    case Suit::kHearts:
        out << "Hearts";
        break;
    case Suit::kSpades:
        out << "Spades";
        break;
    default:
        out << " ";
        break;
    }
    return out;
}

enum class Rank
{
    kAce,
    kTwo,
    kThree,
    kFour,
    kFive,
    kSix,
    kSeven,
    kEight,
    kNine,
    kTen,
    kJack,
    kQueen,
    kKing
};

Rank &operator++(Rank &r)
{
    switch (r)
    {
    case Rank::kAce:
        r = Rank::kTwo;
        break;
    case Rank::kTwo:
        r = Rank::kThree;
        break;
    case Rank::kThree:
        r = Rank::kFour;
        break;
    case Rank::kFour:
        r = Rank::kFive;
        break;
    case Rank::kFive:
        r = Rank::kSix;
        break;
    case Rank::kSix:
        r = Rank::kSeven;
        break;
    case Rank::kSeven:
        r = Rank::kEight;
        break;
    case Rank::kEight:
        r = Rank::kNine;
        break;
    case Rank::kNine:
        r = Rank::kTen;
        break;
    case Rank::kTen:
        r = Rank::kJack;
        break;
    case Rank::kJack:
        r = Rank::kQueen;
        break;
    case Rank::kQueen:
        r = Rank::kKing;
        break;
    case Rank::kKing:
        r = Rank::kAce;
        break;
    default:
        r = Rank::kAce;
        break;
    }
    return r;
}

Rank &operator--(Rank &r)
{
    switch (r)
    {
    case Rank::kAce:
        r = Rank::kKing;
        break;
    case Rank::kTwo:
        r = Rank::kAce;
        break;
    case Rank::kThree:
        r = Rank::kTwo;
        break;
    case Rank::kFour:
        r = Rank::kThree;
        break;
    case Rank::kFive:
        r = Rank::kFour;
        break;
    case Rank::kSix:
        r = Rank::kFive;
        break;
    case Rank::kSeven:
        r = Rank::kSix;
        break;
    case Rank::kEight:
        r = Rank::kSeven;
        break;
    case Rank::kNine:
        r = Rank::kEight;
        break;
    case Rank::kTen:
        r = Rank::kNine;
        break;
    case Rank::kJack:
        r = Rank::kTen;
        break;
    case Rank::kQueen:
        r = Rank::kJack;
        break;
    case Rank::kKing:
        r = Rank::kQueen;
        break;
    default:
        r = Rank::kAce;
        break;
    }
    return r;
}

ostream &operator<<(ostream &out, Rank r)
{
    switch (r)
    {
    case Rank::kAce:
        out << "Ace";
        break;
    case Rank::kTwo:
        out << "Two";
        break;
    case Rank::kThree:
        out << "Three";
        break;
    case Rank::kFour:
        out << "Four";
        break;
    case Rank::kFive:
        out << "Five";
        break;
    case Rank::kSix:
        out << "Six";
        break;
    case Rank::kSeven:
        out << "Seven";
        break;
    case Rank::kEight:
        out << "Eight";
        break;
    case Rank::kNine:
        out << "Nine";
        break;
    case Rank::kTen:
        out << "Ten";
        break;
    case Rank::kJack:
        out << "Jack";
        break;
    case Rank::kQueen:
        out << "Queen";
        break;
    case Rank::kKing:
        out << "King";
        break;
    default:
        out << " ";
        break;
    }
    return out;
}

class Card
{
public:
    Card(Suit s, Rank r) : s(s), r(r){};
    void print();
    Suit getSuit();
    Rank getRank();

private:
    Suit s;
    Rank r;
};

void Card::print()
{
    cout << r << " of " << s << endl;
}

Suit Card::getSuit()
{
    return s;
}

Rank Card::getRank()
{
    return r;
}

class Deck
{
public:
    Deck();
    int size();
    Card *getCard(int);
    vector<Card *> deal();
    ~Deck();

private:
    vector<Card *> cards;
};

Deck::Deck()
{
    Suit s = Suit::kClubs;
    for (int i = 0; i < kSuits; i++)
    {
        Rank r = Rank::kAce;
        for (int j = 0; j < kRanks; j++)
        {
            cards.push_back(new Card(s, r));
            ++r;
        }
        ++s;
    }
}

int Deck::size()
{
    return cards.size();
}

Card *Deck::getCard(int i)
{
    return cards[i];
}

vector<Card *> Deck::deal()
{
    vector<Card *> result;
    // obtain a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(), default_random_engine(seed));
    for (int i = 0; i < kDeal; i++)
    {
        result.push_back(cards[i]);
    }
    return result;
}

Deck::~Deck()
{
    cards.clear();
}

void printDeal(const vector<Card *> &hand)
{
    for (auto c : hand)
    {
        c->print();
    }
}

bool isStraightFlush(vector<Card *> hand)
{
    //A straight flush is a hand that contains five cards
    //of sequential rank, all of the same suit
    Suit s = hand[0]->getSuit();
    Rank r = hand[0]->getRank();
    Suit s1 = hand[1]->getSuit();
    Rank r1 = hand[1]->getRank();
    int checkUp = 0;
    if (r1 == ++r)
        checkUp = 1;
    r = hand[0]->getRank();
    if (r1 == --r)
        checkUp = 2;
    r = hand[0]->getRank();
    if (checkUp == 0)
        return false;

    for (int i = 1; i < hand.size(); i++)
    {
        if (hand[i]->getSuit() != s)
            return false;
        Rank prev = hand[i - 1]->getRank();
        if (checkUp == 1)
            if (hand[i]->getRank() != ++prev)
                return false;
        if (checkUp == 2)
            if (hand[i]->getRank() != --prev)
                return false;
    }
    return true;
}

double probStraightFlush(Deck &deck)
{
    double prob = 0.0;
    vector<double> probs;
    for (int i = 0; i < kTrials; i++)
    {
        bool isStraight = false;
        int draws = 0;
        while (!isStraight)
        {
            ++draws;
            isStraight = isStraightFlush(deck.deal());
        }
        cout << "draws: " << draws << endl; 
        cout << static_cast<double>(1.0 / draws) << endl;
        probs.push_back(static_cast<double>(1.0 / draws));
    }
    prob = static_cast<double>(accumulate(probs.begin(), probs.end(), 0.0) / probs.size());
    return prob;
}

int main()
{
    Deck *d = new Deck();
    cout << d->size() << endl;
    d->getCard(0)->print();
    d->getCard(1)->print();
    d->getCard(2)->print();
    Suit s = Suit::kClubs;
    cout << s << endl;
    ++s;
    cout << s << endl;
    Rank r = Rank::kQueen;
    cout << r << endl;
    ++r;
    cout << r << endl;
    cout << "let's deal..." << endl;
    vector<Card *> hand = d->deal();
    printDeal(hand);
    cout << "let's calculate the probability of a straight flush for " << kTrials << " trials." << endl;
    cout << probStraightFlush(*d) << endl;
    delete d;
    return 0;
}
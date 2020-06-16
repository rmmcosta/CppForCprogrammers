#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int kSuits = 4;
const int kRanks = 13;

enum class Suit
{
    kClubs,
    kDiamonds,
    kHearts,
    kSpades
};

Suit operator++(Suit s)
{
    switch (s)
    {
    case Suit::kClubs:
        return Suit::kDiamonds;
    case Suit::kDiamonds:
        return Suit::kHearts;
    case Suit::kHearts:
        return Suit::kSpades;
    case Suit::kSpades:
        return Suit::kClubs;
    default:
        return Suit::kClubs;
    }
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

Rank operator++(Rank r)
{
    switch (r)
    {
    case Rank::kAce:
        return Rank::kTwo;
    case Rank::kTwo:
        return Rank::kThree;
    case Rank::kThree:
        return Rank::kFour;
    case Rank::kFour:
        return Rank::kFive;
    case Rank::kFive:
        return Rank::kSix;
    case Rank::kSix:
        return Rank::kSeven;
    case Rank::kSeven:
        return Rank::kEight;
    case Rank::kEight:
        return Rank::kNine;
    case Rank::kNine:
        return Rank::kTen;
    case Rank::kTen:
        return Rank::kJack;
    case Rank::kJack:
        return Rank::kQueen;
    case Rank::kQueen:
        return Rank::kKing;
    case Rank::kKing:
        return Rank::kAce;
    default:
        return Rank::kAce;
    }
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

private:
    Suit s;
    Rank r;
};

void Card::print()
{
    cout << r << " of " << s << endl;
}

class Deck
{
public:
    Deck();
    int size();
    Card *getCard(int);

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

int main()
{
    Deck *d = new Deck();
    cout << d->size() << endl;
    d->getCard(0)->print();
    delete d;
    return 0;
}
#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;


class Card
{
private:
    string rank;
    string suit;
    string cardInfo;
public:
    Card()
    { rank = ""; suit = ""; cardInfo = ""; }

    void setRank(const string &r)
    { rank = r; }

    void setSuit(const string &s)
    { suit = s; }

    string getRank() const
    { return rank; }

    string getSuit() const
    { return suit; }

    void setCardInfo()
    { cardInfo = rank + suit; }

    string getCardInfo() const
    { return cardInfo; }
};


#endif //CARD_H

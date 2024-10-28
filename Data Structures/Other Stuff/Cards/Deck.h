#ifndef DECK_H
#define DECK_H
#include <string>
#include "Card.h"
using namespace std;

class Deck
{
private:
    Card deck[52];
    string suits[4] = {"S", "H", "C", "D"};
    string ranks[13] = {"A", "2", "3", "4", "5", "6", "7",
                        "8", "9", "T", "J", "Q", "K"};


public:
    Deck(); // constructor
    void printDeck() const;
    void getRandomCard();
};


#endif //STANDARDDECK_H

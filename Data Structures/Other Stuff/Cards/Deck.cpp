#include "Deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Deck::Deck()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            deck[(i * 13) + j].setRank(ranks[j]);
            deck[(i * 13) + j].setSuit(suits[i]);
            deck[(i * 13) + j].setCardInfo(); // set the info for each card after setting the rank and suit
        }
    }

} // end constructor

void Deck::printDeck() const
{
    for(int i = 0; i < 4; i++)
    {
        if(i == 0)
            cout << "Spades:   ";
        else if(i == 1)
            cout << "Hearts:   ";
        else if(i == 2)
            cout << "Clubs:    ";
        else if(i == 3)
            cout << "Diamonds: ";

        for(int j = 0; j < 13; j++)
        {
            cout << deck[(i * 13) + j].getCardInfo() << " ";
        }
        cout << endl;
    }
} // end printDeck

void Deck::getRandomCard()
{
    int randomNum = rand() % 52;
    cout << "Your random card is " << deck[randomNum].getCardInfo();
} // end getRandomCard


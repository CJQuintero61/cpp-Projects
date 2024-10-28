/*
 * Humble Beginnings. In this program, I simulated a deck of cards and tested to make sure
 * every card was able to be drawn using a large for loop and getRandomCard
 * which was removed for anyone who sees this code so they don't have to run a large loop.
 * From here, it would be cool to try and make some card games, as I do personally enjoy card
 * games with others. This also provided some more learning and refreshing on random numbers
 * as well on how to think about breaking objects down even more into smaller objects.
 * In this case, a card is an object, and a bunch of cards make a deck object.
 * Christian Quintero 10/28/2024
 */
#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

int main()
{
    cout << endl; // for readability

    // Seed the random number generator with the current time
    // also allows functions that get random values to be different each call
    srand(time(nullptr));

    Deck Deck1;
    Deck1.printDeck();
    cout << endl;

    cout << "Getting a random card:\n";
    Deck1.getRandomCard();
    cout << endl;

    return 0;
} // end main
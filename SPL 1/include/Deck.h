#ifndef DECK_H_
#define DECK_H_
#include <vector>
#include <string>

#include <iostream>

#include "Card.h"

using namespace std;

class Deck {
private:
    vector <Card *> _deck;
    void copy(const Deck &other);
public:
    Deck(); //ctor
    Deck(const Deck &other);
    Deck(string deckStr);
    ~Deck();
    vector<Card*> getDeck();
    void setDeck(Deck& _rhs);
    Deck& operator=(const Deck &other);
	Card* fetchCard();   //Returns the top card of the deck and remove it rom the deck
	int getNumberOfCards(); // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"


};

#endif

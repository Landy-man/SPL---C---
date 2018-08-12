#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>

#include <iostream>
#include <vector>

#include "Deck.h"
#include "Card.h"

using namespace std;

class Hand {
private:
	vector <Card *> _playersHand;// Declare here the collection of "Card *" of the hand
    void removeAllCardByValue(int _val);
    int numOfCards(int _val);
    void copyHand(const Hand &other);

public:
    Hand();
    Hand(const Hand &other);
    virtual ~Hand();
    Hand(vector<Card *> hand);
    Hand& operator=(const Hand &other);
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"
    void setHand(vector<Card*> _oldHand);
    Hand getWholeHand();
	vector <Card*> getHand();
};

#endif

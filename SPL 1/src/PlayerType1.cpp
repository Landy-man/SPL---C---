#include "Player.h"

using namespace std;



PlayerType1::PlayerType1():Player(){}

PlayerType1::~PlayerType1(){}

PlayerType1::PlayerType1(const string& pName): Player(pName){}

PlayerType1::PlayerType1(Player* _other): Player(_other->getName()) {

    this->setHand(_other->getHand());
}

int PlayerType1::askCard(){
    int valToAsk;
    int firstCardCounter=0;
    int secondCardCounter=0;
    if(Hand::getNumberOfCards()!=0){
        int cardsNum = Hand::getNumberOfCards()-1;
        vector <Card*> playerHand = Hand::getHand();
        Card* cardPtr;
        cardPtr = playerHand.at(cardsNum);

        for(int i = cardsNum ; i >= 0 ; i--){ //starts from the end where the higher values are
            if(playerHand.at(i)->getValOfCard() == cardPtr->getValOfCard()){ //check if the cards got the same value
                firstCardCounter++;
                cardPtr = playerHand.at(i);
                }
            else{
                if(firstCardCounter > secondCardCounter){ //if the current sum is greater than the older take the new val
                    valToAsk = cardPtr->getValOfCard();
                    cardPtr = playerHand.at(i);
                    secondCardCounter=firstCardCounter;
                    firstCardCounter=1;
                    }
                else{
                    cardPtr = playerHand.at(i);
                    firstCardCounter=1;

                }
            }
        }
        if(firstCardCounter > secondCardCounter)
            return cardPtr->getValOfCard();
        return valToAsk;
    }
    return -800;
}


Player* PlayerType1::clone(){
        return new PlayerType1(*this);
}


int PlayerType1::getType(){
return 1;
}



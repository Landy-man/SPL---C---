#include "Player.h"

PlayerType3::PlayerType3():Player(){}

PlayerType3::PlayerType3(const string& pName): Player(pName){
}

PlayerType3::~PlayerType3()
{

}


PlayerType3::PlayerType3(Player* _other): Player(_other->getName()) {

    this->setHand(_other->getHand());
}


PlayerType3& PlayerType3::operator=(const PlayerType3& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}

int PlayerType3::askCard(){
    vector <Card*> playerHand = Hand::getHand();
    if (playerHand.size()<1)
        return -800;
    else{
        int numOfCards=playerHand.size()-1;
        int _returnVal=(playerHand.at(numOfCards))->getValOfCard();
        turn++;
        return _returnVal;
    }
}

int PlayerType3::getTurn(){
return turn;
}

void PlayerType3::setTurn(int newTurn){
turn=newTurn;
}


int PlayerType3::getType(){
return 3;
}


Player* PlayerType3::clone(){
        return new PlayerType3(*this);
}

#include "Player.h"
PlayerType4::PlayerType4(): Player()
{
    //ctor
}

PlayerType4::PlayerType4(const string& pName): Player(pName){
}


PlayerType4::~PlayerType4()
{

}


PlayerType4::PlayerType4(Player* _other): Player(_other->getName()) {

    this->setHand(_other->getHand());
}


PlayerType4& PlayerType4::operator=(const PlayerType4& rhs)
{
    if (this == &rhs) return *this;
    return *this;
}


int PlayerType4::askCard(){
    vector <Card*> playersHand=Hand::getHand();
    if (playersHand.size()<1)
        return 0;
    turn++;
    return ((playersHand.at(0)->getValOfCard()));
}


int PlayerType4::getTurn(){
return turn;
}

void PlayerType4::setTurn(int newTurn){
turn=newTurn;
}

int PlayerType4::getType(){
return 4;
}


Player* PlayerType4::clone(){
        return new PlayerType4(*this);
}

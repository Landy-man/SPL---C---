#include "Player.h"

using namespace std;


Player::Player(){}

Player::~Player(){}

Player::Player(const string& pName): name(pName){}


string Player::getName(){
    string _ans=name;
    return _ans;
}


string Player::toString(){
    vector<Card*> _hand;
    _hand= this->getHand();
    string _returnVal=this->getName()+":";
    string _handString="";
    for(unsigned int i=0;i<_hand.size();i++){
        _handString=_handString+ " " +(_hand.at(i))->toString();
    }

    return _returnVal+_handString;
}


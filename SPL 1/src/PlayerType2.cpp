#include "Player.h"

using namespace std;



PlayerType2::PlayerType2(): Player(){}

PlayerType2::~PlayerType2(){}

PlayerType2::PlayerType2(const string& pName): Player(pName){
}

PlayerType2::PlayerType2(Player* _other): Player(_other->getName()) {

    this->setHand(_other->getHand());
}



int PlayerType2::askCard(){
    vector <Card*> playerHand = Hand::getHand();
    int _counter=4;


    if (playerHand.size()==0)
        return -800;
    else{
        int _leastLowerVal=(playerHand.at(0))->getValOfCard();
        int num=(playerHand.at(0))->getValOfCard();
        int _tempCount=0;
        for (unsigned int i=0;i<playerHand.size();i++){

            if (num==(playerHand.at(i))->getValOfCard()){
                _tempCount++;
            }
            else{
                if (_tempCount<_counter)
                {
                    _counter=_tempCount;
                    _leastLowerVal=num;

                }
                num = (playerHand.at(i))->getValOfCard();
                _tempCount=1;
            }
        }
                        if (_tempCount<_counter)
                {
                    _counter=_tempCount;
                    _leastLowerVal=num;

                }
            return _leastLowerVal;


    }



}

Player* PlayerType2::clone(){
        return new PlayerType2(*this);
}

int PlayerType2::getType(){
return 2;
}


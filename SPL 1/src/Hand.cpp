#include "Hand.h"
#include <vector>
#include <algorithm>
bool CompareTo(Card* a, Card* b);
bool CompareToValue(NumericCard* a, NumericCard* b);
bool CompareToFigure(FigureCard * a, FigureCard * b);


Hand::Hand():_playersHand(){
}

Hand::Hand(vector <Card *> hand):_playersHand(){

for(Card* _crd:hand){
if (_crd->isCardNumeric()){
    NumericCard* _newNumCard=new NumericCard(_crd->toString());
    _playersHand.push_back(_newNumCard);
    }
else{
    FigureCard* _newFigCard=new FigureCard(_crd->toString());
    _playersHand.push_back(_newFigCard);
}
}
}

Hand::Hand(const Hand &other):_playersHand(){
    copyHand(other);
}



Hand& Hand::operator=(const Hand &other){
    if(this == &other)
        return *this;

    copyHand(other);
    return *this;
}

bool Hand:: addCard(Card &card){
    int i= numOfCards(card.getValOfCard());
    if (i<3){
        if (card.isCardFigure()){
            FigureCard * _fig=new FigureCard(card.toString());
            _playersHand.push_back(_fig);
            delete &card;
        }
        else{
            NumericCard * _num = new NumericCard(card.toString());
            _playersHand.push_back(_num);
            delete &card;
        }
     sort (_playersHand.begin(), _playersHand.end(), CompareTo);
    }
    else{
        removeAllCardByValue(card.getValOfCard());
        delete &card;
    }
return true;



}

bool Hand::removeCard(Card & card){
int flag=-1;
for (unsigned int i=0;i<_playersHand.size();i++)
    if (_playersHand.at(i)->toString()==card.toString()){
        flag=i;
        delete _playersHand.at(i);
    }
if (flag==-1)
    return false;
else{

    _playersHand.erase(_playersHand.begin()+flag);
    return true;
}
}

int Hand::getNumberOfCards(){
	return _playersHand.size();
	}


bool CompareTo(Card* a, Card* b){
    if ((a->isCardNumeric()) && (b->isCardNumeric())){
        return CompareToValue(static_cast<NumericCard *>(a) ,static_cast<NumericCard *> (b));
     }
    else if ((a->isCardFigure()) && (b->isCardFigure())){
        return CompareToFigure(static_cast<FigureCard *>(a) ,static_cast<FigureCard *> (b));
    }
    else{
        if (a->isCardFigure())
            return false;
        else
            return true;
    }

    }

bool CompareToValue(NumericCard* a, NumericCard* b){
        if (a->getNumVal()<b->getNumVal())
            return true;
        if (b->getNumVal()<a->getNumVal())
            return false;
        else
            return (a->GetShapeChar()<b->GetShapeChar());
    }

bool CompareToFigure(FigureCard * a, FigureCard * b){
    if (a->getFigNum()-b->getFigNum()>0)
        return false;
    if (b->getFigNum()-a->getFigNum()>0)
        return true;
    else
        return (a->GetShapeChar()<b->GetShapeChar());
}

string Hand::toString(){
    Card * temp;
    string _toReturn="";

    for(unsigned int i=0 ; i<=_playersHand.size()-1 ; i++){
         temp = _playersHand.at(i);
        _toReturn+= temp->toString()+" ";
    }
    return _toReturn;
}

Hand::~Hand(){
for (unsigned int i=0; i<_playersHand.size();i++)
    delete _playersHand.at(i);
_playersHand.clear();
}

int Hand::numOfCards(int _val){
    int _returnVal=0;
for (unsigned int i=0;i<_playersHand.size();i++){
    if ((_playersHand.at(i))->getValOfCard()==_val)
        _returnVal++;
}
return _returnVal;
}

void Hand::removeAllCardByValue(int _val){
for (unsigned int i=0;i<_playersHand.size();i++)
    if (_playersHand.at(i)->getValOfCard()==_val){
        delete _playersHand.at(i);
        _playersHand.erase(_playersHand.begin()+i);
        i--;
    }
}

vector <Card*> Hand::getHand(){
return _playersHand;
}

void Hand::setHand(vector<Card*> _oldHand){
    this->_playersHand=_oldHand;
}

void Hand::copyHand(const Hand &other){
    unsigned int index;
    for(index = 0; index < other._playersHand.size(); index++){
        Card* temp = other._playersHand.at(index)->clone();
        addCard(*temp);
    }
}



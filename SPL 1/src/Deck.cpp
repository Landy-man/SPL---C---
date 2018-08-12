#include "Deck.h"
#include "Card.h"

Deck::Deck():_deck(){}


Deck::Deck(string cardStr):_deck(){

    string temp;
    for(int i=cardStr.size()-1; i>=0 ; i--){

        if(cardStr.at(i) != ' '){
            temp=cardStr.at(i)+temp;
        }
        else if(temp.size()>0){

            if (temp.at(0)=='J'||temp.at(0)=='Q'||temp.at(0)=='K'||temp.at(0)=='A'){
                _deck.push_back(new FigureCard(temp));}
            else
                _deck.push_back(new NumericCard(temp));
            temp="";
        }
    }
            if (temp.at(0)=='J'||temp.at(0)=='Q'||temp.at(0)=='K'||temp.at(0)=='A')
                _deck.push_back(new FigureCard(temp));
            else
                _deck.push_back(new NumericCard(temp));
}


Deck::~Deck()
{
    for(unsigned int i=0 ; i< _deck.size() ; i++)
        delete _deck.at(i);
    _deck.clear();
}


Deck::Deck(const Deck &other):_deck(){
    copy(other);
}

Deck& Deck::operator=(const Deck &other){
    if(this == &other)
        return *this;
    copy(other);
    return *this;
}





int Deck:: getNumberOfCards(){ //return the vector size
    return _deck.size();
}

string Deck::toString(){

    string _toReturn="";
    cout << "Deck: " ;
    for(int i=_deck.size()-1 ; i>=0 ; i--){
        Card * temp;
        temp = _deck.at(i);
        _toReturn+= temp->toString()+" ";
    }

    return _toReturn;
}

vector<Card*> Deck::getDeck(){
return _deck;
}

void Deck::setDeck(Deck& _rhs){
    _deck= _rhs.getDeck();
}

Card* Deck::fetchCard()
{
    Card * _toReturn;
    _toReturn=_deck.at(_deck.size()-1);
    FigureCard *fig;
    NumericCard *num;
    if (_toReturn->isCardFigure()){
        fig = new FigureCard(_toReturn->toString());
        delete _toReturn;
        _deck.pop_back();
        return fig;
    }
    else{
        num = new NumericCard(_toReturn->toString());
        delete _toReturn;
        _deck.pop_back();
        return num;
}
}

void Deck::copy(const Deck &other){
        unsigned int index;
        for(index = 0; index < other._deck.size(); index++){
            Card* temp = other._deck.at(index)->clone();
            _deck.push_back(temp);
        }
}


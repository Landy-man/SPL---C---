#include "Card.h"
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

NumericCard::NumericCard():number(){
}


NumericCard::~NumericCard(){
}

Card* NumericCard::clone(){
    return new NumericCard(*this);
}


void NumericCard::setValue(int val){
    number=val;
}


NumericCard:: NumericCard(string cardInfo): Card(cardInfo.at(cardInfo.size()-1)) , number(){
    string _value = cardInfo.substr(0, cardInfo.size()-1);
    number = atoi(_value.data());
}

string NumericCard::toString(){
    ostringstream convert;
    convert << number;
    string toReturn= convert.str();
    return toReturn+GetShapeChar();
}

bool NumericCard::isCardFigure(){
return false;
}

bool NumericCard::isCardNumeric(){
return true;
}

int NumericCard:: getNumVal(){
    return number;
    }

int NumericCard::getValOfCard(){
return number;
}

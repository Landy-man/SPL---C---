#include "Card.h"
#include <string>
using namespace std;

FigureCard::FigureCard():figure(){
}

FigureCard::~FigureCard()
{
    //dtor
}


Figure FigureCard::getFigure(){
    return figure;
}

void FigureCard::setFigure(Figure fgr){
    figure=fgr;
}


Card* FigureCard::clone(){
    return new FigureCard(*this);
}
FigureCard::FigureCard(string cardInfo): Card(cardInfo.at(cardInfo.size()-1)) , figure(){
    char figureOfCard = cardInfo.at(0);
    switch(figureOfCard){
        case ('J'):
            figure = Figure(0);
            break;

        case ('Q'):
            figure = Figure(1);
            break;

        case ('K'):
            figure = Figure(2);
            break;

        case ('A'):
            figure = Figure(3);
            break;
}
}

string FigureCard::toString(){
    string toReturn="";

    toReturn+=getFigVal();

    return toReturn+GetShapeChar();
}

char FigureCard::getFigVal(){
            switch(figure){
    case (Figure(0)):
    return 'J';
    break;
    case (Figure(1)):
    return 'Q';
    break;
    case (Figure(2)):
    return 'K';
    break;
    case (Figure(3)):
    return 'A';
    default: return 'Z';
}
}

bool FigureCard::isCardFigure(){
return true;
}

bool FigureCard::isCardNumeric(){
return false;
}

int FigureCard::getFigNum(){
return figure;
}

int FigureCard::getValOfCard(){
return -figure;
}

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
  Shape shape;


public:
    char GetShapeChar();
    Card(char shapeOfCard);
    Card();
    Shape getShape();
    void setShape(Shape shp);
    virtual int getValOfCard()=0;
    virtual bool isCardNumeric() = 0;
    virtual bool isCardFigure() = 0;
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
    virtual Card* clone()=0;
};

class FigureCard : public Card {
private:
	Figure figure;
public:
    Figure getFigure();
    void setFigure(Figure fgr);
    FigureCard(string card);
    FigureCard();
    ~FigureCard();
    char getFigVal();
    int getFigNum();
    int getValOfCard();
	virtual string toString() override;
	virtual bool isCardFigure() override;
	virtual bool isCardNumeric() override;
        virtual Card* clone();
};

class NumericCard : public Card {
private:
	int number;
public:
    NumericCard();
    ~NumericCard();
    NumericCard(string cardInfo);
    int getNumVal();
    void setValue(int val);
    virtual int getValOfCard();
	virtual string toString() override;
	virtual bool isCardFigure() override;
	virtual bool isCardNumeric() override;
                virtual Card* clone();
};

#endif

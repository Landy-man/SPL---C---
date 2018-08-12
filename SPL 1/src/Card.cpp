#include "Card.h"


Card::Card():shape(){

}

/*Char constructor*/
Card::Card(char shapeOfCard):shape(){
switch(shapeOfCard){
case('C'):
    shape=Shape(0);
    break;
    case('D'):
    shape=Shape(1);
    break;
    case('H'):
    shape=Shape(2);
    break;
    case('S'):
    shape=Shape(3);
    break;
}
}


  void Card::setShape(Shape shp){
  this->shape=shp;
  }

  Shape Card::getShape(){
  return shape;
  }



  /*Destructor*/
Card::~Card(){}


char Card::GetShapeChar(){
    switch(shape){
        case (Shape(0)):
            return 'C';
        case (Shape(1)):
            return 'D';
        case (Shape(2)):
            return 'H';
        case (Shape(3)):
            return 'S';
        default:
            return 'Z';
    }
}

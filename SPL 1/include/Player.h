#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include <string>

#include "Hand.h"


using namespace std;

class Player : public Hand {

private:
	const string name="";

public:
	string getName();   //Returns the name of the player
	Player();
    virtual ~Player();
	Player(const string& pName);
    virtual int askCard()=0;
    virtual int getType()=0;
    string toString();
    virtual Player* clone()=0;


};

class PlayerType1 : public Player {
    public:
        PlayerType1();
        ~PlayerType1();
        PlayerType1(const string& pName);
        virtual int askCard();
        PlayerType1(PlayerType1* _other);
        PlayerType1(Player* _other);
        virtual Player* clone();
        virtual int getType();
};

class PlayerType2 : public Player {  //For strategy 2
    public:
        PlayerType2();
        ~PlayerType2();
        PlayerType2(const string& pName);
        PlayerType2(Player* _other);
        virtual int askCard();
        virtual int getType();
        virtual Player* clone();

};


class PlayerType3 : public Player {  //For strategy 3
    private:
    int turn=0;

    public:
virtual int getType();
        int getTurn();
        void setTurn(int newTurn);
        PlayerType3();
        ~PlayerType3();
        PlayerType3& operator=(const PlayerType3& rhs);
        PlayerType3(Player* _other);
        PlayerType3(const string& pName);
        virtual int askCard();
        virtual Player* clone();
};

class PlayerType4 : public Player {  //For strategy 4
private:
    int turn=0;

    public:
virtual int getType();
        int getTurn();
        void setTurn(int newTurn);


        PlayerType4(Player* _other);
        PlayerType4();
        ~PlayerType4();
        PlayerType4& operator=(const PlayerType4& rhs);
        PlayerType4(const string& pName);
        virtual int askCard();
        virtual Player* clone();
};

#endif

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Deck.h"
#include <string>
#include <cstdlib>

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;
	int turnCounter=0;
	int verbal=0;                //The deck of the game

	bool hasWinner();
	int askFrom(PlayerType1* player);
	int askFrom(PlayerType2* player);
	int askFrom(PlayerType3* player);
	int askFrom(PlayerType4* player);
	int askFrom(Player * player);
	char getShape(int _num);
	char getFigure(int _num);
        void copy(const Game &other);
public:
    Game();
    Game(const Game &other);
    ~Game();
    Game& operator=(const Game &other);


	Game(char* configurationFile);
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.
};

#endif

        #include "Game.h"
        #include <cstdlib>
        #include <sstream>

Game::Game():players(),deck(){
}

        Game::~Game(){
            for(unsigned int i=0; i<players.size(); i++){
                delete players.at(i);
        }
        players.clear();
        }


        Game::Game(const Game &other):players(), deck(){
            copy(other);
        }

        Game& Game::operator=(const Game &other)
        {
            if(this == &other)
                return *this;
            copy(other);
            return *this;
        }

        Game::Game(char* configurationFile):players(), deck(){
            string line;
            int _flag=0;
            turnCounter=0;
            ifstream _textStream (configurationFile);
            if (_textStream.is_open()){
                while (getline(_textStream,line)){
                    if (line.size()!=0){
                            if (line.at(0)!='#'){
                                if (_flag==0){
                                    verbal=atoi(line.data());
                                    _flag++;

                                }
                                else if (_flag==1){
                                    _flag++;


                                }
                                else if (_flag==2){
                                    string s=line;
                                    this->deck=Deck(line);
                                    _flag++;

                                }
                                else{

                                    char typeOfPlayer=line.at(line.size()-1);
                                    string name=line.substr(0,line.size()-2);
                                    int num=typeOfPlayer-'0';

                                    if (num==1){
                                        PlayerType1* _toEnter = new PlayerType1(name);
                                        players.push_back(_toEnter);
                                        _flag++;
                                    }
                                    else if(num==2){
                                        PlayerType2* _toEnter=new PlayerType2(name);
                                        players.push_back(_toEnter);
                                        _flag++;
                                            }
                                    else if(num==3){
                                        PlayerType3* _toEnter=new PlayerType3(name);
                                        players.push_back(_toEnter);
                                        _flag++;
                                        }
                                    else if(num==4){
                                        PlayerType4* _toEnter=new PlayerType4(name);
                                        players.push_back(_toEnter);
                                        _flag++;
                                        }
                                }

                            }
                        }
                    }


                }
            else
                cout << "Unable to open file";
        }

        void Game::init(){
            cout<<deck.toString()<<endl;
            for(unsigned int j=0;j<players.size();j++){
                for (int i=0;i<7;i++){
                    Card * _toAdd;
                    _toAdd = deck.fetchCard();
                    players.at(j)->addCard(*_toAdd);
                }

            }
        }

        void Game::play(){
            while (!hasWinner()){
                if (verbal==1){
                    cout << "\nTurn " << turnCounter+1 << endl;
                    printState();
                    }
                bool _takeFromDeck=true;
                int _askFrom=askFrom(players.at((turnCounter)%players.size()));
                int _askVal = players.at(turnCounter%players.size())->askCard();
                if (verbal==1){
                    cout<< players.at((turnCounter)%players.size())->getName()<< " asked "<<players.at(_askFrom)->getName()<< " for the value ";
                    if (_askVal>0)
                        cout<<_askVal<<endl;
                    else
                        cout<<getFigure(_askVal)<<endl;
                        }
                for (int i=0;i<4;i++){
                    char _shape = getShape(i);
                    if (_askVal>0){
                        string _cardString;
                        stringstream ss2;
                        ss2 << _askVal;
                        _cardString = ss2.str();
                        _cardString=_cardString+_shape;
                        Card* _card=new NumericCard(_cardString);
                        if (players.at(_askFrom)->removeCard(*_card)){
                            if (deck.getNumberOfCards()!=0)
                                players.at(_askFrom)->addCard(*deck.fetchCard());
                            players.at((turnCounter)%players.size())->addCard(*_card);
                            _takeFromDeck=false;
                            _card=nullptr;
                        }
                        else
                            delete _card;

                    }
                    else{
                        char _figureString;
                        _figureString = getFigure(_askVal);
                        string _figureCardString="";
                        _figureCardString=_figureCardString+_figureString;
                        _figureCardString=_figureCardString+_shape;
                        Card* _card=new FigureCard(_figureCardString);

                        if (players.at(_askFrom)->removeCard(*_card)){
                            if (deck.getNumberOfCards()!=0)
                                players.at(_askFrom)->addCard(*deck.fetchCard());
                            players.at((turnCounter)%players.size())->addCard(*_card);
                            _takeFromDeck=false;
                            _card=nullptr;
                        }
                        else
                            delete _card;
                    }

                }
                    if (_takeFromDeck && deck.getNumberOfCards()!=0)
                        players.at(turnCounter%players.size())->addCard(*deck.fetchCard());

                turnCounter++;
            }
        }


        void Game::printState(){
            cout<<deck.toString()<<endl;
            for (Player* plr:players){
                cout<<plr->toString()<<endl;
            }
        }

        void Game::printWinner(){
            string s="";
            int numOfWinners=0;
            for (Player* plr : players){
                    if (plr->getNumberOfCards()==0){
                        if (s==""){
                            s=plr->getName();
                            numOfWinners++;
                            }
                        else{
                            s=s+" and "+plr->getName();
                            numOfWinners++;

                    }
                }
            }
            if (numOfWinners==1)
                cout<<"***** The Winner is: "<< s<<" *****"<<endl;
            if (numOfWinners==2)
                cout<<"***** The Winners are: "<< s<<" *****"<<endl;

            }

        void Game::printNumberOfTurns()
        {
            cout << "Number of turns: " << turnCounter+1<<endl;

        }

        bool Game::hasWinner(){
        for (Player * player: players){
            if (player->getNumberOfCards()==0)
                return true;
        }
        return false;
        }

        int Game::askFrom(PlayerType1* player){
         int _numOfPlayer;
         int _HighestAmountOfCard=0;
         for (unsigned int i=0;i<players.size();i++){
            if ((players.at(i)->getNumberOfCards()>=_HighestAmountOfCard)&&(players.at(i)!=player)){
                _HighestAmountOfCard=players.at(i)->getNumberOfCards();
                _numOfPlayer=i;
            }
         }
         return _numOfPlayer;
        }

        int Game::askFrom(PlayerType2* player){
         int _numOfPlayer;
         int _HighestAmountOfCard=0;
         for (unsigned int i=0;i<players.size();i++){
            if ((players.at(i)->getNumberOfCards()>=_HighestAmountOfCard)&&(players.at(i)!=player)){
                _HighestAmountOfCard=players.at(i)->getNumberOfCards();
                _numOfPlayer=i;
            }
         }
         return _numOfPlayer;
        }

        int Game::askFrom(PlayerType3* player){
         if (player==players.at(player->getTurn()%players.size())){
             int _newTurn=player->getTurn();
             _newTurn++;
             player->setTurn(_newTurn);
             return (player->getTurn()%players.size());}
         return (player->getTurn()%players.size());
        }


        int Game::askFrom(PlayerType4* player){
         if (player==players.at(player->getTurn()%players.size())){
             int _newTurn=player->getTurn();
             _newTurn++;
             player->setTurn(_newTurn);
             return (player->getTurn()%players.size());}
         return (player->getTurn()%players.size());
        }


char Game::getShape(int _num){
switch (_num){
    case(0): return 'C';
    case(1): return 'D';
    case(2): return 'H';
    case(3): return 'S';
    default: return 'S';
}
}

char Game::getFigure(int _num){
switch (_num){
case (0): return 'J';
case (-1): return 'Q';
case (-2): return 'K';
case (-3): return 'A';
    default: return 'A';
}
}

int Game::askFrom(Player* player){
    if (player->getType()==1)
        return askFrom(static_cast <PlayerType1*>(player));
    else if (player->getType()==2)
        return askFrom(static_cast <PlayerType2*>(player));
    else if (player->getType()==3)
        return askFrom(static_cast <PlayerType3*>(player));
    else if (player->getType()==4)
        return askFrom(static_cast <PlayerType4*>(player));
    return -1;
}

void Game::copy(const Game &other){
        deck = other.deck;
        unsigned int index;
        for(index = 0; index < other.players.size(); index++){
                Player* temp = other.players.at(index)->clone();
                players.push_back(temp);
        }

        verbal = other.verbal;
        turnCounter = other.turnCounter;
}

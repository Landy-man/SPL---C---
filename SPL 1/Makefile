# All Targets
all: reviiot

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
reviiot: bin/reviiyot.o bin/Game.o bin/Player.o bin/Deck.o bin/PlayerType1.o bin/PlayerType2.o bin/PlayerType3.o bin/PlayerType4.o bin/Hand.o bin/Card.o bin/NumericCard.o bin/FigureCard.o
	@echo 'Building target: Game'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/reviiot bin/reviiyot.o bin/Game.o bin/Player.o bin/Deck.o bin/PlayerType1.o bin/PlayerType2.o bin/PlayerType3.o bin/PlayerType4.o bin/Hand.o bin/Card.o bin/NumericCard.o bin/FigureCard.o
	@echo 'Finished building target: Game'
	@echo ' '

bin/reviiyot.o: src/reviiyot.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/reviiyot.o src/reviiyot.cpp

bin/Game.o: src/Game.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Game.o src/Game.cpp

bin/Player.o: src/Player.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Player.o src/Player.cpp

bin/Hand.o: src/Hand.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Hand.o src/Hand.cpp	

bin/Card.o: src/Card.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Card.o src/Card.cpp

bin/NumericCard.o: src/NumericCard.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/NumericCard.o src/NumericCard.cpp

bin/FigureCard.o: src/FigureCard.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/FigureCard.o src/FigureCard.cpp

bin/PlayerType1.o: src/PlayerType1.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType1.o src/PlayerType1.cpp

bin/PlayerType2.o: src/PlayerType2.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType2.o src/PlayerType2.cpp

bin/PlayerType3.o: src/PlayerType3.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType3.o src/PlayerType3.cpp

bin/PlayerType4.o: src/PlayerType4.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PlayerType4.o src/PlayerType4.cpp
	
bin/Deck.o: src/Deck.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Deck.o src/Deck.cpp

#Clean the build directory
clean: 
	rm -f bin/*
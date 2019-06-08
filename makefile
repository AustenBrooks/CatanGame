CC = g++
CFLAG = -std=c++11
test: main.o card.o players.o board.o
	$(CC) main.o board.o card.o players.o -o test

main.o: main.cpp card.h board.h players.h
	$(CC) -c main.cpp $(CFLAG)

board.o: board.cpp board.h
	$(CC) -c board.cpp $(CFLAG)

card.o: card.cpp card.h players.h
	$(CC) -c card.cpp $(CFLAG)

players.o: players.cpp players.h
	$(CC) -c players.cpp $(CFLAG)

clean:
	rm *.o test
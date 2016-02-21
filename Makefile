##Navjot Singh 912224741

all: tetris

CXXFLAGS=-g -Wall

Tetromino.o: Tetromino.cpp Tetromino.h 
Board.o: Board.cpp Board.h 
tetris.o: tetris.cpp Tetromino.h Board.h

tetris: tetris.o Board.o Tetromino.o

	$(CXX) -o $@ $^  $(LDFLAGS)

clean:
	rm -f *.o tetris

#pragma once
// Battleship.h
// Declaration of class Battleship
// Member functions are defined in Battleship.cpp

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class Battleship
{
public:
	// Types of Searches
	void rawLRLinear();
	void rawUDLinear();
	void diagonalLinear();
	void txTLRLinear(); // two by two
	void txTUDLinear(); // two by two
	void txTDiagonalLinear(); // two by two

	void spiralBinary();
	void rawBinary();

	void randomGuess();

	// Board Functions
	void resetBoard();
	void clearBoard();
	void showBoard(); // debugging function
	int boardSum();

	// ship functions
	int xValue();
	int yValue();
	void determineOrientation();
	void placeShips(int type); // type of ship
	void cannon(int r, int c);	// used for calling rows

	// set/get functions
	void setMoves();
	int getMoves();

	int moves; // moves to completion

private:
	static const int rows = 10;
	static const int columns = 10;
	int board[rows][columns] = { 0 };

	int carrier = 5;
	int battleship = 4;
	int cruiser = 3;
	int submarine = 3;
	int destroyer = 2;
	int x; // x coord
	int y; // y coord

	

	int orientation[5] = { 0 } ;
};
#endif 
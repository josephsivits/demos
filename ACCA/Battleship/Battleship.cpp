// Implementation File - Battleship.cpp

#include "Battleship.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

///////////////////
// BOARD FUNCTIONS
//////////////////

void Battleship::resetBoard()
{
	clearBoard();
	determineOrientation();
}

void Battleship::clearBoard() 
{
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= columns; j++)
		{
			board[i][j] = 0;
		}
	}
}

int Battleship::xValue()
{ 
	return rand() % 10 + 1;
}

int Battleship::yValue()
{
	return rand() % 10 + 1;
}

void Battleship::determineOrientation()
{
	for (int i = 1; i <= 5; i++) // 5 ships
	{
		x = xValue();
		y = yValue();
		int oHor = 1; // horizontal orientation
		int oVer = 3; // verticle orientation
		
		switch (i)
		{
		case 1:
			x + 2 > 10 ? oHor = 2 : oHor = 1;
			y + 2 > 10 ? oVer = 3 : oVer = 4;
			rand() % 2 == 1 ? orientation[i] = oHor : orientation[i] = oVer;
			placeShips(1);
			break;
		case 2:
			x + 3 > 10 ? oHor = 2 : oHor = 1;
			y + 3 > 10 ? oVer = 3 : oVer = 4;
			rand() % 2 == 1 ? orientation[i] = oHor : orientation[i] = oVer;
			placeShips(2);
			break;
		case 3:
			x + 3 > 10 ? oHor = 2 : oHor = 1;
			y + 3 > 10 ? oVer = 3 : oVer = 4;
			rand() % 2 == 1 ? orientation[i] = oHor : orientation[i] = oVer;
			placeShips(3);
			break;
		case 4:
			x + 4 > 10 ? oHor = 2 : oHor = 1;
			y + 4 > 10 ? oVer = 3 : oVer = 4;
			rand() % 2 == 1 ? orientation[i] = oHor : orientation[i] = oVer;
			placeShips(4);
			break;
		case 5:
			x + 5 > 10 ? oHor = 2 : oHor = 1;
			y + 5 > 10 ? oVer = 3 : oVer = 4;
			rand() % 2 == 1 ? orientation[i] = oHor : orientation[i] = oVer;
			placeShips(5);
			break;
		}

		
	}
}

void Battleship::placeShips(int type)
{
	switch (type)
	{
	case 1: // first 2x1 ship
		if (orientation[type] == 1)
		{
			board[x][y] =  1;
			board[x+1][y] =  1;
		}
		if (orientation[type] == 2)
		{
				board[x][y] = 1;
				board[x-1][y] = 1;
		}
		if (orientation[type] == 3)
		{
			board[x][y] = 1;
			board[x][y+1] = 1;
		}
		if (orientation[type] == 4)
		{
			board[x][y] = 1;
			board[x][y-1] = 1;
		}
		break;
		
	case 2: // 3x1 ship
		if (orientation[type] == 1)
		{
			board[x][y] = 1;
			board[x + 1][y] = 1;
			board[x + 2][y] = 1;
		}
		if (orientation[type] == 2)
		{
			board[x][y] = 1;
			board[x - 1][y] = 1;
			board[x - 2][y] = 1;
		}
		if (orientation[type]==3)
		{
			board[x][y] = 1;
			board[x][y + 1] = 1;
			board[x][y + 2] = 1;
		}
		if (orientation[type] == 4)
		{
			board[x][y] = 1;
			board[x][y - 1] = 1;
			board[x][y - 2] = 1;
		}
		break;

	case 3: // 3x1 ship
		if (orientation[type] == 1)
		{
			board[x][y] = 1;
			board[x + 1][y] = 1;
			board[x + 2][y] = 1;
		}
		if (orientation[type] == 2)
		{
			board[x][y] = 1;
			board[x - 1][y] = 1;
			board[x - 2][y] = 1;
		}
		if (orientation[type] == 3)
		{
			board[x][y] = 1;
			board[x][y + 1] = 1;
			board[x][y + 2] = 1;
		}
		if (orientation[type] == 4)
		{
			board[x][y] = 1;
			board[x][y - 1] = 1;
			board[x][y - 2] = 1;
		}
		break;

	case 4: // 4x1 ship
		if (orientation[type] == 1)
		{
			board[x][y] = 1;
			board[x + 1][y] = 1;
			board[x + 2][y] = 1;
			board[x + 3][y] = 1;
		}
		if (orientation[type] == 2)
		{
			board[x][y] = 1;
			board[x - 1][y] = 1;
			board[x - 2][y] = 1;
			board[x - 3][y] = 1;
		}
		if (orientation[type] == 3)
		{
			board[x][y] = 1;
			board[x][y+1] = 1;
			board[x][y+2] = 1;
			board[x][y+3] = 1;
		}
		if (orientation[type] == 3)
		{
			board[x][y] = 1;
			board[x][y - 1] = 1;
			board[x][y - 2] = 1;
			board[x][y - 3] = 1;
		}
		break;

	case 5: // 5x1 ship
		if (orientation[type] == 1)
		{
			board[x][y] = 1;
			board[x + 1][y] = 1;
			board[x + 2][y] = 1;
			board[x + 3][y] = 1;
			board[x + 4][y] = 1;
		}
		if (orientation[type] == 2)
		{
			board[x][y] = 1;
			board[x - 1][y] = 1;
			board[x - 2][y] = 1;
			board[x - 3][y] = 1;
			board[x - 4][y] = 1;
		}
		if (orientation[type] == 3)
		{
			board[x][y] = 1;
			board[x][y + 1] = 1;
			board[x][y + 2] = 1;
			board[x][y + 3] = 1;
			board[x][y + 4] = 1;
		}
		if (orientation[type] == 3)
		{
			board[x][y] = 1;
			board[x][y - 1] = 1;
			board[x][y - 2] = 1;
			board[x][y - 3] = 1;
			board[x][y - 4] = 1;
		}
		break;

	} // end switch

} // end object placeShips()

// debugging function
void Battleship::showBoard()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if(board[i][j] > 1)
				board[i][j] = 1;
			cout << setw(2) << board[i][j];
			if (j == 10) cout << endl;
		}

	}
}

int Battleship::boardSum()
{
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if(board[i][j] > 1)
				board[i][j] = 1;
			sum += board[i][j];
		}
	}
	return sum;
}

/////////////////////////////
// BEGIN SEARCHING ALGORITHMS
/////////////////////////////

void Battleship::cannon(int r, int c)
{
	if (boardSum() > 0)
	{
		moves += 1;
		if (board[r][c] >= 1)
		{
			board[r][c] = 0;
			if (r + 1 <= 10) cannon(r + 1, c);
			if (r - 1 >= 1) cannon(r - 1, c);
			if (c + 1 <= 10) cannon(r, c + 1);
			if (c - 1 >= 1) cannon(r, c - 1);
		}
		// if the board is occupied by a ship, set as 0 indicating "hit"
	}
}

void Battleship::rawLRLinear()
{
	for (int i = 1; i <= 10; i++) // row
	{
		for (int j = 1; j <= 10; j++) // column
		{
			if (i % 2 == 1) // every other row
			{
				if (j % 2 == 0) // every other column of every other row
				{
					cannon(i, j);
				}
			}
			// should replicate checker pattern
			if (i % 2 == 0)
			{
				if (j % 2 == 1)
				{
					cannon(i, j);
				}
			}
		}
	}
}


void Battleship::rawUDLinear()
{
	for (int i = 1; i <= 10; i++) // row
	{
		for (int j = 1; j <= 10; j++) // column
		{
			if (i % 2 == 1) // every other row
			{
				if (j % 2 == 0) // every other column of every other row
				{
					cannon(j, i);
				}
			}
			// should replicate checker pattern
			if (i % 2 == 0)
			{
				if (j % 2 == 1)
				{
					cannon(j, i);
				}
			}
		}
	}
}

void Battleship::diagonalLinear()
{
	//going down vertically
	for (int i = 1; i <= 10; i++)
	{
		int j = 1; // initially column 1
		if (i % 2 == 1) // every other row
		{
			cannon(i, j);
			int iPtr = i;
			while (j <= i)
			{
				j++;
				iPtr--;
				cannon(iPtr, j);
				
			}

		}

		// going across horizontally
		for (int i = 10; i >= 1; i--)
		{
			int j = 10; // initially column 10
			if (i % 2 == 1) // every other row
			{
				cannon(i, j);
				int iPtr = i;
				while (j >= i)
				{
					j--;
					iPtr++;
					cannon(iPtr, j);
				}
			}
		}
	}
}

void Battleship::txTLRLinear()
{
	for (int j = 1; j <= 5; j++) // 2x5 is 10
	{ // j is columns
		for (int i = 1; i <= 5; i++)
		{ //  i is rows
			int s = rand() % 4 + 1;
			//  program will randomly generate positions
			switch (s) {
			case 1:
				cannon(i * 2 - 1, j * 2 - 1);
				break;
			case 2:
				cannon(i * 2, j * 2 - 1);
				break;
			case 3:
				cannon(i * 2, j * 2);
				break;
			case 4:
				cannon(i * 2 - 1, j * 2);
				break;
			}
		}
	}
}

void Battleship::txTUDLinear()
{
	for (int i = 1; i <= 5; i++) // 2x5 is 10
	{ // i is rows
		for (int j = 1; j <= 5; j++)
		{ //  j is columns
			int s = rand() % 4 + 1;
			//  program will randomly generate positions
			switch (s) {
			case 1:
				cannon(i * 2 - 1, j * 2 - 1);
				break;
			case 2:
				cannon(i * 2, j * 2 - 1);
				break;
			case 3:
				cannon(i * 2, j * 2);
				break;
			case 4:
				cannon(i * 2 - 1, j * 2);
				break;
			}
		}
	}
}

void Battleship::txTDiagonalLinear()
{
	// vertically going down
	for (int i = 1; i <= 5; i++)
	{
		int j = 1;
		int flag = i;
		while (flag >= 1)
		{
			int s = rand() % 4 + 1;
			switch (s)
			{
				case 1:
					cannon(i * 2 - 1, j * 2 - 1);
					flag--;
					j++;
					break;
				case 2:
					cannon(i * 2, j * 2 - 1);
					flag--;
					j++;
					break;
				case 3:
					cannon(i * 2, j * 2);
					flag--;
					j++;
					break;
				case 4:
					cannon(i * 2 - 1, j * 2);
					flag--;
					j++;
					break;
			}
			if (i > 5 || i < 1 || j > 5 || j < 5) break;
		}
	}
	// horizontally going across
	for (int j = 1; j <= 5; j++)
	{
		int i = 1;
		int flag = j;
		while (flag >= 1)
		{
			int s = rand() % 4 + 1;
			switch (s)
			{
			case 1:
				cannon(i * 2 - 1, j * 2 - 1);
				flag--;
				j++;
				break;
			case 2:
				cannon(i * 2, j * 2 - 1);
				flag--;
				j++;
				break;
			case 3:
				cannon(i * 2, j * 2);
				flag--;
				j++;
				break;
			case 4:
				cannon(i * 2 - 1, j * 2);
				flag--;
				j++;
				break;
			}
			if (i > 5 || i < 1 || j > 5 || j < 5) break;
		}
	}
}

// will search in a "spiral" fashion from outside center
void Battleship::spiralBinary()
{
	cannon(5, 5);
	// 5 because 5 from center will cover the whole board
	for (int i = 1; i <= 5; i++)
	{
		cannon(5, 5 + i);
		cannon(5 + i, 5 + i);
		cannon(5 + i, 5);
		cannon(5 + i, 5 - i);
		cannon(5, 5 - i);
		cannon(5 - i, 5 - i);
		cannon(5 - i, 5);
		cannon(5 - i, 5 + i);
	}
}

// will search for the ships in pure binary algorithm
void Battleship::rawBinary()
{
	for (int i = 1; i <= 10; i++)
	{
		cannon(i, 10 / i); // search rows
	}

	for (int j = 1; j <= 10; j++)
	{
		cannon(10 / j, j); // search columns
	}
}

void Battleship::randomGuess()
{
	int row = 0, column = 0;
	while (boardSum() != 0)
	{
		row = rand() % 10 + 1;
		column = rand() % 10 + 1;
		cannon(row, column);
	}
}

////////////////////
// SET/GET FUNCTIONS
////////////////////

void Battleship::setMoves()
{
	moves = 1;
}

int Battleship::getMoves()
{
	return moves;
}

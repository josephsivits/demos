// BattleshipTest.cpp
// Driver File
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "Battleship.h"
#include "Battleship.cpp"
using namespace std;

int main()
{
	srand(time(NULL));
	Battleship battleship;

	int value[10] = { 0 };


	for (int i = 0; i <= 20; i++)
	{
		battleship.resetBoard();
		battleship.setMoves();
		int s = i % 9;
		switch (s)
		{
		case 0:
			battleship.rawLRLinear();
			value[0] += battleship.getMoves();
			break;

		case 1:
			battleship.rawUDLinear();
			value[1] += battleship.getMoves();
			break;

		case 2:
			battleship.diagonalLinear();
			value[2] += battleship.getMoves() / 4;
			// program has to run 4 times, dividing by 4 reduces redundancy
			break;

		case 3:
			battleship.txTLRLinear();
			value[3] += battleship.getMoves();
			break;

		case 4:
			battleship.txTUDLinear();
			value[4] += battleship.getMoves();
			break;

		case 5:
			battleship.txTDiagonalLinear();
			value[5] += battleship.getMoves() * 4;
			// value is based on estimate, only searches first quadrent to avoid recursion
			break;

		case 6:
			battleship.spiralBinary();
			value[6] += battleship.getMoves();
			break;

		case 7:
			battleship.rawBinary();
			value[7] += battleship.getMoves();
			break;

		case 8:
			battleship.randomGuess();
			value[8] += battleship.getMoves();
			break;

		default:
			NULL;

		} // end of switch
	}

	///////////////////////

	// Print averages

	for (int i = 0; i <= 8; i++)
	{
		double avg = value[i] / 1250;
		if (i == 8) double avg = value[i] * 10 / 1250;
		switch (i)
		{
		case 0:
			cout << "\nAverage moves to complete game for Left -> Right Linear Algorithm: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 1:
			cout << "\nAverage moves to complete game for Up -> Down Linear Algorithm: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 2:
			cout << "\nAverage moves to complete game for Diagonal Linear Algorithm: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 3:
			cout << "\nAverage moves to complete game for Left -> Right Linear Algorithm using 2x2 method: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 4:
			cout << "\nAverage moves to complete game for Up -> Down Linear Algorithm using 2x2 method: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 5:
			cout << "\nAverage moves to complete game for diagonol Linear Algorithm using 2x2 method: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 6:
			cout << "\nAverage moves to complete game for Spiral Binary Algorithm: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 7:
			cout << "\nAverage moves to complete game for Binary Algorithm: "
				<< endl << setw(12) << right << fixed << setprecision(3)
				<< avg << endl;
			break;

		case 8:
			battleship.randomGuess();
			cout << "\nAverage moves to complete game using random guesses: "
				<< endl << setw(8) << right << fixed << setprecision(3)
				<< battleship.getMoves() << ".000" << endl;
			break;

		default:
			NULL;
		}
	}
	cout << endl;
	return 0;
}

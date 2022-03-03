// source.cpp
// code for AI for demonstrating supervised learning vs. reinforcement learning in c++
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

class supervisedLearning
{
public:
	void findPercent(int);		// find win percentage for card value
	void hitUntilBust();		// finds hits until bust for a card value

	bool dealerHand(int);		// Dealer's response to a players card
								// true if dealer wins, false if dealer busts
	int hit();					//	"hit" in blackjack (call for a card)

	void init();
	void playBlackjack(int);		// function to simulate blackjack
	void printTable();
	void printWinLoss();

	float wp[22] = {};			// win percentage float array
	float hUB[22] = {};			// hit until bust float array
	int winLoss[2] = {};		// win loss float array
};

///////////////////////////////////////////////////////////////////

class reinforcementLearning
{
public:
	void findHits();
	void findWins();		// similar
	bool dealerHand(int);

	int hit();

	void init();
	void playBlackjack(int);
	void printTable();
	void printWinLoss();

	float wp[22] = {};		// win points
	float hp[22] = {};		// hit points
	float eArr[22] = {};	// exaggerated array
	int winLoss[2] = {};	// win loss

	int maxIndex = 0;		// max index in the exaggerated array
};

///////////////////////////////////////////////////////////////////

void supervisedLearning::findPercent(int x)
{
	for (int i = 0; i < 10000; i++) {
		if (!dealerHand(x)) wp[x]++;
	}
}

int supervisedLearning::hit()
{
	return (rand() % 10 + 1);
}

bool supervisedLearning::dealerHand(int x)
{
	int dealerCards = rand() % 11 + 1;
	while (dealerCards < 21) {
		dealerCards += hit();
		if (dealerCards > 21) return false;
		if (dealerCards >= x) return true;
	}
	return false;
}

void supervisedLearning::hitUntilBust()
{
	for (int i = 1; i <= 21; i++)
	{
		for (int j = 0; j < 10000; j++)
		{
			int hand = i;
			while (hand <= 21)
			{
				hand += hit();
				hUB[i]++;
			}
		}
		hUB[i] /= 10000;
	}
}

void supervisedLearning::playBlackjack(int sims)
{
	for (int i = 0; i < sims; i++)
	{
		int hand = rand() % 21 + 1;
		while (hUB[hand] >= 2)
		{
			hand += hit();
			if (hand >= 21) break;
			if (hand < 2) break; // consider getting rid of these 2
		}

		while (wp[hand] <= 25) { // win percentage less than 25%, arbitrary
			if (hand > 21) break;
			hand += hit();
		}

		// check for wins, 0 = loss 1 = win
		if (hand > 21)
		{
			winLoss[0]++;
		}
		else if (dealerHand(hand))
		{
			winLoss[0]++;
		}
		else
		{
			winLoss[1]++;
		}
	}
}

void supervisedLearning::init()
{
	hitUntilBust();

	for (int i = 1; i <= 21; i++)
	{
		findPercent(i);
		wp[i] /= 100;
	}
}

void supervisedLearning::printTable()
{
	for (int i = 1; i <= 21; i++)
	{
		cout << i << " AVG Hits Unitl Bust: " << hUB[i] << endl;
		cout << i << " AVG Win Percentage : " << wp[i] << endl;
	}

	cout << endl << endl;
}

void supervisedLearning::printWinLoss()
{
	cout << "\nSupervised Learning Wins and Losses" << endl;
	cout << "Wins: " << winLoss[1] << endl;
	cout << "Loss: " << winLoss[0] << endl;
}

///////////////////////////////////////////////////////////////////

void reinforcementLearning::findHits()
{
	// 1000 training, gets points if doesn't bust
	for (int i = 1; i <= 21; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (i + hit() <= 21) hp[i]++;
		}
	}
}

void reinforcementLearning::findWins()
{
	for (int i = 1; i <= 21; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (!dealerHand(i)) wp[i]++;
		}
	}
}

bool reinforcementLearning::dealerHand(int x)
{
	int dealerCards = rand() % 11 + 1;
	while (dealerCards < 21) {
		dealerCards += hit();
		if (dealerCards > 21) return false;
		if (dealerCards >= x) return true;
	}
	return false;
}

int reinforcementLearning::hit()
{
	return (rand() % 10 + 1);
}

void reinforcementLearning::init()
{
	findHits();
	findWins();
	for (int i = 1; i <= 21; i++)
	{
		eArr[i] = wp[i] * hp[i];
	}

	int max = 0;
	for (int i = 1; i <= 21; i++)
	{
		if (eArr[i] > max)
		{
			max = eArr[i];
			maxIndex = i;
		}
	}
}

void reinforcementLearning::printTable()
{
	cout << "\t hp \twp\tcs" << endl;
	for (int i = 1; i <= 21; i++)
	{
		cout << i <<'\t' << hp[i] << '\t' << wp[i] << '\t' << (hp[i] * wp[i]) << endl;
	}
	cout << "\n * hp = Hit Points \n * wp = Win Points\n * cs = Compound Score" << endl;
}

void reinforcementLearning::playBlackjack(int sims)
{
	for (int i = 0; i < sims; i++)
	{
		int hand = rand() % 21 + 1;
		while (hand < maxIndex)
		{
			hand += hit();
		}
		if (hand > 21)
			winLoss[0]++;
		else if (dealerHand(hand))
			winLoss[0]++;
		else
			winLoss[1]++;
	}
}

void reinforcementLearning::printWinLoss()
{
	cout << "\nReinforcement Learning Wins and Losses" << endl;
	cout << "Wins: " << winLoss[1] << endl;
	cout << "Loss: " << winLoss[0] << endl;
}

///////////////////////////////////////////////////////////////////

int main()
{

	srand(time(NULL));
	supervisedLearning sL;
	sL.init();
	sL.printTable();

	reinforcementLearning rL;
	rL.init();
	rL.printTable();

	int s = 0;
	cout << "Enter how many simulations you want to run: ";
	cin >> s;

	sL.playBlackjack(s);
	sL.printWinLoss();

	rL.playBlackjack(s);
	rL.printWinLoss();

	return 0;
}
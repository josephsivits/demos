/*

Please write an application that runs 1000 games of craps and answers:
a. How many games are one on rolls 1->20+ rolls
b. How many games are lost on rolls 1->20+ rolls
c. What are chances of winning craps
d. What is average length of a craps game?
*/

import java.security.SecureRandom;
import java.util.Formatter;

public class Craps {

	// return total between 2->12
	public static int roll() {
		SecureRandom rand = new SecureRandom();
		return 2 + rand.nextInt(11);
	} // end method roll

	public static boolean checkLoss(int x) {
		return (x == 2 || x == 3 || x == 12);
	}

	public static boolean checkWin(int x) {
		return (x == 7 || x == 11);
	}

//	SecureRandom rand = new SecureRandom();

	public static void main(String[] args) {
		System.out.println("Craps statistics in Java\nby Joseph Sivits\n");


		int win[] = new int[22];
		int loss[] = new int[22]; // store position 21 as when win with 20+ rolls
		int totalWins = 0, totalLosses = 0, totalRolls = 0;
		for(int sim = 0; sim < 1000; sim++) {
			int point = roll();
			totalRolls++;
			int roll = 1, shoot = 0;
			if(checkLoss(point)) {
				loss[roll]++;
				totalLosses++;
				continue;
			} else if(checkWin(point)) {
				win[roll]++;
				totalWins++;
				continue;
			} else {
				while(shoot != point)
				{
					shoot = roll();
					roll++;
					totalRolls++;
					if(shoot == 7) {
						if(roll > 20) loss[21]++;
						else loss[roll]++;
						totalLosses++;
						break; // FIXES OVERFLOW ERROR
					} else if(shoot == point) {
						if(roll > 20) win[21]++;
						else win[roll]++;
						totalWins++;
						break; // FIXES OVERFLOW ERROR
					} // end if else if block
				} // end while
			} // end if...else
		} // end for loop

		/*

		PRINTING SOLUTION

		*/
		for(int i = 1; i <= 20; i++)
		{
			System.out.printf("%4d games won and %4d games lost on roll #%2d",win[i],loss[i],i);
			System.out.println();
		} // end for loop
		System.out.printf("%4d games won and %4d games lost after the 20th roll",win[21],loss[21]);
		System.out.println();

		float fl = totalWins;
		fl/=10;
		System.out.printf("The chances of winning are %4d / 1000 = %.2f%%\n",totalWins,fl);

		float avgRolls = totalRolls;
		avgRolls/=1000;
		System.out.printf("The average game length is %.2f rolls.\n",avgRolls);
	} // end method main
} // end public class Craps

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <fstream>
using std::ofstream;

#include <cstdlib>
using std::exit;

void wordGenerator(const int * const);

int main()
{
	int phoneNumber[7] = { 0 }; // holds phone number

	// prompt user to enter phone number
	cout << "Enter a phone number (digits 2 through 9) in the form: xxx-xxxx\n";

	// loop 8 times: 7 digits plus hyphen (hypen is not placed in phone number)
	for(int u = 0, v = 0; u < 8; u++)
	{
		int i = cin.get();

		// test if i is between 0 and 9
		if(i >= '0' && i <= '9')
			phoneNumber[v++] = i - '0';
	} // end for

	wordGenerator(phoneNumber); // form words from phone number
	return 0;
} // end main

// function to form words based on phone number
void wordGenerator(const int * const n)
{
	// set output stream and open output file
	ofstream outFile("phone.dat", ios::out);

	// letters corresponding to each number
	//								   0	 1	   2	 3	   4	 5	   6	 7	   8	 9
	const char * phoneLetters[10] = {"ZZZ","OOO","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
	
	// terminate if file could not be opened
	if(!outFile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // end if

	int count = 0; // number of words formed
	// output all possible compinations
	for(int i1 = 0; i1 <= 2; i1++)
	{
		const char * ptr1 = phoneLetters[n[0]];
		for(int i2 = 0; i2 <= 2; i2++)
		{
			const char * ptr2 = phoneLetters[n[1]];
			for(int i3 = 0; i3 <= 2; i3++)
			{
				const char * ptr3 = phoneLetters[n[2]];
				for(int i4 = 0; i4 <= 2; i4++)
				{
					const char * ptr4 = phoneLetters[n[3]];
					for(int i5 = 0; i5 <= 2; i5++)
					{
						const char * ptr5 = phoneLetters[n[4]];
						for(int i6 = 0; i6 <= 2; i6++)
						{ 
							const char * ptr6 = phoneLetters[n[5]];
							for(int i7 = 0; i7 <= 2; i7++)
							{
								const char * ptr7 = phoneLetters[n[6]];
								// write code here
								outFile << ptr1[i1] << ptr2[i2] << ptr3[i3] << ptr4[i4] << ptr5[i5] << ptr6[i6] << ptr7[i7] << " ";

								if(++count%9 == 0) // form rows
									outFile << '\n';
							} // end for i7
						} // end for i6
					} // end for i5
				} // end for i4
			} // end for i3
		} // end for i2
	} // end for i1

	// output phone number
	outFile << "\nPhone number is: ";

	for(int i = 0; i < 7; i++)
	{
		if(i == 3)
			outFile << '-';
		outFile << n[i];
	} // end for i

	// closing output file
	outFile.close();
} // end function wordGenerator

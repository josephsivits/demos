#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

template<typename T, typename U>
U quotient(const T, const T);

int main()
{
    ifstream inFile("numeratorsDenominators.dat",ios::in);
    if(!inFile)
    {
        cerr << "inFile could not be opened" << endl;
        exit(1);
    }
    int numerator = 0, denominator = 0;

    ofstream outFile("results.dat", ios::out);
    if(!outFile)
    {
        cerr << "outFile could not be opened" << endl;
        exit(1);
    }

    /*

    FOR WHEN NOT INPUTTING/OUTPUTTING FILES

    int numerator = 0, denominator = 0;
    cout << "Enter numerator:   ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    */

    cout << setprecision(4);

    while (inFile >> numerator >> denominator)
    {
        try
        {
            outFile << numerator << " / " << denominator << " = " << quotient<int, float>(numerator,denominator) << endl;
        }
        catch(const string & e)
        {
            outFile << e << endl;
        }
    }
    

}

template<typename T, typename U>
U quotient(const T numerator, const T denominator)
{
    const string e = "Attempted to divide by zero";
    if(denominator == 0)
        throw e;
    return static_cast<U> (numerator)/denominator;
}

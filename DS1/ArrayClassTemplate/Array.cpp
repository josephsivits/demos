#include "Array.h"
#include <ctime>
#include <cmath>
#include <random>
#include <typeinfo>
#include <iomanip>
#include <iostream>
using namespace std;

template<typename T>
Array<T>::Array()
{
	size = 5;
	arr = new T[size];
}

template<typename T>
Array<T>::Array(int s)
{
	size = s;
	arr = new T[size];
}

template<typename T>
int Array<T>::getSize() const
{
	return size;
}

template<typename T>
void Array<T>::generateInt()
{
	cout << "Generating integer array size " << getSize() << endl;
	srand(time(nullptr));
	for(int i = 0; i < getSize(); i++)
	{
		int x = ((rand() % 2 == 1) ? rand() % 1000: -(rand() % 1000));
		arr[i] = x;
	}
}

template<typename T>
void Array<T>::generateDouble()
{
	cout << "Generating double array size" << getSize() << endl;
	srand(time(nullptr));
	for(int i = 0; i < size; i++)
	{
		double x = (rand() % 2 == 1? (double)rand()/RAND_MAX : -(double)rand() / RAND_MAX);
		x *= 1000;
		arr[i] = x;
	}
}

template<typename T>
void Array<T>::printArray() const
{
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template<typename T>
void Array<T>::printArray(int lowSubscript, int highSubscript) const
{
	cout << "Printing array between " << lowSubscript << " and " << highSubscript << " inclusive." << endl;
	lowSubscript--;
	while(lowSubscript <= highSubscript)
	{
		cout << arr[lowSubscript] << " ";
		lowSubscript++;
	}
	cout << endl;
}

template<typename T>
double Array<T>::printAverage() const
{
	double average = 0;
	for(int i = 0; i < size; i++)
		average += arr[i];

	return average / size;
}

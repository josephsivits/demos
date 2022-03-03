// file for Array.h implementation
#include "Array.h"
// library required for srand
#include <ctime>
// library required for double mod
#include <cmath>

// library for dist() function
#include <random>

//library for typeid function
#include <typeinfo>

#include <iomanip>
#include <iostream>
using namespace std;

// default constructor for when size is not given by user
// for some reason it aint working
template <typename T>
Array<T>::Array()
{
	cout << "Initializing constructor type: " << typeid(T).name() << endl;
	size = 5;
	arr = new T[size];
}

template <typename T>
Array<T>::Array(int s)
{
	cout << "Initializing constructor type: " << typeid(T).name() << endl;
	size = s;
	arr = new T[size];
}

/*
template <typename T>
Array<T>::~Array()
{
	cout << "Initializing destructor type: " << typeid(T).name() << endl;
	delete[] arr;
}
*/
template <typename T>
int Array<T>::getSize()
{
	return size;
}

template <typename T>
void Array<T>::generateInt()
{
	cout << "Generating integer array size " << size << endl;
	srand(time(nullptr));
	for(int i = 0; i < size; i++)
	{
		int x = ((rand() % 2) == 1 ? rand() % 1000 : -(rand() % 1000));
		// write code to add it to the array
		arr[i] = x;
	}
}

// generating random doubles is kind of hard....
// I used library science for this...
template <typename T>
void Array<T>::generateDouble()
{
	cout << "Generating double array size " << size << endl;
	const int MIN = 0;
	const int MAX = 1000;
	srand(time(nullptr));
	for(int i = 0; i < size; i++)
	{
		// still need to check if this works
		//double x = uniform_real_distribution<double> dist(-1000.000, 1000.000);
		//int x = ((rand()%2)==1? rand()%1000 : -(rand()%1000));
		double x = (rand()%2==1)==1 ? (double)rand()/RAND_MAX : -(double)rand() / RAND_MAX;
		x = x * 1000;
		arr[i] = x;
	}
}

template <typename T>
void Array<T>::printArray()
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Array<T>::printArray(int lowSubscript, int highSubscript)
{
	// making lowest subscript inclusive
	cout << "Printing array " << lowSubscript << " and " << highSubscript << " inclusive." << endl;
	lowSubscript--;
	while(lowSubscript <= highSubscript)
	{
		cout << arr[lowSubscript] << " ";
		lowSubscript++;
	}
	cout << endl;
}

template <typename T>
double Array<T>::printAverage()
{
	double average = 0;
	for(int i = 0; i < size; i++)
	{
		average += arr[i];
	}
	//cout << setprecision(3) << average/size << endl;
	return average/size;
}

/*
template <typename T, typename U>
void Array<T>::typeCompare(const U * arr2)
{
	if(typeid(arr) == typeid(arr2)) cout << "yessir" << endl;
	else { cout << "nosir" << endl; }
}
*/

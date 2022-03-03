#ifndef ARRAY_H
#define ARRAY_H

// Array class for Lab 01A
template<typename T>
class Array
{
public:
	Array(); // default constructor, will set size to 5
	Array(int); // implied constructor, size will be user defined
	// destructor
	//~Array();

	int getSize();

	// MAKE A DESTRUCTOR
	void generateInt();
	void generateDouble();

	void printArray();
	void printArray(int, int);

	// could be incorrect, check for valid type
	double printAverage();

	// could be incorrect, check for valid type
	void typeCompare(const T *);

private:
	int size;
	T *arr; // could be wrong
};

#endif

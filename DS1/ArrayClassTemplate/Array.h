#ifndef ARRAY_H
#define ARRAY_H

// array template class for lab 01B
template<typename T>
class Array
{
public:
	Array();
	Array(int);

	int getSize() const;
	void generateInt();
	void generateDouble();

	void printArray() const;
	void printArray(int, int) const;

	double printAverage() const;

	void typeCompare(const T *);
private:
	int size;
	T *arr;
};

#endif

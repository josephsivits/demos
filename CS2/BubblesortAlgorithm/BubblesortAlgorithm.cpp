//tryna bubble sort alogrithm
#include <iostream>
#include <iomanip>

using namespace std;

void bubbleSort(int*const, const int);	// function prototype
void swap(int*const, int*const);	// function prototype

int main()
{
	const int arraySize = 10;
	int a[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

	cout << "Data items in original order\n";
	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];

	bubbleSort(a, arraySize);	// sort the array

	cout << "\nData items in ascending order\n";
	for (int j = 0; j < arraySize; j++)
		cout << setw(4) << a[j];

	cout << endl;

	system("pause");
	return 0;
}	// end main


// function to sort an array
void bubbleSort(int * const array, const int size)
{
	int smallest;	// index of smallest element

	//loop over size -1 elements
	for (int i = 0; i < size - 1; i++)
	{
		smallest = i;	// first index of remaining array

		//loop to find index of smallest element
		for (int index = i + 1; index < size; index++)

			if (array[index] < array[smallest])
			{
				smallest = index;
				swap(&array[i], &array[smallest]);
			}

		
	} // end (for?) if
} // end function bubbleSort

// swap values at memory locations to which element1Ptr and element2Ptr point
void swap(int * const element1Ptr, int * const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
} // end function swap
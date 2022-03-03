// Driver File
#include "Array.cpp"
using namespace std;

template<typename T, typename U>
bool typeCompare(T arr, U arr2)
{
	return (typeid(arr) == typeid(arr2))? true : false;
}

int main()
{
	Array<int> arrInt(8);
	Array<double> arrDouble(5);

	arrInt.generateInt();
	arrDouble.generateDouble();
	arrInt.printArray(2,4);

	cout << "\nPrinting entire integer array:\n";
	arrInt.printArray();

	cout << "\nPrinting entire double array:\n";
	arrDouble.printArray();

	cout << "\nAverage of integer array: " << arrInt.printAverage() << endl;
	cout << "\nAverage of double array: " << arrDouble.printAverage() << endl;

	if(typeCompare(arrInt,arrDouble))
	{
		cout << "Arrays are of same type" << endl;
	} else {
		cout << "Arrays are of different types" << endl;
	}
	return 0;
}

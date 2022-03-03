#include <iostream>
// using std::cin;
// using std::cout;
#include <string>
// using std::string
#include <exception>
// using std::exception;
// using std::runtime_error;
using namespace std;

// user-defined class using Method 2a (only applicable method for the instance)
class ExceptionHandling : public exception
{
public:
    const char * what() const throw()
    {
        return "Divide by zero error! (from user-defined class)";
    }
};

// stack unwinding applied to the functions
void method1() throw (string);
void method2a() throw (ExceptionHandling);
void method2b(); // runtime_error is implicit
void method3() throw(int);
void menu();

int main()
{
    cout << "Exception handling lab (divide by zero)\nby Joseph Sivits\n" << endl;

    menu();
    
    return 0;
}

void menu()
{
    int choice = 0;
    do
    {
        cout << "\nEnter 1 for method1 (user defined string)" << endl;
        cout << "Enter 2 for method2a (exception class system defined class)" << endl;
        cout << "Enter 3 for method2b (specialized class system defined class)" << endl;
        cout << "Enter 4 for method3 (default catch handler)" << endl;
        cout << "Enter -1 to quit" << endl;
        cout << "? ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                try
                {
                    method1();
                }
                catch(string e)
                {
                    cerr << e;
                }
                break;
            case 2:
                try
                {
                    method2a();
                }
                catch(ExceptionHandling e)
                {
                    cerr << e.what() << endl;
                }
                break;
            case 3:
                try
                {
                    method2b();
                }
                catch(runtime_error)
                {
                    cerr << "Divide by zero error! Try again." << endl;
                }
                break;
            case 4:
                try
                {
                    method3();
                }
                catch(...)
                {
                    cerr << "Divide by zero error! Try again." << endl;
                }
                break;
            case -1:
                cout << "Thank you for using this app!\n";
                exit(1);
                break;
            default:
                cout << "Error! " << choice << " not a valid choice." << endl;
                break;
        }
    } while(choice != -1);

}

void method1() throw (string)
{
    cout << "\nMethod 1\n";
    cout << "Enter the dividend followed by the divisor to find the quotient:\n? ";
    double dividend = 0, divisor = 0, quotient = 0;
    cin >> dividend >> divisor;

    string e = "Divide by zero error! Try again.\n";

    if(divisor == 0) throw e;
    quotient = dividend / divisor;
	cout << dividend << " / " << divisor << " = " << quotient << endl;
}

void method2a() throw (ExceptionHandling)
{
    cout << "\nMethod 2a\n";
    cout << "Enter the dividend followed by the divisor to find the quotient:\n? ";
    double dividend = 0, divisor = 0, quotient = 0;
    cin >> dividend >> divisor;

    string e = "Divide by zero error! Try again.\n";
    if(divisor == 0) throw ExceptionHandling();
    quotient = dividend / divisor;
	cout << dividend << " / " << divisor << " = " << quotient << endl;
}

void method2b()
{
    cout << "\nMethod 2b\n";
    cout << "Enter the dividend followed by the divisor to find the quotient:\n? ";
    double dividend = 0, divisor = 0, quotient = 0;
    cin >> dividend >> divisor;

    if(divisor == 0) throw runtime_error("This gets handled in the menu() function\n");
    quotient = dividend / divisor;
    cout << dividend << " / " << divisor << " = " << quotient << endl;
}

void method3() throw(int)
{
    cout << "\nMethod 3\n";
    cout << "Enter the dividend followed by the divisor to find the quotient:\n? ";
    double dividend = 0, divisor = 0, quotient = 0;
    cin >> dividend >> divisor;

    if(divisor == 0) throw 1;
    quotient = dividend / divisor;
    cout << dividend << " / " << divisor << " = " << quotient << endl;
}

//input output
#include <iostream>
//string functions
#include <string>

//shortening
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

//main function
int main()
{
	cout << "Hello World \n";
	
	int a = 0;
	int b = 9;
	int result = a + b;
	
	cout << result << " is the result \n";

	//different kinds of strings
	string myString = "This is a string";
	string antString("another string");
	string nextString{ "The next string" };

	double r = 5.0;

	double circle = 2 * PI * r;

	cout << circle;
	cout << NEWLINE;
	cout << NEWLINE;

	int age;
	//input age
	cin >> age;
	cout << NEWLINE;
	//print your age
	

	if (age > 0)
	{
		if (age <= 50)
		{
			cout << "Damn " << age << " is young";
			cout << NEWLINE;
		}
		else if (age > 50 && age <= 100)
		{
			cout << "Damn " << age << " is old";
			cout << NEWLINE;
		}
		else
		{
			cout << "Your age, " << age << " is off the charts!";
			cout << NEWLINE;
		}
		
	}

	for (int c = 0; c < 100; c++)
	{
		age++;
	}

	cout << "Your new age is " << age;
	cout << NEWLINE;

	int countDown = 10;

countItDown:
	cout << countDown << ", ";
	countDown--;
	if (countDown > 0) goto countItDown;

	cout << "Lift Off! ";
	cout << NEWLINE;

	return 0;

};


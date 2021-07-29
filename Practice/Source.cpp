//input output
#include <iostream>
//string functions
#include <string>

//shortening
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

namespace first
{
	int x = 10;
	int y = 11;
}

namespace second
{
	double x = 6.789;
	double y = 7.192;
}

void dealWithMyAge(int age)
{
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
}

double calcCircleDiameter(double r)
{
	return 2 * PI * r;
}

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

	double circle = calcCircleDiameter(5.0);

	cout << circle;
	cout << NEWLINE;
	
	int age;
	//input age
	cin >> age;
	cout << NEWLINE;
	//print your age
	dealWithMyAge(age);

	int countDown = 10;

countItDown:
	cout << countDown << ", ";
	countDown--;
	if (countDown > 0) goto countItDown;

	cout << "Lift Off! ";
	cout << NEWLINE;

	using first::x;
	using second::y;

	cout << x << "\n";
	cout << y << "\n";
	cout << first::y << "\n";
	cout << second::x << "\n";
	
	return 0;

};


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

string reverseString(string s)
{
	string r;

	for (int i = s.length()-1; i >= 0; i--)
	{
		r += s.at(i);
	}

	return r;
}

void isPalindrome(string orig, string rev)
{
	if (orig.compare(rev) != 0)
	{
		cout << "Not a palindrome";
		cout << NEWLINE;
	}
	else
	{
		cout << "is palindrome";
		cout << NEWLINE;
	}
}

void countDown() 
{
	int countDown = 10;
countItDown:
	cout << countDown << ", ";
	countDown--;
	if (countDown > 0) goto countItDown;

	cout << "Lift Off! ";
	cout << NEWLINE;
}

void firstSecond()
{
	using first::x;
	using second::y;

	cout << x << "\n";
	cout << y << "\n";
	cout << first::y << "\n";
	cout << second::x << "\n";
}

//main function
int main()
{
	cout << "Hello World \n";
	
	double circle = calcCircleDiameter(5.0);

	cout << circle;
	cout << NEWLINE;
	
	int age;
	//input age
	cin >> age;
	cout << NEWLINE;
	//print your age
	dealWithMyAge(age);

	countDown();

	firstSecond();

	string orig = "cat";
	string rev = reverseString(orig);

	cout << rev;
	cout << NEWLINE;

	isPalindrome(orig, rev);

	orig = "tat";
	rev.clear();
	rev = reverseString(orig);

	cout << rev;
	cout << NEWLINE;

	isPalindrome(orig, rev);

	return 0;

};


#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
	cout << "0 (Zero) Terminates:" << endl;
	list<int> integers;
	int number = 1;

	while (number != 0)
	{
		if (number < 0)
		{
			cerr << "Error! Number is below Zero (0)." << endl;
			cerr << "Terminating";
			break;
		}

		cout << "Enter Number: ";
		integers.push_back(number);
		cin >> number;

	}

	list<int>::const_iterator it;

	int counter = 0;
	int oldInt = 0;
	int newInt = 0;
	int theNumber = 0;
	int max = 0;

	for (it = integers.begin(); it != integers.end(); it++)
	{
		newInt = *it;

		if (oldInt == newInt)
		{
			counter++;
			theNumber = *it;
		}

		else
		{
			counter = 0;
		}

		if(counter > max)
		{
			max = counter;
		}

		oldInt = newInt;
	}

	cout << "The longest subsequence of equal numbers in given array is: "<< max + 1 << endl;
	cout << "The number is: " << theNumber;

	return 0;
}

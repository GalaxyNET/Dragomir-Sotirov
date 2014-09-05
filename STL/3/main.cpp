#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int main()
{
	cout << "0 (Zero) Terminates:" << endl;
	stack<int> integers;
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
		cin >> number;

		if (number == 0)
		{
			break;
		}

		integers.push(number);
	}

	cout << "Numbers backwards printed are: "<<endl;

	while (!integers.empty())
	{
       cout << integers.top() << " ";
       integers.pop();
	}

	return 0;
}

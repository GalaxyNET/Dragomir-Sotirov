#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{

list<int> integers;
int number = 1;

cout << "0 (Zero) Terminates:"<<endl;

while (number != 0)
{
	if (number < 0)
	{
		cerr << "Error! Number is below Zero (0)."<<endl;
		cerr << "Terminating";
		break;
	}

	cout << "Enter Number: ";
	cin >> number;
	integers.push_back(number);
}

list<int>::const_iterator it;

double sum = 0;
double counter = 0;

for (it = integers.begin(); it != integers.end() ; it++)
{
	sum+=*it;
	counter++;
}

counter-=1;
cout << "Sum from list is: "<<sum<<endl;
cout << "Average from list is: "<<sum/counter<<endl;

return 0;
}

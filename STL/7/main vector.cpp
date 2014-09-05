#include <iostream>
#include <vector>

using namespace std;

int main()
{
 vector<int> numbers;
 int number = 1;

 cout << "Enter a positive/negative integer: " << endl << "(0)-Zero Breaks" <<endl;

 while (number != 0)
 {

  cout << "Number :";
  cin >> number;

	 if (number == 0)
	 {
		 break;
	 }

  numbers.push_back(number);

 }

cout << "Removing negative numbers..." <<endl;

for (unsigned int i = 0; i < numbers.size(); i++)
{
	if (numbers[i] < 0)
	{
		numbers.erase(numbers.begin() + i);
		i--;
	}
}

cout << "Printing Positive Integers: ";

for (unsigned int i = 0; i < numbers.size(); i++)
{
		cout << numbers[i]<<" ";
}

 return 0;
}

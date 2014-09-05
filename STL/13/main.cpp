//21. Write a program that finds the longest subsequence of
//greater values in array.

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main() {
	int size = 9;
	int arr[] = {1, 2, 2, 2, 5, 6, 3, 1, 4};

	list<int> integers;

	integers.insert(integers.begin(), arr, arr + size);

	int counter = 1;
	int previous = arr[0];
	int current;
	int max = 0;

	int counterIter = 0;
	int counterIterHolder = 0;

	list<int>::const_iterator iter;
	for(iter = integers.begin(); iter != integers.end(); iter++)
	{
		counterIter++;
		current = *iter;

		if(current > previous)
		{
			counter++;
			if(counter > max)
			{
				max = counter;
				counterIterHolder = counterIter;
			}

		}
		else
		{
			counter = 1;
		}
		previous = current;
	}

	cout<<"The longest subsequence is: ";
	for(int i = counterIterHolder - max; i < counterIterHolder; i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}



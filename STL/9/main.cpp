#include <iostream>

using namespace std;

int main()
{
int array[9] = {2, 2, 3, 3, 2, 3, 4, 3, 3};

int counter = 0;
int maxCounter = 0;
int majorant;

for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
    {
       if (array[i] == array[j] )
       {
    	   counter++;
       }
    }

    if (maxCounter < counter)
    {
    	maxCounter = counter;
    	majorant = array[i];
    }

    counter = 0;
}

int arraySize = sizeof(array) / sizeof*array;

if ((arraySize/maxCounter) <= 2)
{
	cout << "The majorant of the array is number: "<<majorant<<endl;
	cout << "He repeat: "<<maxCounter<<" times in the array.";
}

else
{
	cout << "The array hasn't got a majorant number!"<<endl;
}

 return 0;
}

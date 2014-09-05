#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string animals[] = {"CAT", "DOG", "MONKEY", "FISH", "APE", "ELEPHANT"};

	for(unsigned i = 0; i < sizeof(animals)/sizeof*animals; i++)
	{
		for(unsigned j = i+1; j < sizeof(animals)/sizeof*animals; j++)
		{
			if(animals[j] < animals[i])
			{
				string temp = animals[i];
				animals[i] = animals[j];
				animals[j] = temp;
			}
		}
	}

	for(unsigned i = 0; i < sizeof(animals)/sizeof*animals; i++)
	{
		cout<<animals[i]<<endl;
	}

	return 0;
}

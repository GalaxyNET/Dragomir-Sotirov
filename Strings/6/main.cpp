#include <iostream>
using namespace std;

int main()
{
	string str = "This is a homework";

	char ch;
	int total = 0;
	int counterA = 0;
	int counterE = 0;
	int counterU = 0;
	int counterI = 0;
	int counterO = 0;
	int counterY = 0;

	for(unsigned i = 0; i < str.length(); i++)
	{
		ch = tolower(str[i]);
		switch(ch)
		{
			case 'a': counterA++; break;
			case 'e': counterE++; break;
			case 'u': counterU++; break;
			case 'i': counterI++; break;
			case 'o': counterO++; break;
			case 'y': counterY++; break;
			default: break;
		}
	}

	total = counterA + counterE + counterU + counterI + counterO + counterY;

	cout<<"The vowel 'a' appears "<<counterA<<" times."<<endl;
	cout<<"The vowel 'e' appears "<<counterE<<" times."<<endl;
	cout<<"The vowel 'u' appears "<<counterU<<" times."<<endl;
	cout<<"The vowel 'i' appears "<<counterI<<" times."<<endl;
	cout<<"The vowel 'o' appears "<<counterO<<" times."<<endl;
	cout<<"The vowel 'y' appears "<<counterY<<" times."<<endl;
	cout<<endl;
	cout<<"Total number of vowels is: "<<total<<endl;

	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	string str = "abcdefghijklmnopqrstuvwxyz{";
	string fill ="";
	string rev = "";
	int counter = 0;

	for(unsigned int i = 0; i <= str.length()/2; i++)
	{
		for(unsigned int j = 0; j < (str.length()-counter)/2; j++)
		{
			cout<<" ";
		}

		fill = str.substr(i,i);

		for(int s = fill.length()-1; s >=0; s--)
		{
			rev += fill[s];
		}

		cout<<fill<<str[i * 2]<<rev;
		rev = "";
		for(unsigned int k = 0; k < (str.length()-counter)/2; k++)
		{
			cout<<" ";
		}
		counter += 2;
		cout<<endl;
	}

	return 0;
}

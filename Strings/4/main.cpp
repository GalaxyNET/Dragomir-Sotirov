#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "print this string backwards uppercased";
	string result = "";
	char ch;

	for(int i = str.length()-1; i >= 0; i--)
	{
		ch = str[i];
		if(isalpha(ch))
		{
			if((int)(ch) < 91)
			{
				ch = tolower(ch);
			}
			else
			{
				ch = toupper(ch);
			}
		}
		result += ch;
	}

	cout<<result;
	return 0;
}

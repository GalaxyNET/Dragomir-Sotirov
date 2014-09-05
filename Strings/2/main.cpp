#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> strings;

	cout<<"Enter string 1: "<<endl;
	string str1 = "";
	getline(cin, str1);
	strings.push_back(str1);

	cout<<"Enter string 2: "<<endl;
	string str2 = "";
	getline(cin, str2);
	strings.push_back(str2);

	cout<<"Enter string 3: "<<endl;
	string str3 = "";
	getline(cin, str3);
	strings.push_back(str3);

	for(unsigned i = 0; i < strings.size(); i++)
	{
		string temp = strings[i];
		string clearTemp = "";
		for(unsigned j = 0; j < temp.length(); j++)
		{
			char ch = temp[j];
			if(isalpha(ch))
			{
				clearTemp += ch;
			}
		}

		if(clearTemp[clearTemp.length() - 1] == 'r' || (clearTemp[clearTemp.length() - 1] == 'y' && clearTemp[clearTemp.length() - 2] == 'a'))
		{
			cout<<temp<<endl;
		}
	}
	return 0;
}

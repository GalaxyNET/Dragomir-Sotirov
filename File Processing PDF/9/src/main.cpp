#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	ifstream firstText("read.txt" , ios::in);
	ifstream secondText("read2.txt" , ios::in);

	string str = "";
	string str2 = "";
	int count = 0 ;
	int count2 = 0 ;
	while(getline(firstText,str)){
		count++;
		while(getline(secondText,str2)){
			count2++;
			if ((str != str2) &&( count == count2)){
				cout << "line " << count << endl;
			}
		}
		secondText.clear();
		secondText.seekg(0);
		count2 = 0 ;
	}

	firstText.clear();
	firstText.seekg(0);

return 0;

}

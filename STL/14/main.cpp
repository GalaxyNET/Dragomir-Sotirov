//2. Write a program that reads several sentences from the
//console and reverses not only them but and every one of
//them word by word.

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
void reverseString( T text, int, T &);

int main()
{
	string santences;

	cout << "Enter a text: ";
	getline(cin, santences);

	string emptyString;

	int len = santences.size();
	reverseString(santences, len, emptyString);

	cout << emptyString  << endl;

	return 0;
}

template <typename T>
void reverseString(T text, int len, T &Empty)
{

   stack<char> myStack;

   for ( int i = 0; i < len; i++ )
   {
	   char ch = text.at(i);
	   myStack.push(ch);
   }

   while ( !myStack.empty() )
   {
	   stringstream str ;
	   str<<myStack.top();
       Empty.append(str.str());
       myStack.pop();
       str<<"";
   }
}

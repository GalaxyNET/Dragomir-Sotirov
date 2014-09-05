#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
 list<int> numbers;
 int number;

 while (number != 0)
 {
  cout << "Enter a positive integer: ";
  cin >> number;
  numbers.push_back(number);
 }
 numbers.sort();
 for (list<int>::iterator i = numbers.begin() ; i != numbers.end(); i++)
 {
  cout << *i;
 }

 return 0;
}

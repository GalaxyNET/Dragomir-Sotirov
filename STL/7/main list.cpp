//7. Write a program that removes from a given
//sequence all negative numbers.
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
	list<int> numbers;
	int number = 1;
	cout << "0 (ZERO) ending the sequence !!!" << endl;

	while (number != 0) {
		cout <<"Enter a value: ";
		cin >> number;
		numbers.push_back(number);
	}

	cout << "the list before removing : " << endl;

	list<int> removed = numbers;

	for (list<int>::iterator i = numbers.begin() ; i != numbers.end() ; i ++){
		cout << *i << " ";
		if(*i < 0){
			removed.remove(*i);
		}
	}
	cout << "The list after removing is: " << endl;
	for (list<int>::iterator i = removed.begin() ; i != removed.end() ; i ++){
		cout << *i << " " ;
	}
	return 0;
}

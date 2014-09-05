//6. Write a program that finds in a given array of integers how
//many times each of them presents.
//Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
//2  2 times
//3  4 times
//4  3 times

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	list<int> numbers;
	int number = 1;
	cout << "0 (ZERO) ending the sequence !!!" << endl;

	while (number != 0) {
		cout << "Enter a value: ";
		cin >> number;
		if (number != 0) {
			numbers.push_back(number);
		}
	}

	vector<string> countNumbers;
	countNumbers.push_back("");

	int count = 0;

	for (list<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
		for (list<int>::iterator k = numbers.begin(); k != numbers.end(); k++) {
			if (*i == *k) {

				count++;
			}
		}
		bool check = true;
		string result;

		stringstream num;
		stringstream counter;

		num << *i;
		counter << count;
		result.append(num.str() + " is found " + counter.str());

		counter << "";
		num << "";
		for (unsigned j = 0; j < countNumbers.size(); j++) {

			if (result == countNumbers[j]) {
				check = false;
				break;
			}

		}

		if (check == true) {
			countNumbers.push_back(result);
		}
		result = "";
		count = 0;
		check = true;

	}
	for (unsigned j = 0; j < countNumbers.size(); j++) {
		cout << countNumbers[j] << endl;
	}

	return 0;
}

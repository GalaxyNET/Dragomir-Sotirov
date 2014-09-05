#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	ifstream test("test.txt", ios::in);
	ifstream checkWords("words.txt", ios::in);
	ofstream result("result.txt", ios::out);
	if (!test) {
		cerr << "The file coud not be opened !!!";
		exit(1);
	}
	string word;
	string testText;
	while (test >> word) {
		testText.append(word + " ");
	}
	test.clear();
	test.seekg(0);

	int position = testText.find_first_of(".,:!?()", 0);
	while (position != string::npos) {
		testText.replace(position, 1, "");
		position = testText.find_first_of(".,:!?()", position);
	}
	vector<string> words;
	position = 0;
	int position2 = testText.find(" ");

	while (position2 != string::npos) {
		string word = testText.substr(position, position2 - position);
		words.push_back(word);
		position = position2 + 1;
		position2 = testText.find(" ", position);
	}

	string checkWord;
	int count = 0;
	vector<string> countWords;

	while (checkWords >> checkWord) {
		for (unsigned i = 0; i < words.size(); i++)
		{
			if (checkWord == words[i]) {
				count++;
			}
		}

		stringstream a;
		a << count;
		countWords.push_back(a.str() + " -> " + checkWord);
		count = 0;
		a << "";
	}

	sort(countWords.begin(), countWords.end());
	for (int i = countWords.size()-1; i >= 0; i--) {
		result << countWords[i] << endl;
	}

	return 0;
}

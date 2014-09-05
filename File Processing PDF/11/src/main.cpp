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
	   ifstream inClientFile( "words.txt", ios::in );
	   ifstream inClientFile2( "test.txt", ios::in );
	   ofstream outClientFile( "write.txt", ios::out );

	   if ( !inClientFile && !outClientFile)
	   {
	      cerr << "File could not be opened" << endl;
	      exit( 1 );
	   }

	      string word1;
	      vector <string> sentence;
	      vector <string> checks;

	   while ( inClientFile2 >> word1)
	   {
        sentence.push_back(word1);
	   }

	   while ( inClientFile >> word1)
	   {
        checks.push_back(word1);
	   }

	   int counter = 0;

	   for (unsigned int i = 0; i < checks.size(); i++)
	   {
		   int check = 0;

		   for (unsigned int j = 0; j < sentence.size(); j++)
		   {
			   if (checks[i] == sentence[j])
			   {
				   counter++;
				   check = j;
			   }
		   }

		   if ( counter != 0 )
		   {
			   outClientFile << counter <<"->"<< sentence[check] + " ";
		   }

		   counter = 0;
	   }

return 0;

}

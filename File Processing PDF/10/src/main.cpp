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
	   ifstream inClientFile( "read.txt", ios::in );
	   ifstream inClientFile2( "read2.txt", ios::in );
	   ofstream outClientFile( "write.txt", ios::out );

	   if ( !inClientFile && !outClientFile)
	   {
	      cerr << "File could not be opened" << endl;
	      exit( 1 );
	   }

	      string word1;
	      vector <string> sentence;
	      vector <string> checks;

	   while ( inClientFile >> word1)
	   {
        sentence.push_back(word1);
	   }

	   while ( inClientFile2 >> word1)
	   {
        checks.push_back(word1);
	   }

	   for (unsigned int i = 0; i < checks.size(); i++)
	   {
		   for (unsigned int j = 0; j < sentence.size(); j++)
		   {
			   if (checks[i] == sentence[j])
			   {
				   sentence.erase(sentence.begin() + j);
			   }
		   }
	   }
           for (unsigned int i = 0; i < sentence.size(); i++)
           {
        	   outClientFile << sentence[i] + " ";
           }

return 0;

}

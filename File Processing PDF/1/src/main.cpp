#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

void outputLine( string , int ,  string );

int main()
{
	   ifstream inClientFile( "read.txt", ios::in );
	   ofstream outClientFile( "write.txt", ios::out);

	   if ( !inClientFile && !outClientFile)
	   {
	      cerr << "File could not be opened" << endl;
	      exit( 1 );
	   }

		   string word1;
		   int int1;
		   string word2;
		   int input = 1;

		   while ( inClientFile >> word1 >> int1 >> word2 )
           outputLine( word1, int1, word2 );

           inClientFile.clear();
           inClientFile.seekg(0);

		   while ( inClientFile >> word1 >> int1 >> word2 )
		   {
			   outClientFile << left << input << " " << word1 << " " << int1 << " " << right << word2 << endl;
			   input++;
		   }


return 0;
}

void outputLine( string word1, int int1, string word2 )
{
   cout << left << word1 << " " << int1 << " " << right << word2 << endl;
}


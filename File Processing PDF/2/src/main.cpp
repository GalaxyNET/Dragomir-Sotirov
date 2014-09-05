#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void outputLine( string , string );

int main()
{
	   ifstream inClientFile( "read.txt", ios::in );
	   ofstream outClientFile( "write.txt", ios::out );

	   if ( !inClientFile && !outClientFile)
	   {
	      cerr << "File could not be opened" << endl;
	      exit( 1 );
	   }

		   string word1;
		   string word2;

		   cout<<"Words in File read.txt : "<<endl;
		   while ( inClientFile >> word1 >> word2 )
           outputLine( word1, word2 );

           inClientFile.clear();
           inClientFile.seekg(0);
           cout<<endl;

           vector<string> sortedNames;

                   while ( inClientFile >> word1 )
           		   {
           			   sortedNames.push_back(word1);
           		   }

                   sort(sortedNames.begin(), sortedNames.end());

           cout << "Sorted names in Vector is: " << endl;

                   for (unsigned int i = 0; i < sortedNames.size(); i++)
                   {
                	   cout << sortedNames[i]<<endl;
                   }

                   for (unsigned int i = 0; i < sortedNames.size(); i+=2)
                   {
                         outClientFile << left << sortedNames[i] << " " << right << sortedNames[i+1] << endl;
                   }




return 0;
}

void outputLine( string word1, string word2 )
{
   cout << left << word1 << " " << right << word2 << endl;
}



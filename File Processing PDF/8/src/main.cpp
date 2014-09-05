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
	   ofstream outClientFile( "write.txt", ios::out );

	   if ( !inClientFile && !outClientFile)
	   {
	      cerr << "File could not be opened" << endl;
	      exit( 1 );
	   }

	    string word1;
        string sentence;

	   while ( inClientFile >> word1)
	   {
        sentence += word1 + " ";
	   }
	               size_t position = 0;
	   			   string search = "test";
	   			   size_t space = 0;

		   while ((position = sentence.find(search, position)) != std::string::npos)
		       {
			        space = sentence.find(" ", position) - position;
		            sentence.replace(position, space, "");
		            position = position + 1;
		       }

               outClientFile << sentence;

return 0;
}

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

//	    string start = "start";
//	    string finish = "finish";

//		   while ( inClientFile >> word1 )
//		   {
//
//			   if (word1 == start)
//			   {
//				   word1 == finish;
//			   }
//
//			   outClientFile << word1 << " ";
//		   }

	   while ( inClientFile >> word1)
	   {
        sentence += word1 + " ";
	   }
	               size_t position = 0;
	   			   string search = "start";

		   while ((position = sentence.find(search, position)) != std::string::npos)
		       {
		            sentence.replace(position, search.length(), "finish");
		            position = position + 1;
		       }

               outClientFile << sentence;

return 0;
}

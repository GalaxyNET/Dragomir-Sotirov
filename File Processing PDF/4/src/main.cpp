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

           int number;
           int array[4][4];
           int i = 0, j = 0;

                   while ( inClientFile >> number )
           		   {
                	   if (j == 4)
                	   {
                		   i++;
                		   j = 0;
                	   }

           			 array[i][j] = number;
           			 j++;
           		   }

                   int biggersum = 0;

                   for (int i = 0; i < 3; i++)
                   {
                       for (int j = 0; j < 3; j++)
                       {
                    	   if (array[i][j] + array[i][j+1] + array[i+1][j] + array[i+1][j+1] > biggersum)
                    	   {
                    		   biggersum = array[i][j] + array[i][j+1] + array[i+1][j] + array[i+1][j+1];
                    	   }
                       }
                   }

                     cout << biggersum;

                  outClientFile << biggersum;




return 0;
}

void outputLine( string word1, string word2 )
{
   cout << left << word1 << " " << right << word2 << endl;
}



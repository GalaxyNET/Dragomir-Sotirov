#include <iostream> 
#include <cstdlib>

using namespace std;

const int SIZE = 6;

int main()
{
   char stringValue[ SIZE ];
   int sum = 0;
   
   for ( int i = 1; i <= 4; ++i )
   {
      cout << "Enter an integer string: ";
      cin >> stringValue;
      sum += atoi( stringValue );
   }
   
   cout << "The total of the values is " << sum << endl;
}

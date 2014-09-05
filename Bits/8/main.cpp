#include <iostream> 
#include <iomanip> 
#include <cstdlib>
using namespace std;

const int SIZE = 15;

int main()
{
   char stringValue[ SIZE ];
   double sum = 0.0;
   
   for ( int i = 1; i <= 4; i++ )
   {
      cout << "Enter a floating-point value: ";
      cin >> stringValue;
      sum += atof( stringValue );
   }

   cout << fixed << "\nThe total of the values is " << setprecision( 3 )  << sum << endl;
}

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;


int main()
{
	list<int> values;
	int n,m;

	cout << "Enter N: ";
	cin >> n;
	cout << "Enter M: ";
	cin >> m;

	string sequence = "";

	stringstream ss;
	ss << n;
	sequence.append(ss.str() + " ");

	while ( n != m )
	{
      //even N even M +2
      if (n % 2 == 0 && m % 2 == 0 && n != m/2)
      {
    	  stringstream ss;
    	  ss << "";
    	  n = n+2;
    	  ss << n;
    	  sequence.append(ss.str() + " ");
      }

       if (n == m)
       {
     	  break;
       }

      //odd N odd M +1
      if (n % 2 == 1 && m % 2 == 1 && n != m/2)
      {
    	  stringstream ss;
    	  ss << "";
    	  n = n+1;
    	  ss << n;
    	  sequence.append(ss.str() + " ");
      }

      if (n == m)
      {
    	  break;
      }

      //even N odd M +1
      if (n % 2 == 0 && m % 2 == 1 && n != m/2)
      {
    	  stringstream ss;
    	  ss << "";
    	  n = n+1;
    	  ss << n;
    	  sequence.append(ss.str() + " ");
      }

      if (n == m)
      {
    	  break;
      }

      //odd N even M +1
      if (n % 2 == 1 && m % 2 == 0 && n != m/2)
      {
    	  stringstream ss;
    	  ss << "";
    	  n = n+1;
    	  ss << n;
    	  sequence.append(ss.str() + " ");
      }

      if (n == m)
      {
    	  break;
      }

      //even N even M N==M/2 *2
      if (n % 2 == 0 && m % 2 == 0 && n == m/2)
      {
    	  stringstream ss;
    	  ss << "";
    	  n = n*2;
    	  ss << n;
    	  sequence.append(ss.str() + " ");
      }

      if (n == m)
      {
    	  break;
      }
	}
	cout <<"The shortest sequence is: " << sequence <<endl;

	return 0;
}

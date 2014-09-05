#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
 int arr[] = {1, 1, 2, 1, 2, 3, 4};

 int sizeArr = sizeof(arr) / sizeof *arr;

 list<int> conditionals;

 conditionals.insert(conditionals.begin(), arr, arr + sizeArr);

 conditionals.sort();
 conditionals.unique();

 list<int>::const_iterator citr;
 int counter = 0;

 for(citr = conditionals.begin(); citr != conditionals.end(); citr++)
 {
  for(int j = 0; j < sizeArr; j++)
  {
   if(*citr == arr[j])
   {
    counter++;
   }
  }
  cout<<*citr<<" -> "<<counter<<endl;
  counter = 0;
 }
 return 0;
}

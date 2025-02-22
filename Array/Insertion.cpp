/* Topic-2: Array in DSA and Various operation---*/

/* Algorithm of Array:
1. Start
2.Create Array
3.Initialize a variable i as 0
4.Enter value of kth position
5.Increment value of i by 1
6.Repeat 4 and 5 unit the end of Array
7.End
*/


#include <iostream>
using namespace std;
int main()
{
  int age[5];
  int i=0;
  int size=sizeof(age)/sizeof(age[0]);
  cout<<"Insert element to Array:";
  for(int i=0;i<size;i++)
  {
      cin>>age[i];
  }
  
  //Display  Content of Array:
  cout<<"content Of Array:";
   for( i=0;i<size;i++)
  {
      cout<<age[i]<<" ";
  }
   
   return 0;
}
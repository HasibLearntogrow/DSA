
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string first,second,third;
  cin>>first;
  cin>>second;
  cin>>third;
  string mid=first+second;
  sort(mid.begin(),mid.end());
  sort(third.begin(),third.end());
  if(mid==third){
      cout<<"YES";
  }else{
      cout<<"NO";
  }
   
   return 0;
}
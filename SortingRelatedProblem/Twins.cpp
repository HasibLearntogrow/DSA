
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  double total=0;
  vector<int>v(n);
  for(int i=0;i<n;i++){
      cin>>v[i];
  }
  for(int i=0;i<n;i++){
      total+=v[i];
  }
  int count=0;
  double sum=0;
   sort(v.rbegin(),v.rend());
   for(int i=0;i<n;i++){
       sum+=v[i];
       count++;
       if(sum>total/2){
          break;
           
       }
   }
   
   cout<<count;
   
   return 0;
}
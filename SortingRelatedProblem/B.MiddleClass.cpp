
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--){
      double sum=0;
      int c=0;
      int n,x;
      cin>>n>>x;
      vector<int>v(n);
      for(int i=0;i<n;i++){
          cin>>v[i];
      }
      
      sort(v.begin(),v.end());
      int j=1;
      for(int i=n-1;i>=0;--i){
         sum+=v[i];
         if(sum/j>=x){
             c++;
         }
         j++;
          
          
      }
      
      cout<<c<<endl;
      
      
      
      
  }
   
   return 0;
}
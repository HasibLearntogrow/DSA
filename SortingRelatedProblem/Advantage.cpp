
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t; //Number of test case
  cin>>t;
  while(t--){
     int n; //size of Array
     cin>>n;
     vector<int>v(n);
     
     
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     vector<int>v2=v;//copy to new Arry
      sort(v2.begin(),v2.end());
      int max=v2[v2.size()-1]; //Find max value  
      
      for(int i=0;i<n;i++){
          if(v[i] !=max){
              cout<<v[i]-max<<" "; //s1-max
          }else{
              cout<<v[i]-v2[v2.size()-2]<<" ";
          }
      }
      cout<<endl;
   
  } 
   
   return 0;
}
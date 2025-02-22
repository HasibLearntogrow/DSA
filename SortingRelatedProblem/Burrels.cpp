
#include <bits/stdc++.h>

using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--){
     int n,k;
     cin>>n>>k;
     vector<int>v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     sort(v.rbegin(),v.rend());
     int max=v[0];
     for(int j=1;j<=k;j++){
         max+=v[j];
     }
     cout<<max-0<<endl;
 }
   
   return 0;
}
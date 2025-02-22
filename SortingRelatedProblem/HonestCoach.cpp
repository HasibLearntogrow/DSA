
#include <bits/stdc++.h>

using namespace std;

int main()
{
 

     int n;
     cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     sort(v.begin(),v.end());
     int mid=n/2;
     long long a=0;
     long long b=0;
     for(int i=0;i<mid;i++){
         a+=v[i];
     }
     
      for(int j=mid;j<n;j++){
         b+=v[j];
     }
    
     
     cout<<a*a+b*b<<endl;
     
   return 0;
}
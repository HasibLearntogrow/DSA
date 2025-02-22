#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
    cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   sort(v.begin(),v.end());
   int x = v.size();
   for(int i=1;i<n;i++){
       if(v[i]-v[i-1]<=1){
           x--;
       }
   }
   if(x==1){
       cout<<"YES"<<endl;
   }else{
       cout<<"NO"<<endl;
   }
    }
    
   return 0;
}
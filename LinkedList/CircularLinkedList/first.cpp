
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--){
       string x;
       string res=" ";
       cin>>x;
       int len=x.size();
       if(x[len-2]=='u' && x[len-1]=='s'){
           for(int i=0;i<len-2;i++){
               res+=x[i];
           }
       }
       cout<<res+'i'<<endl;
       
       
   }
   
   return 0;
}
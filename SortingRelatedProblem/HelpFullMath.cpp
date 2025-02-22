
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x;
    cin>>x;
   vector<char>v ;
   for(char c: x){
       if(c !='+'){
           v.push_back(c);
       }
   }
   sort(v.begin(),v.end());
   for(int i=0;i<v.size()-1;i++){
       cout<<v[i]<<'+';
   }
   cout<<v[v.size()-1];
   return 0;
}
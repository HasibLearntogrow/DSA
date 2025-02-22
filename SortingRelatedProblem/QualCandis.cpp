
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t; //number of text case
  cin>>t;
  while(t--){
     int n; //number of friends
     cin>>n;
     vector<int>v(n);
     
     int eat=0; // I have to eat for create balence
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
      sort(v.begin(),v.end());
    int max=v[0]; //Minumun candis to create balnce
     for(int i=1;i<v.size();i++){
        int dif=v[i]-max;
        eat+=dif;
     }
     cout<<eat<<endl;
  }
   
   return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
   vector<int>v(3);
   for(int i=0;i<3;i++){
       cin>>v[i];
   }
   sort(v.rbegin(),v.rend());
   int first=v[0]-v[1];
   int second=v[1]-v[2];
   cout<< first+second<<" ";
   
   return 0;
}
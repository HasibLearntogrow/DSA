
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t; //Number of test case
  cin>>t;
  while(t--){
  int n;
  cin>>n;// Size of Array
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
 
  map<int,int>mp; //Craete mp
  for( int x: arr){
   mp[x]++; //count frequency
  }
         bool found = false;
        for (const auto& m : mp) { //Pair by pair
            if (m.second >= 3) {
                cout << m.first << " ";
                found = true;
                break;
            }
            
        }

        if (!found) {
            cout << "-1";
        }
        
        cout << endl; 
    
   
  } 
   
   return 0;
}
#include<bits/stdc++.h>
using namespace std;
string RemoveDuplictae(string s){
   sort(s.rbegin(),s.rend());
   stack<char>st;
   for(char c:s){
    if(st.empty() || st.top() !=c){
        st.push(c);
    }
   }
  string res="";
  string Curtop;
  while (!st.empty())
  {
    Curtop=st.top();
    st.pop();
   res +=Curtop; 
  }
  return res; 
}
int main(){
    cout<<"Enter any string:";
    string st;
    cin>>st;
 string ans=RemoveDuplictae(st);
 cout<<ans;

}
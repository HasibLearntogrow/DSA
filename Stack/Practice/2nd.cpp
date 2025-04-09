#include<bits/stdc++.h>
using namespace std;
void remove(stack<int>&st){
    bool re=false;
  while (!st.empty())
  {
    int current=st.top();
    st.pop();
    int next=st.top();
    while (!st.empty())
    {
        cout<<current<<" ";
       if(current !=next){
        st.pop();
       } else{
        st.push(next);
       }
       
   
    }
   
    

    
    
    
  }
  



}
int main(){
stack<int>st;
st.push(10);
st.push(2);
st.push(7);
st.push(2);
st.push(5);
remove(st);



    return 0;
}
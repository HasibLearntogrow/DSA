#include<bits/stdc++.h>
using namespace std;
void remove(stack<int>&st){
  while (!st.empty())
  {
    bool re=false;
    int current=st.top();
    st.pop();
    int next;
    while (!st.empty())
    {
         next=st.top();
       if(current !=next){
      re= true;
        st.pop();
       } 
    }
    
    if (re==true)
    {
        cout<<current<<" ";
        
    }else{
        st.push(next);
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
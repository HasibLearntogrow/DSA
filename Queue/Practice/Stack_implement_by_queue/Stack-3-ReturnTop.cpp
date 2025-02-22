#include<bits/stdc++.h>
using namespace std;
//Create class:
class Stack{
   queue<int>q;
   public:

   //Data push in stack;
   void push(int data){
    q.push(data);
    for(int i=0;i<q.size()-1;i++){
        q.push(q.front());
        q.pop();
    }
   }
   //Return top value:
   int top(){
    if(!q.empty()){
        return q.front();
    }else{
        return -1;
    }
   }
};
int main(){
    Stack st;
   st.push(10);
    cout<<"Top:"<<st.top()<<endl;
    st.push(11);
    cout<<"Top:"<<st.top()<<endl;
    return 0;
}
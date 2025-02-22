#include<bits/stdc++.h>
using namespace std;
//Create class:
class Stack{
   queue<int>q;
   public:

   //Data push in stack;
   void push(int data){
    q.push(data);
    for(int i=0;i<q.size();i++){
        q.push(q.front());
        q.pop();
    }
   }
};
int main(){
    Stack st;
    st.push(10);
    return 0;
}
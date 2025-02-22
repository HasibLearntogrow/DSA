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
   //pop element:
   void pop(){
    if(!q.empty()){
        q.pop();
    }else{
        cout<<"Already empty!"<<endl;
    }
   }
   //check size:
   int size(){
    if(!q.empty()){
        return q.size();
    }else{
     return -1;
    }
   }
  
   //Check Empty or not:
   bool isEmpty(){
    if(q.empty()){
        return true;
    }else{
        return false;
    }
   }
   void print() {
    queue<int> temp = q; 
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}
};
int main(){
    Stack st;
   st.push(10);
    cout<<"Top:"<<st.top()<<endl;
    st.push(11);
    cout<<"Top:"<<st.top()<<endl;
    st.pop();
    cout<<"Top:"<<st.top()<<endl;
    cout<<"size:"<<st.size()<<endl;
    cout<<"IsEmpty:"<<st.isEmpty()<<endl;
    st.push(15);
    st.push(20);
    st.print();
    return 0;
}
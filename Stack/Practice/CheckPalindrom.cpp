#include<bits/stdc++.h>
using namespace std;
int main(){
    string expression;
    cout << "Enter any expression:";
    cin >> expression;
    bool flag = false;
    stack<char> st;
    queue<char>q;
    for(int i=0;i<expression.size();i++){
        int ch=expression[i];
        st.push(ch);
        q.push(ch);
    }
    while (!st.empty() && !q.empty())
    {
         char c1=st.top();
         st.pop();
         char c2=q.front();
         q.pop();
         if(c1==c2){
            flag=true;
         }else{
            flag=false;
            break;
         }
    }
    if(flag==true){
    cout<<expression<<"->This is palindrome"<<endl;
    }else{
        cout<<expression<<"->This is not palindrome"<<endl;
    }

    return 0;
}
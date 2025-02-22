#include<bits/stdc++.h>
using namespace std;  
int ExpressionValue(string exp){
stack<int>st;
for(char ch: exp){
    if(isdigit(ch)){
        int x=ch-'0';
        st.push(x);
    }else{
        if(st.size()<2){
            cout<<"Invalid Expression";
            return -1;
        }

        int curr=st.top();
        st.pop();
        int next=st.top();
        st.pop();
        if(ch=='+'){
            st.push(curr+next);
        }else if(ch=='-'){
            st.push(curr-next);
        } else if(ch=='*'){
            st.push(curr*next);
        }else if(ch=='/'){
            if(next==0){
                cout<<"Mathmatical error";
                return -1;
            }
            st.push(curr/next);
        }else{
            cout<<"Invalid expression";
        }

    }
  
}
return st.top();
}
int main(){
    cout<<"Enter any expression:";
    string exp;
    cin>>exp;
    int ans=ExpressionValue(exp);
    cout<<ans;

    return 0;
}
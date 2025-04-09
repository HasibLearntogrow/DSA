#include<bits/stdc++.h>
using namespace std;
int main(){

stack<char>st;
string text="hello world";
string ans="";
for(int i=0;i<text.size();i++){
    char ch=text[i];
    if (ch=='e' || ch=='o' || ch=='i')
    {
        st.push(ch);
    }  
}


for (int  i = 0; i < text.size(); i++)
{
    char x=text[i];
    
    if(!st.empty() && (x=='e' || x=='o' || x=='i')){

    ans.push_back(st.top());
       
            st.pop();   
    }else{
        ans.push_back(x);
    }
}
cout<<ans;


    return 0;
}
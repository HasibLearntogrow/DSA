#include<bits/stdc++.h>
using namespace std;

int main(){
string text="abacd";
for (int i = 0; i <text.size(); i++)
{
    char t=text[i];
    for (int j = 1; j< text.size(); j++)
    {
        char y=text[j];
        if (t==y)
        {
           if(t=='a' && y=='a' ) {
            text[i]='x';
            text[j]='x';
           }
           

        }
        
        
    }
    
    
}



cout<<text;

    return 0;
}
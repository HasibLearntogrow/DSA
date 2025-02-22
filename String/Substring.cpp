#include <iostream>
#include <string>
using namespace std;

string Substring(string text,int position,int len) {
    string res = "";
    
    for (int i = position-1; i <position-1+len; i++) {
        res += text[i];
    }
    
    return res;
}

int main() {
   string text;
   cin >> text;
   int position,len;
   cin>>position>>len;
   
   string res = Substring(text,position,len);
   cout << res;

   return 0;
}

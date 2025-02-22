#include <iostream>
#include <string>
using namespace std;

string strMerge(string text1,string text2) {
    string res = "";
    
    for (int i = 0; i <text1.size(); i++) {
        res += text1[i];
    }
    for (int j =0; j < text2.size(); j++) {
        res += text2[j];
    }
    return res;
}

int main() {
   string text1,text2;
   cin >> text1>>text2;
   
   string res = strMerge(text1,text2);
   cout << res;

   return 0;
}

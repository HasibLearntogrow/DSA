#include <iostream>
#include <string>
using namespace std;

string strDelete(string text, int initial, int length) {
    string res = "";
    initial -= 1;
    for (int i = 0; i < initial; i++) {
        res += text[i];
    }
    for (int j = initial + length; j < text.size(); j++) {
        res += text[j];
    }
    return res;
}

int main() {
   string text;
   int position, len;
   cin >> text;
   cin >> position >> len;
   string res = strDelete(text, position, len);
   cout << res;

   return 0;
}

#include <iostream>
#include <string>
using namespace std;

int length(string text) {
    int i = 0;
    while (text[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
   string text;
   cin>>text;
   int size = length(text);
   cout << size;

   return 0;
}

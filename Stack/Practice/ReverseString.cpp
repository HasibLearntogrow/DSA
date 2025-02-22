#include <bits/stdc++.h>
using namespace std;
int main()
{
  string x;
  cout << "Enter any string:";
  cin >> x;
  stack<char> s;
  for (char c : x)
  {
    s.push(c);
  }
  string rev = " ";
  while (!s.empty())
  {
    char ch = s.top();
    rev += ch;
    s.pop();
  }

  cout << "Reverse string :" << " " << rev << endl;

  return 0;
}
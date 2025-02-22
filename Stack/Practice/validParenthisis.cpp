#include <bits/stdc++.h>
using namespace std;
int main()
{
    string expression;
    cout << "Enter any expression:";
    cin >> expression;
    bool flag = false;
    stack<char> st;
    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            while (!st.empty())
            {
                int x = st.top();
                if (ch == ')' && x == '(' || ch == '}' && x == '{' || ch == ']' && x == '[')
                {
                    flag = true;
                    st.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag == true)
    {

        cout << expression << " This is valid expression" << endl;
    }
    else
    {
        cout << expression << " This is invalid expression" << endl;
    }

    return 0;
}
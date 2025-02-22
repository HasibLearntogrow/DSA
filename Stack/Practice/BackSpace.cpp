#include <bits/stdc++.h>
using namespace std;

bool backspace(string s, string t)
{
    stack<char> st, st2;

    for (char c : s)
    {
        if (c != '#')
        {
            st.push(c);
        }
        else if (!st.empty())
        {
            st.pop();
        }
    }

    for (char ch : t)
    {
        if (ch != '#')
        {
            st2.push(ch);
        }
        else if (!st2.empty())
        {
            st2.pop();
        }
    }

    string first, second;
    while (!st.empty())
    {
        first += st.top();
        st.pop();
    }
    while (!st2.empty())
    {
        second += st2.top();
        st2.pop();
    }
    if (first == second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << "Enter two string:";
    string s, t;
    cin >> s >> t;

    if (backspace(s, t))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}

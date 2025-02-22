#include <bits/stdc++.h>
using namespace std;

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return -1;
    }
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPrefix(string s) {
    //Change ---1:
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    stack<char> st;
    string response = "";

    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            response.push_back(s[i]);

            //Change -2: mamualy reverse-backet
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                response.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            while (!st.empty() && 
                   ((precedence(st.top()) > precedence(s[i])) || 
                    (precedence(st.top()) == precedence(s[i]) && !isRightAssociative(s[i]))) && 
                   (st.top() != '(')) {
                response.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        response.push_back(st.top());
        st.pop();
    }
 //chanege-3: again reverse;
    reverse(response.begin(), response.end());
    return response;
}

int main() {
    cout << "Enter any infix expression: ";
    string exp;
    cin >> exp;
    string out = infixToPrefix(exp);
    cout << "Prefix for: " << exp << " -----> " << out << endl;
    return 0;
}

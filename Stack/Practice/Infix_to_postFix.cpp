#include <bits/stdc++.h>
using namespace std;

//Check precedemce:
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
//Operational function:
string infixtopostfix(string s) {
    stack<char> st;
    string response = "";
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            response.push_back(s[i]);
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {   //----->Rules three
                response.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) {   //----->last remain element in stack:
                st.pop();
            }
        } else {
            while (!st.empty() && //------>Rules 2 and 1:
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
    return response;
}

int main() {
    cout << "Enter any infix expression: ";
    string exp;
    cin >> exp;
    string out = infixtopostfix(exp);
    cout << "Postfix for: " << exp << " -----> " << out << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> tep) {
    stack<int> st;
    
    while (!tep.empty()) {
        st.push(tep.front());
        tep.pop();
    }

    while (!st.empty()) {
        tep.push(st.top());
        st.pop();
    }

    return tep;
}

int main() {
    queue<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Original Queue: ";
    queue<int> temp = st; 
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    queue<int> res = reverseQueue(st);

    cout << "Reversed Queue: ";
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;

    return 0;
}

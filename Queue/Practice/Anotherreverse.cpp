#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> tep) {
    queue<int> q;

    while (!tep.empty()) {
        q.push(tep.front());
        tep.pop();
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    return q;
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

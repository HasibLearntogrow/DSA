#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> st1, st2;

    void Assist() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }

public:
    void enqueue(int data) {
        st1.push(data);
    }

    int front() {
        Assist();
        if (!st2.empty()) {
            return st2.top();
        }
        return -1;
    }

    void dequeue() {
        Assist();
        if (!st2.empty()) {
            st2.pop();
        }
    }

    void print() {
        Assist();
        stack<int> temp = st2;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    q.print();

    q.dequeue();
    cout << "After dequeuing, front element: " << q.front() << endl;
    
    q.print();

    return 0;
}

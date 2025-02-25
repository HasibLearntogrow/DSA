#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;
    queue<int> q;

    while (T--) {
        int query;
        cin >> query;

        if (query == 1) {
            int n;
            cin >> n;
            q.push(n);
        } else if (query == 2) {
            if (!q.empty()) {
                q.pop();
            }
        } else if (query == 3) {
            if (q.empty()) {
                cout << "Empty!\n";
            } else {
                cout << q.front() << '\n';
            }
        }
    }

    return 0;
}

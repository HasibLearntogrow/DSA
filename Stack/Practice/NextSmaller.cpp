#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> NextSmaller(vector<int>& v) {
    int n = v.size();
    vector<int> nextS(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
            nextS[st.top()] = v[i]; 
            st.pop();
        }
        st.push(i);
    }
    return nextS;
}

int main() {
    vector<int> arr = {4, 8, 2, 1, 6, 10, 5};

    cout << "This is the original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> small = NextSmaller(arr);

    cout << "This is the next smaller array: ";
    for (int num : small) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

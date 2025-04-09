#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> preSmaller(vector<int>& v) {
    int n = v.size();
    vector<int> preS(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
         
            st.pop();
        }
        if(!st.empty()){
        preS[i]=st.top();
        }
        st.push(i);
    }
    return preS;
}

int main() {
    vector<int> arr = {4, 8, 2, 1, 6, 10, 5};

    cout << "This is the original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> small = preSmaller(arr);

    cout << "This is the next smaller array: ";
    for (int num : small) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> NextSmaller(vector<int>& v) {
    int n = v.size();
    vector<int> nextS(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
            nextS[st.top()] = i; 
            st.pop();
        }
        st.push(i);
    }
    return nextS;
}

vector<int> preSmaller(vector<int>& v) {
    int n = v.size();
    vector<int> preS(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
            st.pop();
        }
        if (!st.empty()) {
            preS[i] = st.top();
        }
        st.push(i);
    }
    return preS;
}

int getMaxArea(vector<int>& arr) {
    vector<int> prevS = preSmaller(arr);
    vector<int> nextS = NextSmaller(arr);
    
    int maxArea = 0;

    for (int i = 0; i < arr.size(); ++i) {
        int width = nextS[i] - prevS[i] - 1;
        int area = arr[i] * width;          
        maxArea = max(maxArea, area);        
    }
    
    return maxArea;
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr) << endl;
    return 0;
}

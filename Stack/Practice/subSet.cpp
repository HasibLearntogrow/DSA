#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v = {{}};
        for (int num : nums) {
            int n = v.size();
            for (int i = 0; i < n; i++) {
                v.push_back(v[i]);  // Copy existing subset
                v.back().push_back(num);  // Add current number
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> result = sol.subsets(nums);

    // Print subsets
    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;

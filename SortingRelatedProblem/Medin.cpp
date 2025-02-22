#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums;
    int num;
    
    while (cin >> num) {
        nums.push_back(num);
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n % 2 == 1) {
            cout << nums[n / 2] << endl;
        } else {
            cout << (nums[n / 2] + nums[n / 2 - 1]) / 2 << endl;
        }
    }

    return 0;
}

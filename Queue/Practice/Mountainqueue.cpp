#include <iostream>
#include <vector>
#include <stack>

std::vector<int> findNextHigherPeaks(const std::vector<int>& heights) {
    int n = heights.size();
    std::vector<int> result(n, -1);
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[i] > heights[s.top()]) {
            result[s.top()] = heights[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> heights(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }

    std::vector<int> nextHigherPeaks = findNextHigherPeaks(heights);

    for (int height : nextHigherPeaks) {
        std::cout << height << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int josephus(int n, int k) {
    vector<int> people;
    for (int i = 1; i <= n; i++) people.push_back(i);
    int index = 0;
    while (people.size() > 1) {
        index = (index + k - 1) % people.size();
        people.erase(people.begin() + index);
    }
    return people[0];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
    return 0;
}

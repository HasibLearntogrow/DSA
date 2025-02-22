#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++) { 
        cin >> v2[i];
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = v[i] + v2[j];
            int count1 = count(v.begin(), v.end(), sum);
            int count2 = count(v2.begin(), v2.end(), sum);
            if (count1 == 0 && count2 == 0) {
                cout << v[i] << " " << v2[j];
                return 0;
            }
        }
    }
    return 0;
}

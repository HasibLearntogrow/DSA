#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    double dis = 0;
    for (int i = 1; i < n; i++) {
        dis = max(dis, double(v[i] - v[i - 1]));
    }
    dis /= 2;
    
    cout << fixed << setprecision(10) << max({double(v[0]), dis, double(l - v[n - 1])}) << endl;
    
    return 0;
}

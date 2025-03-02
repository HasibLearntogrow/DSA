#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w, int dir) {
    if (dir == 1) {
        adj[u].push_back({v, w});
        return;
    }
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void Display(vector<vector<pair<int, int>>>& adj, int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto ele : adj[i]) {
            cout << "(" << ele.first << "  " << ele.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, w, dir, u, v;
    cout << "Enter number of vertices:";
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter number of edges:";
    cin >> m;
    cout << "Enter vertices and weight (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(adj, u, v, w, 0);
    }
    cout << "Graph representation:" << endl;
    Display(adj, n);
    return 0;
}

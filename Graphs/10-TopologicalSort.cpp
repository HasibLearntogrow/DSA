#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &adj, int u, int v, int dir) {
    adj[u].push_back(v);
    if (dir == 0) {
        adj[v].push_back(u);
    }
}

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visit, stack<int> &st) {
    visit[v] = true;
    for (int i : adj[v]) {
        if (!visit[i]) {
            dfs(i, adj, visit, st);
        }
    }
    st.push(v);
}

vector<int> topological(vector<vector<int>> &adj, int n) {
    vector<bool> visit(n + 1, false);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i, adj, visit, st);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    int n, u, v, m, dir;
    
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n + 1);

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Notation for directed graph = 1 or undirected graph = 0: ";
    cin >> dir;

    cout << "Now enter starting and ending vertex:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        addedge(adj, u, v, dir);
    }

    vector<int> ans = topological(adj, n);

    for (int i = 0; i < ans.size()-1; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

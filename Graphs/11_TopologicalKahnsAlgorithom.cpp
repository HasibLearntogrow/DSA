#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &adj, int u, int v, int dir, vector<int> &indegree) { 
    if (dir == 1) {
        adj[u].push_back(v); 
        indegree[v]++;
    } else { 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}   

vector<int> topological(vector<vector<int>> &adj, vector<int> &indegree) {
    int v = adj.size();
    queue<int> q;
    
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> ans;
    int count = 0; 

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        count++;

        for (auto ele : adj[node]) {
            indegree[ele]--;
            if (indegree[ele] == 0) {
                q.push(ele);
            }
        }
    }

    // Check for cycle
    if (count != v) {
        cout << "Graph contains a cycle!" << endl;
        return {};
    }
    
    return ans;
}

int main() {
    vector<vector<int>> adj;
    vector<int> indegree;

    int n, u, v, m, dir;
    cout << "Enter number of vertices: ";
    cin >> n;
    adj.resize(n+1); 
    indegree.resize(n+1, 0);

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Notation for directed graph = 1 or undirected graph = 0: ";
    cin >> dir;

    cout << "Now enter starting and ending vertex:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        addedge(adj, u, v, dir, indegree);
    }

    vector<int> topo = topological(adj, indegree);
    if (!topo.empty()) {
        cout << "Topological sort:" << endl;
        for (int i : topo) {
            cout << i<< " ";
        }
        cout << endl;
    }

    return 0;
}

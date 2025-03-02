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

void dijkstras(vector<vector<pair<int, int>>>& adj, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dis(adj.size(), INT_MAX);
    
    dis[start] = 0;
    q.push({0, start}); 

    while (!q.empty()) {
        int currDist = q.top().first;
        int node = q.top().second;
        q.pop();

        

        for (auto ele : adj[node]) {
            int ver = ele.first;
            int weight = ele.second;

            if (dis[ver] > currDist + weight) {
                dis[ver] = currDist + weight;
                q.push({dis[ver], ver});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < dis.size(); i++) {
        cout << "Node " << i << ": " << (dis[i] == INT_MAX ? -1 : dis[i]) << endl;
    }
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
    int n, m, w, start, u, v;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    
    cout << "Enter number of edges: ";
    cin >> m;
    
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        addEdge(adj, u, v, w, 1);
    }

    cout << "Graph representation:" << endl;
    Display(adj, n);
    
    cout << "Enter starting node: ";
    cin >> start;
    
    dijkstras(adj, start);

    return 0;
}

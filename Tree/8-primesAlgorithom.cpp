#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void primMST(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> parent(n, -1);  // MST
    vector<int> key(n, INT_MAX); // Store the minimum weight to add a vertex
    vector<bool> inMST(n, false); 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push({0, 0}); // Start from vertex 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (const auto& e : adj[u]) {
            int v = e.first;
            int weight = e.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree (MST) Edges with Weights:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=key[i];
    }
    cout<<"Minimum weight of spanning tree is:"<<sum<<endl;
}

int main() {
    vector<vector<pair<int, int>>> adj;
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    adj.resize(n);
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    primMST(n, adj);
    return 0;
}

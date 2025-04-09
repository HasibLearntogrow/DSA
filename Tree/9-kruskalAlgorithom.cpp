#include <bits/stdc++.h>
using namespace std;

// Step-2: Make Set
void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Step-3: Find Parent with Path Compression
int findparent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]); // Path compression
}

// Step-4: Union by Rank
void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    int parentU = findparent(parent, u);
    int parentV = findparent(parent, v);

    if (parentU != parentV) {
        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
}

// Step-1: Kruskal’s Algorithm
void Minimumspanning(vector<tuple<int, int, int>> &edge, int n) {
    vector<int> parent(n + 1);
    vector<int> rank(n + 1);
    makeset(parent, rank, n);
    int mst_weight = 0;
    vector<tuple<int, int, int>> mst;
    sort(edge.begin(), edge.end());
    for (auto &[w, u, v] : edge) {
        int parentU = findparent(parent, u);
        int parentV = findparent(parent, v);

        if (parentU != parentV) {
            mst_weight += w;
            unionset(u, v, parent, rank);
            mst.push_back({w, u, v});
        }
    }

    // Output MST
    cout << "Minimum Spanning Tree:\n";
    cout << "Weight -> U -> V\n";
    for (auto &[w, u, v] : mst) {
        cout << w << " -> " << u << " -> " << v << endl;
    }
    cout << "Total Weight of Minimum Spanning Tree: " << mst_weight << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<tuple<int, int, int>> edge;
    cout << "Enter weight -> U -> V:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> w >> u >> v;
        edge.push_back({w, u, v});
    }

    Minimumspanning(edge, n);
    return 0;
}

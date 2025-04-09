#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Euler's Formula Check
    bool checkEulerPlanarity(int E) {
        return (E <= 3 * V - 6);
    }

    // Check for K5 (Complete Graph with 5 nodes)
    bool containsK5() {
        if (V < 5) return false;

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                for (int k = j + 1; k < V; k++) {
                    for (int l = k + 1; l < V; l++) {
                        for (int m = l + 1; m < V; m++) {
                            set<int> clique = {i, j, k, l, m};
                            bool isK5 = true;
                            for (int x : clique) {
                                for (int y : clique) {
                                    if (x != y && find(adj[x].begin(), adj[x].end(), y) == adj[x].end()) {
                                        isK5 = false;
                                        break;
                                    }
                                }
                                if (!isK5) break;
                            }
                            if (isK5) return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    // Check for K3,3 (Bipartite Graph fully connected)
    bool containsK33() {
        if (V < 6) return false;

        vector<int> nodes;
        for (int i = 0; i < V; i++)
            if (adj[i].size() >= 3) nodes.push_back(i);

        if (nodes.size() < 6) return false;

        for (int a = 0; a < nodes.size(); a++) {
            for (int b = a + 1; b < nodes.size(); b++) {
                for (int c = b + 1; c < nodes.size(); c++) {
                    for (int d = c + 1; d < nodes.size(); d++) {
                        for (int e = d + 1; e < nodes.size(); e++) {
                            for (int f = e + 1; f < nodes.size(); f++) {
                                set<int> partA = {nodes[a], nodes[b], nodes[c]};
                                set<int> partB = {nodes[d], nodes[e], nodes[f]};

                                bool isK33 = true;
                                for (int x : partA) {
                                    for (int y : partB) {
                                        if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end()) {
                                            isK33 = false;
                                            break;
                                        }
                                    }
                                    if (!isK33) break;
                                }
                                if (isK33) return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    // Main Planarity Check
    bool isPlanar(int E) {
        if (!checkEulerPlanarity(E)) return false;
        if (containsK5() || containsK33()) return false;
        return true;
    }
};

int main() {
    int n, m, u, v;
    cout << "Enter number of vertices & edges: ";
    cin >> n >> m;

    Graph g(n);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isPlanar(m)) {
        cout << "This is a planar graph!" << endl;
    } else {
        cout << "This is not a planar graph!" << endl;
    }

    return 0;
}

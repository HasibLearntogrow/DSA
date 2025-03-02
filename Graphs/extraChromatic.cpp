#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    vector<int> color;
    int numColors;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
        color.assign(V, -1);
        numColors = 1;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void Chromatic(int x) {
        for (int y : adj[x]) {
            if (color[y] == -1) {
                set<int> usedColors;
                for (int neighbor : adj[y]) {
                    if (color[neighbor] != -1)
                        usedColors.insert(color[neighbor]);
                }
                
                int minColor = 0;
                while (usedColors.find(minColor) != usedColors.end()) {
                    minColor++;
                }
                
                color[y] = minColor;
                if (minColor >= numColors) numColors++;
                
                Chromatic(y);
            }
        }
    }

    void findChromaticNumber() {
        color[0] = 0; // Assign first vertex color 0
        Chromatic(0);
        cout << "Chromatic number: " << numColors << endl;
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.findChromaticNumber();
    return 0;
}

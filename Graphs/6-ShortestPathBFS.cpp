#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &adj, int u, int v, int dir) {
    adj[u].push_back(v);
    if (dir == 0) {  
        adj[v].push_back(u);
    }
}

void Display(vector<vector<int>>& adj, int vertices) {
    for (int i = 0; i < vertices; i++) { 
        cout << i << " -> ";
        for (int ele : adj[i]) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

void shortbfs(vector<vector<int>>& adj, int start,int des) {
    queue<int> q;
    vector<bool> visit(adj.size(), false);

    vector<int>dis(adj.size(),-1);
    dis[start]=0;

    vector<int>parent(adj.size(),-1);
    
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        

        for (int x : adj[curr]) {
            if (!visit[x]) {
             dis[x]=dis[curr]+1;
             parent[x]=curr;

                visit[x] = true;
                q.push(x);
            }
        }
    }

    
  cout<<"Shortest distance->"<<start<<"--to--"<<des<<endl;


  vector<int>path;
  for ( int i =des; i !=-1; i=parent[i])
  {
    path.push_back(i);
  }
  reverse(path.begin(),path.end());


  for(int element: path){
    cout<<element<<" ";
  }

}

int main() {
    vector<vector<int>> adj;

    int n, u, v, m, dir;
    cout << "Enter number of vertices: ";
    cin >> n;
    adj.resize(n);  

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Notation for directed graph = 1 or undirected graph = 0: ";
    cin >> dir;

    cout << "Now enter starting and ending vertex:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        addedge(adj, u, v, dir);
    }

    cout << "Graph:" << endl;
    Display(adj, n);

    cout << "For BFS ...insert starting node: ";
    int st,des;
    cin >> st;
    cout << "For BFS ...insert destination  node: ";
    cin >> des;
    shortbfs(adj,st,des);

    return 0;
}

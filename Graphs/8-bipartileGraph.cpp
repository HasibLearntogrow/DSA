#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>> &adj,int u,int v){
  adj[u].push_back(v);
  adj[u].push_back(v);
}


bool isBipartile(vector<vector<int>> &adj){
int s=adj.size();
vector<int>color(s,-1);
queue<int>q;
for (int i = 0; i <s; i++)
{
    if(color[i]==-1){
        color[i]=0;
        q.push(i);
    }
    while (!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int curr: adj[top]){
            if (color[curr]==-1)
            {
                color[curr]=1-color[top];
                q.push(curr);
            }else if(color[top]==color[curr]){
                return false;
            }
            
        }
    }
    
}
return true;
}

int main(){
vector<vector<int>>adj;
int u,v,n,m;
cout<<"Enter number of vertex & edge:";
cin>>n>>m;
adj.resize(n);
for (int i = 0; i <m; i++)
{
    cin>>u>>v;
    addedge(adj,u,v);
}
if (isBipartile(adj))
{
    cout<<"This is bipartile graph!"<<endl;
}else{
    cout<<"This is not bipartile graph!"<<endl;
}



}
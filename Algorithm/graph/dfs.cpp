#include<iostream>
#include <bits/stdc++.h>

using namespace std;


//using dfs to get if 2 points on the graph are connectd or not
void dfs(vector<int> *adj, int node, vector<bool> &visited){
  visited[node] = true;
  for(int i=0;i<adj[node].size(); i++){
    int child = adj[node][i];
    if(!visited[child])
      dfs(adj,child,visited); 
  }
}

int main(){
  int v,e;
  cin >> v >> e;

  //adjancy list representation for undirected graph
  vector<int> adj[v+1];
  vector<bool> visited(v+1,false);
  for(int i=0;i<e;i++){
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int start , end;
  cin >> start >> end;
  dfs(adj,start,visited);
  cout << visited[end];
}
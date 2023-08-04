#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void bfs(int start,vector<int> *adj, vector<int> &depth){
  depth[start] = 0;
  queue<int> q;
  q.push(start);
  while(!q.empty()){
    int curNode = q.front();
    q.pop();
    for(int i=0;i<adj[curNode].size();i++){
      int child = adj[curNode][i];
      if(depth[child] == INT_MAX){
        q.push(child);
        depth[child] = depth[curNode]+1; 
      }
    }
  }
}


int main(){
    int v,e;
    cin >> v >> e;
    vector<int> adj[v+1];
    vector<int> depth(v+1,INT_MAX);
    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int start,end;
    cin >> start >> end;

    
    bfs(start,adj,depth);
    cout << depth[end];   
}
#include<iostream>
#include <bits/stdc++.h>


using namespace std;




void dfs(int node ,vector<int> *adj , vector<bool>& visited , vector<int>& toplogy){
    visited[node] = true;
    for(int i=0;i< adj[node].size();i++){
        int child = adj[node][i];  
        if(visited[child] != true)
            dfs(child,adj,visited,toplogy);
    }
    toplogy.push_back(node);
   
}




int main(){
    int v,e;
    cin >> v >> e;
    vector<int> adj[v+1];
    vector<bool> visited(v+1,false);
    for(int i=0;i<e;i++){
        int from,to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    vector<int> topologSort;

   
   
    

    for(int i=1;i<=v;i++){
        if(visited[i]!=true){
            dfs(i,adj,visited,topologSort);
        }
    }   

    for(int i=topologSort.size()-1;i>=0;i--)
        cout << topologSort[i] << " "; 



       
}

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct NodeHelper{
    bool visited;
    int start;
    int finish;
};

void dfs(int node ,vector<int> *adj , vector<NodeHelper>& helper , bool& flag,int& counter){
    helper[node].visited = true;
    helper[node].start = ++counter;
    for(int i=0;i< adj[node].size();i++){
        int child = adj[node][i];
        if(helper[child].start>0 && helper[child].finish == 0){
            flag=true;
            return;
        }
            
        if(helper[child].visited != true)
            dfs(child,adj,helper,flag,counter);
    }
    helper[node].finish = ++counter;
}




int main(){
    int v,e;
    cin >> v >> e;
    vector<int> adj[v+1];
   
    for(int i=0;i<e;i++){
        int from,to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    
    vector<NodeHelper> helper(v+1); 
    for(int i=1;i<=v;i++){
        helper[i].visited = false;
        helper[i].finish=0;
        helper[i].start=0;
    }

    int counter = 0;
    bool flag = false;

    for(int i=1;i<=v;i++){
        if(helper[i].visited!=true){
            dfs(i,adj,helper,flag,counter);
        }
    }

    cout << flag;

       
}

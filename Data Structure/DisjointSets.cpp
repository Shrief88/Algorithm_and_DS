#include<iostream>
#include <bits/stdc++.h>


using namespace std;

#define MAX 1000

class DisjointSet{
    private:
        int parent[MAX];
        int rank[MAX];

    public:

    void makeSet(int i){
        parent[i] = i;
        rank[i] = 0;
    }

    int find(int i){
        if(parent[i] == i)
            return i;

        return parent[i] =  find(parent[i]);    
    }

    void Union(int i,int j){
        int i_ID = find(i);
        int j_ID = find(j);   

        if(i_ID == j_ID)
            return;

        if(rank[i_ID]<rank[j_ID]){
            parent[i_ID] = j_ID;
        }else if(rank[i_ID]>rank[j_ID]){
            parent[j_ID] = i_ID;
        }else{
            parent[i_ID] = j_ID;
            rank[j_ID]++;
        }  
    }
};


int main(){
    DisjointSet s;
    s.makeSet(1);
    s.makeSet(2);
    s.makeSet(3);
    s.makeSet(4);
    s.makeSet(5);
    s.makeSet(6);
    s.Union(2,4);
    s.Union(5,2);
    s.Union(3,1);
    s.Union(2,3);
    s.Union(2,6);
}
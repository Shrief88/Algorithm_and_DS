#include<iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> computePrefix(string p){
  vector<int> prefixes(p.length());
  for(int i=1,k=0 ; i<p.length(); i++){
    while (k>0 && p[i] != p[k])
      k = prefixes[k-1];
    
    if(p[i] == p[k])
      prefixes[i] = ++k;
    else
      prefixes[i] = 0;
  }
  return prefixes;
}

vector<int> kmp(string t, string p){
  vector<int> match_index;
  vector<int> prefixes = computePrefix(p);
  for(int i=0,k=0;i<t.length();i++){
    while (k>0 && t[i] != p[k])
      k = prefixes[k-1];

    if(p[k] == t[i])
      k++;
    
    if(k == p.length()){
      match_index.push_back(i-p.length()+1);
      k = prefixes[k-1];
    } 
  }

  return match_index;
}

int main(){
  string t,p;
  cin >> p >> t;
  vector<int> vec = kmp(t,p);
  for(int i=0;i<vec.size();i++)
    cout << vec[i] << " ";

  
}
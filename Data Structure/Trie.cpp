#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Trie{
  private:
    bool isleaf;
    unordered_map<int,Trie*> child;

  public: 
    Trie();
    void insert(string s,int index);
    bool wordExist(string s, int index);
    bool prefixExist(string s, int index);
};

Trie::Trie(){
  isleaf = false;
}

void Trie::insert(string s, int index = 0){
  if(index == s.length())
    this->isleaf = true;
  else{
    int cur = s[index] - 'a';
    if(this->child.find(cur) == this->child.end())
      child[cur] = new Trie();
    child[cur]->insert(s,index+1);
  }
}

bool Trie::wordExist(string s, int index = 0){
  if(index == s.length())
    return isleaf;
  else{
    int cur = s[index] - 'a';
    if(this->child.find(cur) == this->child.end())
      return false;
    
    return child[cur]->wordExist(s,index+1);
  }  
}

bool Trie::prefixExist(string s, int index = 0){
  if(index == s.length())
    return true;
  else{
    int cur = s[index] - 'a';
    if(this->child.find(cur) == this->child.end())
      return false;
    
    return child[cur]->prefixExist(s,index+1);
  }  
}




int main(){
  Trie t;
  t.insert("the");
  t.insert("a");
  t.insert("there");
  cout << t.wordExist("tho");
}
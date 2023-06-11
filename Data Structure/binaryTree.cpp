#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
  int value;
  Node* right;
  Node* left;
  Node(int value){
    this->value = value;
    this->right = NULL;
    this->left = NULL;
  }
};

class BinaryTree{
  private:
    Node* root;
    void inOrder(Node* treeNode);
    void preOrder(Node* treeNode);
    void postOrder(Node* treeNode);
    int getHeight(Node* treeNode);
    void clear(Node* treeNode);
    bool find(int value,Node* treeNode);

  public: 
    BinaryTree(Node* root);
    ~BinaryTree(){clear(root);};
    void addEdge(Node* parent , Node* child, char direction);
    void inOrder(){inOrder(root);};
    void preOrder(){preOrder(root);};
    void postOrder(){postOrder(root);};
    void levelOrder();
    int getHeight(){return getHeight(root);};
    bool find(int value){return find(value,root);};

};

BinaryTree::BinaryTree(Node* root){
  this->root = root;
}

void BinaryTree::addEdge(Node* parent , Node* child, char direction){
  assert(direction == 'l' || direction == 'r');
  if(direction == 'l'){
    assert(parent->left == nullptr);
    parent->left = child;
  }else{
    assert(parent->right == nullptr);
    parent->right = child;
  }
}

void BinaryTree::clear(Node* treeNode){
  if(!treeNode)
    return;
  
  clear(treeNode->left);
  clear(treeNode->right);
  delete treeNode;
  treeNode = nullptr;
}

int BinaryTree::getHeight(Node* treeNode){
  if(!treeNode)
    return 0;

  return 1+max(getHeight(treeNode->left),getHeight(treeNode->right));
  
}

void BinaryTree::inOrder(Node* treeNode){
  if(!treeNode)
    return;

  inOrder(treeNode->left);
  cout << treeNode->value << " ";
  inOrder(treeNode->right);
}

void BinaryTree::preOrder(Node* treeNode){
  if(!treeNode)
    return;

  cout << treeNode->value << " ";
  inOrder(treeNode->left);
  inOrder(treeNode->right);
}

void BinaryTree::postOrder(Node* treeNode){
  if(!treeNode)
    return;

  inOrder(treeNode->left);
  inOrder(treeNode->right);
  cout << treeNode->value << " ";
}

void BinaryTree::levelOrder(){
  queue<Node* > q;
  vector<int> res;
  q.push(root);
  while(!q.empty()){
    res.push_back(q.front()->value);
    if(q.front()->left)
      q.push(q.front()->left);
    
    if(q.front()->right)
      q.push(q.front()->right);
    
    q.pop();
  }

  for(int i=0;i<res.size();i++){
    cout << res[i] << " ";
  }
  cout << endl;
}

bool BinaryTree::find(int value,Node* treeNode){
  bool res = treeNode->value == value ? true : false;

  if(!res && treeNode->left)
    res = find(value,treeNode->left);

  if(!res && treeNode->right)
    res = find(value,treeNode->right);

  return res;
}

int main(){
  Node* n1 = new Node(1);
  BinaryTree bt(n1);
  
  Node* n2 = new Node(2);
  bt.addEdge(n1,n2,'l');

  Node* n3 = new Node(3);
  bt.addEdge(n1,n3,'r');

  Node* n4 = new Node(4);
  bt.addEdge(n2,n4,'l');

  Node* n5 = new Node(5);
  bt.addEdge(n4,n5,'l');

  cout << bt.find(10);

}
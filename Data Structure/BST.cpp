#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
   
    public:
        int value;
        Node* right;
        Node* left;
        Node(int value){
            this->value = value;
            this->right = NULL;
            this->left = NULL;
        }
};

class BinarySearchTree{
    Node* root;
    void insert(Node* treeNode,int value);
    Node* find(Node* treeNode,int value);
    int height(Node* treeNode);
    bool isBalance(Node* treeNode);
    void inOrder(Node* treeNode);
    void preOrder(Node* treeNode);
    void postOrder(Node* treeNode);
    vector<int> levelOrder(Node* treeNode);


    public:
        BinarySearchTree();
        void insert(int value){insert(root,value);};
        Node* find(int value){return find(root,value);};
        int height(){return height(root);};
        bool isBalance(){ return isBalance(root);};
        void inOrder(){inOrder(root);};
        void preOrder(){preOrder(root);};
        void postOrder(){postOrder(root);};
        vector<int> levelOrder(){return levelOrder(root);};
};

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

void BinarySearchTree::insert(Node* treeNode,int value){
    if(!treeNode){
        Node* ptr = new Node(value);
        root = ptr;
    }
    else{
        if(value>treeNode->value){
            if(!treeNode->right){
                Node* ptr = new Node(value);
                treeNode->right = ptr;
            }else
                insert(treeNode->right,value);
        }else{
            if(!treeNode->left){
                Node* ptr = new Node(value);
                treeNode->left = ptr;
            }else
                insert(treeNode->left,value);
        }
    }   
}

Node* BinarySearchTree::find(Node* treeNode,int value){
    if(!treeNode)
        return NULL;

    if(value == treeNode->value)
        return treeNode;

    if(value > treeNode->value)
        return find(treeNode->right,value); 
    else
        return find(treeNode->left,value);     
}

int BinarySearchTree::height(Node* treeNode){
    if(!treeNode)
        return 0;

    return 1+ max(height(treeNode->right),height(treeNode->left));    
}

bool BinarySearchTree::isBalance(Node* treeNode){
    if(!treeNode)
        return false;

    return (abs(height(treeNode->left)-height(treeNode->right)) > 1) ? false : true;
}

void BinarySearchTree::inOrder(Node* treeNode){
    if(!treeNode)
        return;

    inOrder(treeNode->left);
    cout << treeNode->value << " ";
    inOrder(treeNode->right);
}

void BinarySearchTree::preOrder(Node* treeNode){
    if(!treeNode)
        return;

    cout << treeNode->value << " ";
    preOrder(treeNode->left);
    preOrder(treeNode->right);
}

void BinarySearchTree::postOrder(Node* treeNode){
    if(!treeNode)
        return;

    preOrder(treeNode->left);
    preOrder(treeNode->right);
    cout << treeNode->value << " ";
}

vector<int> BinarySearchTree::levelOrder(Node* treeNode){
    vector<int> res;
    queue<Node*> helper;
    helper.push(treeNode);

    while(!helper.empty()){
        res.push_back(helper.front()->value);
        if(helper.front()->left)
            helper.push(helper.front()->left);

        if(helper.front()->right)
            helper.push(helper.front()->right); 

        helper.pop();      
    }

    return res;
}



int main(){
    BinarySearchTree bst;
    bst.insert(6);
    bst.insert(8);
    bst.insert(2);
    bst.insert(1);
    bst.insert(0);
    vector<int> res = bst.levelOrder();
    for(int i=0;i<res.size();i++)
        cout << res[i];
}



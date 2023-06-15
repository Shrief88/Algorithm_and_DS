#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node* right;
        Node* left;
        int height;
        Node(int value){
            this->value = value;
            this->right = NULL;
            this->left = NULL;
            this->height = 1;
        }
};

class BinarySearchTree{
    private:
        Node* root;
        Node* insert(Node* treeNode,int value);
        Node* find(Node* treeNode,int value);
        int height(Node* treeNode);
        bool isBalance(Node* treeNode);
        void inOrder(Node* treeNode);
        void preOrder(Node* treeNode);
        void postOrder(Node* treeNode);
        vector<int> levelOrder(Node* treeNode);
        void clear(Node* treeNode);
        Node* getMax(Node* treeNode);
        Node* getMin(Node* treeNode);
        bool findAncestors(int value,vector<Node*> &ancestors,Node* treeNode);
        Node* deleteNode(int value,Node* treeNode);
        int getBalanceFactor(Node* treeNode);
        Node* rightRotation(Node* q);
        Node* leftRotation(Node* q);
        Node* Balance(Node* treeNode);
        Node* getSuccessor(int value);
        Node* getPredecesor(int value);
        bool findAncestors(int value,vector<Node*> &ancestors){return findAncestors(value,ancestors,root);};

    public:
        BinarySearchTree();
        ~BinarySearchTree(){clear(root);};
        void insert(int value){root = insert(root,value);};
        Node* find(int value){return find(root,value);};
        int height(){return height(root);};
        bool isBalance(){ return isBalance(root);};
        void inOrder(){inOrder(root);};
        void preOrder(){preOrder(root);};
        void postOrder(){postOrder(root);};
        vector<int> levelOrder(){return levelOrder(root);};
        Node* getMax(){return getMax(root);};
        Node* getMin(){return getMin(root);};
        void deleteNode(int value){root = deleteNode(value,root);};
};

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

void BinarySearchTree::clear(Node* treeNode){
  if(!treeNode)
    return;
  
  clear(treeNode->left);
  clear(treeNode->right);
  delete treeNode;
  treeNode = nullptr;
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

int BinarySearchTree::getBalanceFactor(Node* treeNode){
    return height(treeNode->left) - height(treeNode->right);
}

Node* BinarySearchTree::rightRotation(Node* Q){
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    Q->height = height(Q);
    P->height = height(P);
    return P;
}

Node* BinarySearchTree::leftRotation(Node* P){
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    Q->height = height(Q);
    P->height = height(P);
    return Q;   
}

Node* BinarySearchTree::Balance(Node* treeNode){
    int balanceFactor = getBalanceFactor(treeNode);
   
    if(balanceFactor == 2){
        int leftBalanceFactor = getBalanceFactor(treeNode->left);
        if(leftBalanceFactor == -1)
            treeNode->left = leftRotation(treeNode->left);
        return rightRotation(treeNode);
    }
        
    else if(balanceFactor == -2){
        int rightBalanceFactor = getBalanceFactor(treeNode->right);
        if(rightBalanceFactor == 1)
            treeNode->right = rightRotation(treeNode->right);
        return leftRotation(treeNode);
    }

    return treeNode;
}

Node* BinarySearchTree::insert(Node* treeNode,int value){
    if(!treeNode){
        Node* newNode = new Node(value);  
        return newNode;
    }
    else{
        if(value>treeNode->value)
            treeNode->right = insert(treeNode->right,value);
        else if(value < treeNode->value)
            treeNode->left = insert(treeNode->left,value);
        else 
            return treeNode;
    }

    treeNode->height = height(treeNode);

    return Balance(treeNode);
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

Node* BinarySearchTree::getMax(Node* treeNode){
    Node* ptr = treeNode;
    while(ptr->right != nullptr)
        ptr = ptr->right;
    
    return ptr;
}

Node* BinarySearchTree::getMin(Node* treeNode){
    Node* ptr = treeNode;
    while(ptr->left != nullptr)
        ptr = ptr->left;
    
    return ptr;
}

bool BinarySearchTree::findAncestors(int value ,vector<Node*> &ancestors,Node* treeNode){
    if(!treeNode)
        return NULL;

    if(value == treeNode->value)
        return treeNode;

    ancestors.push_back(treeNode);

    if(value > treeNode->value)
        return findAncestors(value,ancestors,treeNode->right); 
    else
        return findAncestors(value,ancestors,treeNode->left); 
}

Node* BinarySearchTree::getSuccessor(int value){
    Node* tmp = find(value);
    if(tmp){
        if(tmp->right){
            return getMin(tmp->right);
        }else{
            vector<Node*> ancestors;
            findAncestors(value,ancestors);
            if(ancestors.size() > 0){
                Node* next = ancestors[ancestors.size()-1];
                for(int i= ancestors.size()-2 ; i>=0 ; i--)
                    if(ancestors[i]->value > value){
                        next = ancestors[i];
                        break;
                    }
                return next;
            }else{
                return nullptr;
            }
        }
    }else{
        return nullptr;
    }
}

Node* BinarySearchTree::getPredecesor(int value){
    Node* tmp = find(value);
    if(tmp){
        if(tmp->left){
            return getMax(tmp->left);
        }else{
            vector<Node*> ancestors;
            findAncestors(value,ancestors);
            if(ancestors.size() > 0){
                Node* previous = ancestors[ancestors.size()-1];
                for(int i= ancestors.size()-2 ; i>=0 ; i--)
                    if(ancestors[i]->value < value){
                        previous = ancestors[i];
                        break;
                    }
                return previous;
            }else{
                return nullptr;
            }
        }
    }else{
        return nullptr;
    }
}


Node* BinarySearchTree::deleteNode(int value,Node* treeNode){
    if(treeNode == nullptr)
        return treeNode;

    if(value < treeNode->value){
        treeNode->left = deleteNode(value,treeNode->left);
    }else if(value > treeNode->value){
        treeNode->right = deleteNode(value,treeNode->right);
    }else{
        Node* tmp = treeNode;
        //case 1 : No children
        if(!treeNode->left && !treeNode->right) 
            treeNode = nullptr;

        //case 2 : just one child
        else if(!treeNode->right)
            treeNode = treeNode->left;
        else if(!treeNode->left)
            treeNode = treeNode->right;
        else{
            // case 3: two children 
            Node* successor = getSuccessor(value);
            treeNode->value = successor->value;
            treeNode->right = deleteNode(successor->value,treeNode->right);
            tmp = nullptr;
        }

        if(tmp)
            delete tmp;   
    }

    if(treeNode){
        treeNode->height = height(treeNode);
        treeNode = Balance(treeNode);
    }

    return treeNode;
}


int main(){
    BinarySearchTree bst;
    bst.insert(9);
    bst.insert(6);
    bst.insert(14);
    bst.insert(13);
    bst.insert(32);
    bst.insert(7);
    bst.insert(10);
   
    bst.deleteNode(6);
    bst.deleteNode(14);
    bst.deleteNode(32);
    bst.deleteNode(9);
    cout << bst.isBalance();
}



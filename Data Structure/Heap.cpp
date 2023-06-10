#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Heap{
    private:
        vector<int> vec;
        int size;
        int cap = 1000;
        void siftUp(int i);
        void siftDown(int i);
        int getParent(int i);
        int getLeftChild(int i);
        int getRightChild(int i);

    public:
        Heap();
        void buildHeap(vector<int> &vec);
        int getMax();
        void insert(int value);
        int extractMax();
        void remove(int i);
        void heapSort(vector<int> &vec);
        
};

Heap::Heap(){
    size=0;
    vec.resize(cap);
}

void Heap::buildHeap(vector<int> &vec){
    this->vec = vec;
    this->size = vec.size();
    for(int i=vec.size()/2;i>=0;i--){
        siftDown(i);
    }
}

int Heap::getMax(){
    return vec[0];
}

int Heap::getParent(int i){
    return (i-1)/2;
}

int Heap::getLeftChild(int i){
    return (2*i)+1;
}

int Heap::getRightChild(int i){
    return (2*i)+2;
}

void Heap::siftUp(int i){
    if(i == 0)
        return;
        
    int parent = getParent(i);
    if(vec[i] > vec[parent]){
        swap(vec[i],vec[parent]);
        siftUp(parent);
    }
}

void Heap::siftDown(int i){
    int leftChild = getLeftChild(i);
    int rightChild = getRightChild(i);

    if(leftChild>size-1 && rightChild>size-1)
        return;
    
    int child = leftChild;
    if(rightChild<=size-1){
        child = vec[rightChild] > vec[leftChild] ? rightChild : leftChild ; 
    } 

    if(vec[child] > vec[i]){
        swap(vec[child],vec[i]);
        siftDown(child);
    }
}

void Heap::insert(int value){
    assert(size != cap);
    vec[size++] = value;
    siftUp(size-1);
}

int Heap::extractMax(){
    assert(size !=0);
    int max = vec[0];
    swap(vec[0],vec[size-1]);
    size--;
    siftDown(0);
    return max;
}

void Heap::remove(int i){
    vec[i] = INT_MAX;
    siftUp(i);
    extractMax();
}

void Heap::heapSort(vector<int> &vec){
    buildHeap(vec);
    for(int i=vec.size()-1;i>=0 ; i--)
        vec[i] = extractMax();
}




int main(){
   vector<int> vec = {3,8,5,10,12,14,1};
   Heap h;

   h.heapSort(vec);

   for(int i=0;i<vec.size();i++){
     cout << vec[i] << " ";
   }   
  
}


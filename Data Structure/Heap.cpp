#include<iostream>
#include <bits/stdc++.h>


using namespace std;

#define MAX 1000

class Heap{
    private:
        int a[MAX];
        int size;

    public:
        Heap(){
            size=0;
        }

        int parent(int i){
            return i%2 == 0 ? (i/2)-1 : i/2;
        }

        int leftChild(int i){
            return (2*i)+1;
        }

        int rightChild(int i){
            return (2*i)+2;
        }

        void siftUp(int i){
            while ( a[i] > a[parent(i)] && i>0) {
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }

        void siftDown(int i){
            if(leftChild(i)>size-1 && rightChild(i)>size-1)
                return;

            int max = leftChild(i);
            if(rightChild(i)<=size-1){
                if(a[rightChild(i)]>a[max]){
                    max = rightChild(i);
                }
            } 

            if(a[i]<a[max]){
                swap(a[i],a[max]);
                siftDown(max);
            }else{
                return;
            }   
        }

        void insert(int number){
            size++;
            a[size-1]= number;
            siftUp(size-1);
        }


        int extractMax(){
            int result = a[0];
            swap(a[0],a[size-1]);
            size--;
            siftDown(0);
            return result;
        }

        void remove(int i){
            a[i] = INT_MAX;
            siftUp(i);
            extractMax();
        }
};


int main(){
  
}
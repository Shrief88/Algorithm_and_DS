#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Vector{
    private:
        int *arr = nullptr;
        int size = 0;
        int cap;

    public:
        Vector(int size): size(size){
            if(size < 0)
                size = 1;

            cap = size + 10;    
            arr = new int[cap]; 

        }

        ~Vector(){
            delete[] arr;
            arr = nullptr;
        }

        int get(int index){
            return arr[index];
        }

        void set(int index,int value){
            arr[index] = value;
        }

        void print(){
            for(int i=0;i<size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        int find(int value){
            for(int i=0;i<size;i++){
                if(arr[i]== value)
                    return i;
            }
            return -1;
        }

        int getFront(){
            return arr[0];
        }

        int getBack(){
            return arr[size-1];
        }

        void expand_cap(){
            cap *= 2;
            int *newArr = new int[cap];
            for(int i=0;i<size;i++)
                newArr[i] = arr[i];
            
            swap (arr,newArr);
            delete newArr;
        }

        void push_back(int value){
            if(size == cap)
                expand_cap();
           
           arr[size++] = value;
        }

        void insert(int value, int index){
            if(size == cap)
                expand_cap();

            for(int i=size;i>index;i--)
                arr[i] = arr[i-1]; 

            size++;
            arr[index]= value;       
        }

        void leftRotation(){
            int tmp = arr[0];
            for(int i=0;i<size-1;i++)
                arr[i] = arr[i+1];

            arr[size-1] = tmp;    
        }

        void rightRotation(){
            int tmp = arr[size-1];
            for(int i=size-1;i>0;i--)
                arr[i]= arr[i-1];

            arr[0] = tmp;    
        }

        void rightRotation(int steps){
            steps = steps%size;

            for(int i=0;i<steps;i++)
                rightRotation();
        }

        int pop(int index){
            int tmp = arr[index];
            for(int i=index;i<size;i++){
                arr[i] = arr[i+1]; 
            }
            size--;
            return tmp;
        }

        int find_transposition(int value){
            for(int i=0;i<size;i++){
                if(arr[i] == value){
                    if(i != 0){
                        swap(arr[i],arr[i-1]);
                        return i-1;
                    }
                    return 0;
                }
            }
        }
};

int main(){
    Vector v(5);
    for(int i=0;i<10;i++)
        v.set(i,i);

    v.print();
    v.rightRotation(2);
    v.print();

    
}
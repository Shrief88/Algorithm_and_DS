#include<iostream>
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

class Vector{
    private:
        int *arr = nullptr;
        int size;
        int cap;
        void expand_cap();
        bool isFull();

    public:
        Vector(int size);
        Vector();
        ~Vector();
        void push_back(int value);
        int get(int index);
        void set(int index,int value);
        void insert(int index,int value);
        void print();
        void pop(int index);
        int getSize();
};

Vector::Vector(int size){
    if(size < 0)
        this->size = 0;
    
    this->size = 0;
    cap = size + 10;    
    arr = new int[cap]; 
}

Vector::Vector(){
    size = 0;
    cap = size + 10;    
    arr = new int[cap]; 
}


Vector::~Vector(){
    delete[] arr;
    arr = nullptr;
}

void Vector::expand_cap(){
    cap*=2;
    int *newArr = new int[cap];
    for(int i=0;i<size; i++){
        newArr[i] = arr[i];
    }

    swap(arr,newArr);
    delete[] newArr;
}

bool Vector::isFull(){
    return size == cap ? true : false;
}

void Vector::push_back(int value){
    if(isFull())
        expand_cap();
    arr[size++] =  value;
}

int Vector::get(int index){
    assert(index<size && index>=0);
    return arr[index];
}

void Vector::insert(int index,int value){
    if(isFull())
        expand_cap();
    
    for(int i=size+1 ; i>index ; i--)
        arr[i] = arr[i-1];

    arr[index] = value;
    size++;
}

void Vector::set(int index,int value){
    assert(index<size && index>=0);
    arr[index] = value;
}

void Vector::print(){
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Vector::pop(int index){
    assert(index<size && index>=0);
    for(int i=index ; i<size-1 ; i++)
        arr[i] = arr[i+1];

    size--;
}

int Vector::getSize(){
    return size;
}



int main(){
    Vector v(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);
    v.push_back(10);
    cout << v.get(4);
    
    
}
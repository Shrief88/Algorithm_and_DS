#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack{
    private:
        int *arr;
        int size;
        int cap;

    public:
        Stack();
        Stack(int size);
        bool isFull();
        bool isEmpty();
        void push(int value);
        void pop();
        int getTop();
        int getSize();
        void display();
};

Stack::Stack(){
    cap = 1000;
    size = 0;
    arr = new int[cap];
}

Stack::Stack(int size){
    assert(size > 0);
    this->size = 0;
    this->cap = size;
    arr = new int[cap];
}

bool Stack::isFull(){
    return size == cap ? true : false;
}

bool Stack::isEmpty(){
    return size == 0 ? true : false;
}

void Stack::push(int value){
   
    assert(!isFull());
    arr[size++] = value;
}

void Stack::pop(){
    assert(!isEmpty());
    size--;
}

int Stack::getTop(){
    return arr[size-1];
}

int Stack::getSize(){
    return size;
}

void Stack::display(){
    for(int i = size-1;i>=0;i--)
        cout << arr[i] << " ";
    cout << endl;
}

   
int main(){
    Stack s;
    s.push(5);
    s.push(4);
    s.display();
    s.pop();
    s.display();

}
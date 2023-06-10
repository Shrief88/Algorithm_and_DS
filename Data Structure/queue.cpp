#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *arr;
        int cap;

    public:
        Queue();
        Queue(int size);
        ~Queue();
        bool isEmpty();
        bool isFull();
        int getSize();
        void enqueue(int value);
        void dequeue();
        int getFront();
        void display();
};

Queue::Queue(){
    cap = 1000;
    arr = new int[1000];
    rear = 0;
    front = 0;
    size = 0;
}

Queue::Queue(int size){
    cap = size;
    arr = new int[cap];
    rear = 0;
    front = 0;
    this->size = 0;
}

Queue::~Queue(){
    delete[] arr;
    arr = nullptr;
}

bool Queue::isEmpty(){
    return size == 0 ? true : false;
}

bool Queue::isFull(){
    return size == cap ? true : false;
}

int Queue::getSize(){
    return size;
}

void Queue::enqueue(int value){
    assert(!isFull());
    if(rear == cap)
        rear = 0;

    arr[rear++] = value;
    size++;
}

void Queue::dequeue(){
    assert(!isEmpty());
    if(front == cap-1)
        front = -1;
    
    front++;
    size--;
}

int Queue::getFront(){
    assert(!isEmpty());
    return arr[front];
}

void Queue::display(){
    if(rear>front){
        for(int i=front;i<rear;i++)
            cout << arr[i] << " ";
    }else if(front >= rear){
        for(int i=front;i<cap;i++)
            cout << arr[i] << " ";

        for(int i=0;i<rear;i++)
            cout << arr[i] << " ";    
    }
    cout << endl;
}


int main(){
    Queue q(3);
    q.enqueue(4);
    q.enqueue(2);
    q.display();
    q.enqueue(1);
    q.dequeue();
    q.display();
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    cout << q.getFront();
   

}
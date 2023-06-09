#include<iostream>
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) : data(data){};
};

class LinkedList{
    private:
        Node* head;
        int size;
        Node* getTail();

    public:
        LinkedList();
        ~LinkedList();
        void print();
        void insert(int value);
        void insertFront(int value);
        void deleteFront();
        void pop();
        int getSize();
};

LinkedList::LinkedList(){
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList(){
    while(head != nullptr){
        Node* next = head->next;
        delete head;
        head = next;
    }
    size = 0;
}

void LinkedList::print(){
    Node* tmp = head;
    while (tmp != nullptr){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

Node* LinkedList::getTail(){
    Node* tmp = head;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    return tmp;
}

void LinkedList::insert(int value){
    Node* newNode = new Node(value);
    if(head == nullptr)
        head = newNode;
    else{
        Node* tail = getTail();
        tail->next = newNode;
    }
    size++;
}

void LinkedList::insertFront(int value){
    Node* newNode = new Node(value);
    if(head == nullptr)
        head = newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void LinkedList::deleteFront(){
    assert(head != nullptr);
    Node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
    size--;
}

void LinkedList::pop(){
    assert(size != 0);
    if(size == 1){
        delete head;
        head = nullptr;
    }else{
        Node* tmp = head;
        while (tmp->next->next != nullptr)
            tmp = tmp->next;

        delete tmp->next;
        tmp->next = nullptr;
        tmp = nullptr;
    }
    size--;
}

int LinkedList::getSize(){
    return size;
}

int main(){
    LinkedList ll;
    ll.insert(3);
    ll.pop();
    ll.insert(2);
    ll.print();
    ll.insert(5);
    ll.insert(4);
    ll.print();
    ll.pop();
    ll.print();
    ll.deleteFront();
    ll.print();
}




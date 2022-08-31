#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) : data(data){};
};

class LinkedList{
    private:
        Node* head;
        int length;

    public:
        LinkedList(){
            head = nullptr;
            length = 0;
        }

        void print(){
            Node* tmp = head;
            while (tmp != nullptr){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }

        Node* getTail(){
            Node* tmp = head;
            while (tmp->next != nullptr){
                tmp = tmp->next;
            }
            return tmp;
        }

        void insert(int value){
            Node* node = new Node(value);
            if(head == nullptr)
                head = node;
            else{
                Node* tail = getTail();
                tail->next = node;
            } 
            length++;      
        }

        void insert_front(int value){
            Node* node = new Node(value);
            node->next = head;
            head = node;  
        }

        void delete_front(){
            if(head == nullptr)
                return;

            Node* node = head;
            head = head->next;
            delete node;
            length--;    
        }

        void delete_last(){
            if(length == 0)
                return;

            if(length == 1)
                head = nullptr;  
            else{
                Node* node = head;
                Node* previous = nullptr;
                while (node->next != nullptr){
                    previous = node;
                    node = node->next;
                }
                delete node;
                previous->next = nullptr;
            }
            length--;
        }

        void delete_index(int index){
            if(index == 1)
                delete_front();
            else{
                Node* node = head;
                Node* previous = nullptr;
                for(int i=1;i<index;i++){
                    previous = node;
                    node = node->next;
                }

                previous->next = node->next;
                delete node;
            }
            length--;
        }

        void deleteKey(int value){
            int index = find(value);
            delete_index(index);
        }

        int get_ntn(int index){
            if(index>length || index<0)
                return -1;

            Node* tmp = head;
            for(int i=1;i<index;i++){
                tmp = tmp->next;
            }
            return tmp->data;
        }

        int get_ntn_back(int index){
            index = length - index + 1;
            return get_ntn(index);
        }

        int find(int value){
            Node* tmp = head;
            int index = 1;
            while (tmp != nullptr){
                if(tmp->data == value)
                    return index;

                index++;
                tmp = tmp->next;    
            }
            return -1;
        }  

        int improved_search(int value){
            Node* tmp = head;
            Node* previous = nullptr;
            int index = 1;
            while (tmp != nullptr){
                if(tmp->data == value){
                    if(!previous)
                        return index;
                    
                    tmp->data = previous->data;
                    previous->data = value;
                    return --index;
                }
                previous = tmp;
                index++;
                tmp = tmp->next;    
            }
            return -1;
        } 

        void reverse(){
            Node* cur = head;
            Node* prev = nullptr;
            while (cur != nullptr){
                Node* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
        } 
};





int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);

    
    ll.print();
    ll.reverse();
    ll.print();
    

    
    


}




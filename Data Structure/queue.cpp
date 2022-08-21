#include<iostream>


using namespace std;

#define MAX 1000

class Queue{
    private:
        int front;
        int rear;
        int size;
        int a[MAX];
    public:
        Queue(){
            size =0;
            rear = -1;
            front = 0;
        }

        bool isEmpty(){
            return size == 0 ? true : false;
        }

        bool isFull(){
            return size == MAX ? true : false;
        }

        int getSize(){
            return size;
        }

        void enqueue(int n){
            if(isFull()){
                cout << "Queue is Full";
                return;
            }else{
                if(rear == MAX-1)
                    rear =-1;

                a[++rear] = n;
                size++;
            }
        }

        void dequeue(){
            if(isEmpty()){
                 cout << "Queue is Empty";
                return;
            }else{
                if(front=MAX-1){
                    front = -1;
                }
                front++;
                size--;
            }
        }

        int getFront(){
            if(isEmpty()){
                cout << "Queue is Empty";
                return 0;
            }else{
                return a[front];
            }
        }

        void display(){
            if(rear>front){
                for(int i=front;i<=rear;i++)
                    cout << a[i] << " ";
            }else if(front>rear){
                for(int i=front;i<MAX;i++)
                    cout << a[i] << " ";

                for(int i=0;i<=rear;i++)
                    cout << a[i] << " ";    
            }
        }
};

int main(){
   

}
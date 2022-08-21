#include<iostream>


using namespace std;

#define MAX 1000

class Stack{
    private:
        int top;
        int a[MAX];
        int size;
    public:
        Stack(){
            top =  0; 
            size = 0;
        }

        bool isStackFull(){
            if (top>MAX-1)
                return true;
            else
                return false;    
        }

        bool isStackEmpty(){
            if(top == 0)
                return true;
            else
                return false;    
        }

        void push(int number){
            if(isStackFull()){
                cout << "Stack OverFlow";
                return;
            }
            a[top++] = number;
            size++;
        }

        void pop(){
            if(isStackEmpty()){
               cout << "Stack is Empty";
               return; 
            }
            top--;
            size--;
        }

        int gettop(){
            if(isStackEmpty()){
               cout << "Stack is Empty";
               return 0; 
            }
            return a[top-1];
        } 

        int getSize(){
            return size;
        }

        void display(){
            for(int i =top-1;i>=0;i--)
                cout << a[i] << " ";
        }
};
   
int main(){
 
}
#include <iostream>
#include <vector>

using namespace std;

/*
  Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.
  In the first iteration we move largest element to end , In the second iteration we move second largest element to end and so on.
  Complexities: 
  Worst case : O(n^2)
  Best case : O(n)
  Average case : O(n^2)
  Space Complexity : O(1)
*/

void iterativeSort(vector<int> &vec){
  for(int i=0;i<vec.size(); i++){
    int ptr1 = 0;
    int ptr2 = 1;
    bool swaped = false;

    while (ptr2 < vec.size() - i){
      if(vec[ptr2]<vec[ptr1]){
        swap(vec[ptr1],vec[ptr2]);
        swaped = true;
      }  
      ptr1++;
      ptr2++;
    }

    if(!swaped)
      break;
  }
}

void recursiveSort(vector<int> &vec,int size){
  if(size == 1)
    return;

  int ptr1 = 0;
  int ptr2 = 1;
  bool swaped = false;

  while (ptr2 < size){
    if(vec[ptr2]<vec[ptr1]){
      swap(vec[ptr1],vec[ptr2]);
      swaped = true;
    }
    ptr1++;
    ptr2++;
  }

  if(!swaped)
    return;

  recursiveSort(vec,size-1); 
     
}


void bubbleSort(vector<int> &vec){
  // iterativeSort(vec);
  recursiveSort(vec,vec.size());
}

int main(){
  vector<int> vec = {9,2,10,0,100,5,3,90,85};
  bubbleSort(vec);
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << " ";
  }
}
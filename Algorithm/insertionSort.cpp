#include <iostream>
#include <vector>

using namespace std;

/* 
  the goal of algorthim is to find the right place of the element
  at n=1, the intial subarray is already sorted. 
  then from n=2 to the end of the array we search linearly to find the correct position for the element n, 
  this means after every step, the extended subarray is sorted.
  Insertion sort is adaptive, stable, in-place, online algorthim.   
*/

void recursiveSort(vector<int> &vec,int size){
  if(size == 1){
    return;
  }

  recursiveSort(vec,size-1);

  int key = vec[size-1];
  int j = size-2;
  while(j >= 0 && vec[j]>key){
    vec[j+1] = vec[j];
    j--;
  }  
  vec[j+1] = key;
}

void iterativeSort(vector<int> &vec){
  for(int i=1;i<vec.size();i++){
    int key = vec[i];
    int j = i-1;
    while(j >= 0 && vec[j]>key){
      vec[j+1] = vec[j];
      j--;
    }  
    vec[j+1] = key;
  }
}


void insertionSort(vector<int>& vec){
  recursiveSort(vec,vec.size());
  // iterativeSort(vec);
}


int main(){
  vector<int> vec = {9,2,10,0,5,3,90,85};
  insertionSort(vec);
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << " ";
  } 
}
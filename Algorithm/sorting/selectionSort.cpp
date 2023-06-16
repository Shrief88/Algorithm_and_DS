#include <iostream>
#include <vector>

using namespace std;

/*
  Selection sort is based on a simple observation: 
  the first element of a sorted array is the minimum of the whole array, and the second element is the second element of the whole array and so on.
  Complexities: 
  Worst case : O(n^2)
  Best case : O(n^2)
  Average case : O(n^2)
  Space Complexity : O(1)
*/

void selectionSort(vector<int> &vec){
  for(int i=0; i < vec.size();i++){
    int minPostion = i;
    for(int j=i+1;j<vec.size();j++)
      if(vec[j] < vec[minPostion])
        minPostion = j;

    swap(vec[i],vec[minPostion]);
  }
}

int main(){
  vector<int> vec = {9,2,10,0,5,3,90,85};
  selectionSort(vec);
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << " ";
  }
}
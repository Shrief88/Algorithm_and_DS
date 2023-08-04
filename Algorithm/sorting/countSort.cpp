#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

/*
  Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array.
  Complexities: 
  Worst case : O(n+m)
  Best case : O(n+m)
  Average case : O(n+m)
  Space Complexity : O(m)
  where m is the max value in the array 
*/

void countSort(vector<int> &vec){
  int max = vec[0];
  for(int i=1;i<vec.size(); i++){
    if(vec[i] > max)
      max = vec[i];
  }

  vector<int> countArray;
  countArray.resize(max+1);

  for(int i=0;i<vec.size();i++)
    countArray[vec[i]]++;

  for(int i=1;i<countArray.size();i++){
    countArray[i] += countArray[i-1];
  }  

  rotate(countArray.rbegin(),countArray.rbegin()+1,countArray.rend());
  
  vector<int> sortedArray(vec.size());

  for(int i=0;i<vec.size(); i++){
    sortedArray[countArray[vec[i]]] = vec[i];
    countArray[vec[i]]++;
  }

  for(int i=0;i<vec.size(); i++){
    vec[i] = sortedArray[i];
  }

}

int main(){
  vector<int> vec = {1, 4, 1, 2, 7, 5, 2};
  countSort(vec);
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << " ";
  }
}
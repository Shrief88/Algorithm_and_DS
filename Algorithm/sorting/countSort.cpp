#include <iostream>
#include <vector>

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

  for(int i=0,k=0;i<countArray.size();i++){
    if(countArray[i] > 0){
      for(int j=0;j<countArray[i]; j++,k++)
        vec[k] = i;
    }
  }  

}

int main(){
  vector<int> vec = {9,3,10,9,5,3,90,9};
  countSort(vec);
  for(int i=0;i<vec.size();i++){
    cout << vec[i] << " ";
  }
}
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums,int value){
  int start = 0;
  int end = nums.size()-1;
  while (end >= start){
    int middle = start + (end - start)/2;
    if(nums[middle] == value)
      return middle;
    else if(nums[middle] > value)
      end = middle-1;
    else if (nums[middle] < value)
      start = middle + 1;
  }
  return -1;
}

int main(){
  vector<int> nums = {1,4,5,10,30,80,100,115};
  int value;
  cin >> value;
  cout << binarySearch(nums,value) << endl;
}